#include "stream.h"

void SStream::Read(void* buffer, int size) {
    vtbl->Read(this, buffer, size);
}

uint16_t SStream::ReadWord() {
    uint16_t result = 0;
    Read(&result, sizeof(result));
    return result;
}

int SStream::ReadMax(void* buffer, int size) {
    return vtbl->ReadMax(this, buffer, size);
}

void SStream::Write(const void* buffer, int size) {
    vtbl->Write(this, buffer, size);
}

void SStream::WriteWord(uint16_t value) {
    Write(&value, sizeof(value));
}
