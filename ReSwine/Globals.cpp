#include "Globals.h"
#include "common/swineversion.h"
#include "core/logger.h"
#include "core/timer.h"
#include "platform/platform.h"

SSuperWindow* SuperWindow = nullptr;

struct {
    SLogger* g;
} Logger = { nullptr };

SVersion* Version = nullptr;
STimer* Timer = nullptr;
SPlatform* g_Platform = nullptr;

char fullpath[1024] = "default/path";
