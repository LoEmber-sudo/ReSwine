#pragma once
#include "window/widget.h"
#include "core/stream.h"
#include "userEventProp.h"
#include <Windows.h>
#include <cstdint>

struct SWindow : SWidget
{
    wchar_t ClassName[32] = {};
    HWND* hWnd = nullptr;
    unsigned int Style = 0;
    int Index = 0;
    int ModalResult = 0;
    SWidget* ModalTarget = nullptr;
    SStream* EventStream = nullptr;
    int EventDirection = 0;
    UserEventProp UserEvents[10] = {};

    int LastMouseX = 0;
    int LastMouseY = 0;
    int LastMouseButtons = 0;
    bool MouseCursorRestricted = false;

    int Dpi = 0;
    float Scaling = 1.0f;
    bool shouldClose = false;

    // Constructor / Destructor
    SWindow() = default;
    virtual ~SWindow() = default;

    // Optional helper functions can be added here later
};
