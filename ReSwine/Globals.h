#pragma once
#include "game/SuperWindow.h"
#include "core/logger.h"
#include "core/timer.h"
#include "platform/platform.h"

// Global instances
extern SSuperWindow* SuperWindow;
struct LoggerStruct {
    SLogger* g;
};
extern LoggerStruct Logger;



extern STimer* Timer;
extern SPlatform* g_Platform;
extern char fullpath[1024];
extern class SVersion* Version;
