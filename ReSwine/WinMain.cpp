#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "platform/platform.h"
#include "common/version.h"
#include "core/logger.h"
#include "core/timer.h"
#include "game/defs.h"
#include "Globals.h"
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include "main2.h"
inline void _srand(unsigned int seed) {
    std::srand(seed);
}

using __time64_t = std::time_t;

inline __time64_t __time64(__time64_t*) {
    return std::time(nullptr);
}

inline __time64_t __time64(int) {
    return std::time(nullptr);
}

int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char* lpCmdLine, int nCmdShow)
{
    // Seed RNG
    __time64_t now = __time64(0);
    _srand(now);

    // Set working directory to exe root (strip "\bin\")
    wchar_t exe_path[MAX_PATH];
    GetModuleFileNameW(nullptr, exe_path, MAX_PATH);
    if (wchar_t* binPos = wcsstr(exe_path, L"\\bin\\")) {
        *binPos = L'\0';
        SetCurrentDirectoryW(exe_path);
    }

    // Version info
    Version = new SVersion();
    SString versionString{};
    versionString.buf = nullptr;
    versionString.size = 0;
    Version->GetLongString(&versionString);



    char appNameStr[1024];
    const char* appName = versionString.buf ? versionString.buf : fullpath;
    sprintf_s(appNameStr, sizeof(appNameStr), "Application name: %s game", appName);


    if (versionString.buf) {
        operator delete(versionString.buf, 1u);
    }

    // Logger
    Logger.g = new SLogger("swine journal", appNameStr, 1, 0);
    ((SLogger*)Logger.g)->Log(0, "Build type: FINAL");
    // Timer
    Timer = new STimer();


    CoInitializeEx(nullptr, 0);

    // Run game main loop
    main2();

    // Cleanup
    if (Timer) {
        delete Timer;
        Timer = nullptr;
    }

    if (Logger.g) {
        delete (SLogger*)Logger.g;
        Logger.g = nullptr;
    }

    CoUninitialize();
    return 0;
}
