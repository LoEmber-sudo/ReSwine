#pragma once
#include <cstdint>

struct SWidget_vtbl;

struct SWidget
{
    SWidget_vtbl* __vftable = nullptr; //
    int X = 0;
    int Y = 0;
    const int Width = 0;
    const int Height = 0;

    SWidget* Parent = nullptr;
    SWidget* Child = nullptr;
    SWidget* Sibling = nullptr;
    SWidget* Focus = nullptr;
    SWidget* FocusSibling = nullptr;

    SWidget* Left = nullptr;
    SWidget* Right = nullptr;
    SWidget* Up = nullptr;
    SWidget* Down = nullptr;

    bool Enabled = true;
    bool Visible = true;

    int Cursor = 0;
    int Gravity = 0;

    SWidget() = default;
    virtual ~SWidget() = default;
};
