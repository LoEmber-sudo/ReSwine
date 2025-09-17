#pragma once
#include <cstdint>
#include "../window/stack.h" //SStack<int>

struct SStream_vtbl;

struct SStream
{
    SStream_vtbl* __vftable = nullptr; 
    SStack<int> Chunks;               
    bool NewTypeStrings = false;

    SStream() = default;
    virtual ~SStream() = default;
};
