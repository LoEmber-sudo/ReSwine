#pragma once
#include "window/window.h"   // Base class
#include "window/displaymode.h"
#include "window/antialiasingmode.h"
#include "core/darray.h"
#include "window/messagebox.h"
#include <cstdint>

// Forward declarations
struct SMessageBox;
struct SDXWindow : SWindow
{
    // Display and graphics settings
    SDisplayMode DisplayMode;
    bool VSync = false;
    SAntialiasingMode AntialiasingMode;
    
    // Monitor and resolution info
    int Monitor = 0;
    int FullScreenWidth = 0;
    int FullScreenHeight = 0;
    int WindowedX = 0;
    int WindowedY = 0;
    int WindowedWidth = 0;
    int WindowedHeight = 0;

    // Desktop resolution info
    int DesktopX = 0;
    int DesktopY = 0;
    int DesktopWidth = 0;
    int DesktopHeight = 0;

    // Monitor rectangles array
    SDarray MonitorRects;

    // Cursor position
    int CursorX = 0;
    int CursorY = 0;

    // Optional message box
    SMessageBox* MBox = nullptr;

    // Constructor / Destructor
    SDXWindow() = default;
    virtual ~SDXWindow() = default;

    // Optional helper functions can be added here later
};
