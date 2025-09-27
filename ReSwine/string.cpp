#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <locale>
#include <string>
#include "string2.h"

SString* Format(SString* result, const char* format, ...) {
    if (!result || !format) return nullptr;

    char temp[1024]; // temporary buffer for formatted string

    va_list args;
    va_start(args, format);
    std::setlocale(LC_ALL, "C"); // ensure "C" locale for consistent formatting
    int len = vsnprintf(temp, sizeof(temp), format, args);
    va_end(args);

    if (len < 0 || len >= static_cast<int>(sizeof(temp))) {
        // formatting failed or output too long
        result->buf = nullptr;
        result->size = 0;
        return result;
    }

    result->size = len;
    result->buf = new char[len + 1];
    std::memcpy(result->buf, temp, len + 1); // include null terminator
    return result;
}
