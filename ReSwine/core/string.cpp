#include "string2.h"
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <locale>
#include "stream.h"

SString::SString(const SString& src)
{
    if (src.size > 0)
    {
        size = src.size;
        buf = new char[size + 1];
        memcpy(buf, src.buf, size + 1);
    }
    else
    {
        size = 0;
        buf = nullptr;
    }
}

SString& SString::stringEQ(const char* str)
{
    if (buf)
    {
        delete[] buf;
        buf = nullptr;
    }

    if (str)
    {
        size = static_cast<int>(strlen(str));
        buf = new char[size + 1];
        memcpy(buf, str, size + 1);
    }
    else
    {
        size = 0;
        buf = nullptr;
    }
    return *this;
}

SString& SString::stringEQ2(const SString& src)
{
    if (buf)
    {
        delete[] buf;
        buf = nullptr;
    }

    if (src.size > 0)
    {
        size = src.size;
        buf = new char[size + 1];
        memcpy(buf, src.buf, size + 1);
    }
    else
    {
        size = 0;
        buf = nullptr;
    }
    return *this;
}

SString SString::Format(SString* result, const char* format, ...)
{
    if (!result || !format)
        return SString();

    char temp[1024];

    va_list args;
    va_start(args, format);
    std::setlocale(LC_ALL, "C");
    int len = std::vsnprintf(temp, sizeof(temp), format, args);
    va_end(args);

    if (len < 0 || len >= static_cast<int>(sizeof(temp)))
    {
        result->buf = nullptr;
        result->size = 0;
        return *result;
    }

    result->size = len;
    result->buf = new char[len + 1];
    std::memcpy(result->buf, temp, len + 1);

    return *result;
}

SString* SString::stringPLUS(SString* result, const char* str)
{
    if (!result || !str) return nullptr;

    unsigned int strLen = std::strlen(str);
    char* newBuf = new char[size + strLen + 1];

    if (buf)
        std::memcpy(newBuf, buf, size);

    std::memcpy(newBuf + size, str, strLen + 1); // include null terminator

    result->buf = newBuf;
    result->size = size + strLen;

    return result;
}

void SString::Load(SStream* is)
{
    if (!is) return;
    int word = is->NewTypeStrings ? is->ReadWord() : is->ReadWord() - 1;
    size = word;

    if (buf) {
        delete[] buf;
        buf = nullptr;
    }

    if (size >= 0) {
        buf = new char[size + 1];
        if (!buf) {
            throw std::bad_alloc();
        }
        is->Read(buf, size);
        buf[size] = '\0';
    }
}
void SString::Save(SStream* stream)
{
    if (buf)
    {
        if (size >= 0xFFFF)
        {
            throw std::runtime_error("String is too long");
        }
        stream->WriteWord(size);
        stream->Write(buf, size);
    }
    else
    {
        stream->WriteWord(0);
    }
}
SString::SString(const char* str)
{
    if (str)
    {
        size = static_cast<int>(strlen(str));
        buf = new char[size + 1];
        memcpy(buf, str, size + 1);
    }
    else
    {
        size = 0;
        buf = nullptr;
    }
}

SString* SString::Dirname(SString* result)
{
    int lastSlash = -1;
    for (int i = 0; i < size - 1; ++i)
    {
        if (buf[i] == '/' || buf[i] == '\\')
            lastSlash = i;
    }

    if (lastSlash < 0)
    {
        result->size = 1;
        result->buf = new char[2];
        memcpy(result->buf, ".", 2);
        return result;
    }

    if (lastSlash > 0)
    {
        result->size = lastSlash;
        result->buf = new char[lastSlash + 1];
        memcpy(result->buf, buf, lastSlash);
        result->buf[lastSlash] = '\0';
    }
    else
    {
        result->size = 0;
        result->buf = nullptr;
    }

    return result;
}
