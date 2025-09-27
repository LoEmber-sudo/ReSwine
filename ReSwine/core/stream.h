#pragma once
#include <cstdint>

struct SStream; // forward declaration

struct SStream_vtbl {
    void(__thiscall* AddRef)(SStream* thisptr);
    void(__thiscall* Release)(SStream* thisptr);
    void(__thiscall* Read)(SStream* thisptr, void* buffer, int size);
    int(__thiscall* ReadMax)(SStream* thisptr, void* buffer, int size);
    void(__thiscall* Write)(SStream* thisptr, const void* buffer, int size);
    int(__thiscall* Seek)(SStream* thisptr, int offset, int origin);
};

struct SStream {
    SStream_vtbl* vtbl;
    bool NewTypeStrings;

    void Read(void* buffer, int size);
    uint16_t ReadWord();
    int ReadMax(void* buffer, int size);
    void Write(const void* buffer, int size);
    void WriteWord(uint16_t value);
};
