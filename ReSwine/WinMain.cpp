#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "platform/platform.h"
#include "common/swineversion.h"
#include "core/logger.h"
#include "core/timer.h"
#include "game/defs.h"
#include "Globals.h"
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include "main2.h"


void SLogger::Log(int loglev, const char* message, ...)
{
    if (!Logging || loglev > LogLevel)
        return;

    char buf[512];
    char logLine[524];

    va_list args;
    va_start(args, message);
    vsnprintf_s(buf, sizeof(buf), message, args);
    va_end(args);

    if (loglev < 0)
        snprintf(logLine, sizeof(logLine), "%s\r\n", buf);
    else
        snprintf(logLine, sizeof(logLine), "<%d> %s\r\n", loglev, buf);

    if (LogBufferUsed < 512)
    {
        strcpy_s(LogBufferContent[LogBufferUsed], sizeof(LogBufferContent[LogBufferUsed]), logLine);
        LogBufferUsed++;
    }


    if (LogBufferUsed >= 512 || loglev <= 0)
        WriteBufferToLog();

    OutputDebugStringA(logLine);
}
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
    SString versionString = Version->GetLongString();

    // Build app name string
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

    // Platform + COM
    CoInitializeEx(nullptr, 0);
    g_Platform = new SPlatform();
    g_Platform->Initialize();

    // Run game main loop
    main2();

    // Cleanup
    if (g_Platform) {
        delete g_Platform;
        g_Platform = nullptr;
    }

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
