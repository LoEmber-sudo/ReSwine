#define _CRT_SECURE_NO_WARNINGS
#include "logger.h"
#include <cstdarg>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <cstring>

SLogger::SLogger(const char* fileName, const char* appname, int logLevel, bool logToFile)
{
    strcpy_s(LogFileName, fileName);
    strcpy_s(AppName, appname);
    LogLevel = logLevel;
    Logging = true;
    LogToFile = logToFile;
    LogBufferUsed = 0;
}

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
        strcpy_s(LogBufferContent[LogBufferUsed], logLine);
        LogBufferUsed++;
    }

    if (LogBufferUsed >= 512 || loglev <= 0)
        WriteBufferToLog();

    OutputDebugStringA(logLine);
}

void SLogger::WriteBufferToLog()
{
    if (!LogToFile)
        return;

    std::ofstream logFile(LogFileName, std::ios::app | std::ios::binary);
    if (!logFile.is_open())
        return;

    for (int i = 0; i < LogBufferUsed; ++i)
    {
        logFile.write(LogBufferContent[i], std::strlen(LogBufferContent[i]));
    }

    LogBufferUsed = 0;
    logFile.close();
}
