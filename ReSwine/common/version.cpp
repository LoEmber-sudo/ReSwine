#include "version.h"
#include <cstdio>
#include <cstdlib>
#include <locale>
#include <iostream>
#include <cstring>
#include "../core/string2.h"
#include "../Globals.h"
SString* SVersion::GetLongString(SString* result)
{
    const char* who = fullpath;
    if (VersionType == Developer) who = "Developer";
    else if (VersionType == Gold) who = "HD Remaster";
    int needed = std::snprintf(nullptr, 0, "S.W.I.N.E. %s v%d.%d.%d",
        who, MajorVersion, MinorVersion, 1846);


    if (result->buf) delete[] result->buf;
    result->buf = new char[needed + 1]; 

    std::snprintf(result->buf, needed + 1, "S.W.I.N.E. %s v%d.%d.%d",
        who, MajorVersion, MinorVersion, 1846);

    result->size = needed;

    return result;
}
SVersion::SVersion()
{
    SVersion* result; // eax

    this->MajorVersion = 1;
    result = this;
    this->MinorVersion = 7;
    this->VersionType = SwineVersionType::Gold;
}
double SVersion::GetFloat()
{

    std::setlocale(LC_NUMERIC, "C");
    SString result{};
    SString::Format(&result, "%d.%d", MajorVersion, MinorVersion);

    const char* str = fullpath;
    if (result.buf)
        str = result.buf;
    double value = std::atof(str);
    if (result.buf)
        delete[] result.buf;

    return value;
}
int SVersion::GetInt() const
{
    return MinorVersion | ((MajorVersion | (VersionType << 8)) << 16);
}
SString* SVersion::GetNetworkString(SString* result)
{
    SString::Format(result, "%d_%d_%d", this->VersionType, this->MajorVersion, this->MinorVersion);
    return result;
}
SString* SVersion::GetShortString(SString* result)
{
    SString::Format(result, "%d.%d", MajorVersion, MinorVersion);
    return result;
}
bool SVersion::GetVersionTypeFromString(const char* strVersionType)
{
    const char* Src = "Developer";
    const char* aHdRemas = "HD Remaster";
    return (_stricmp(strVersionType, Src) == 0 || _stricmp(strVersionType, aHdRemas) == 0) ? TRUE : FALSE;
}
SString* SVersion::GetVersionTypeString(SString* result)
{
    result->buf = nullptr;
    result->size = 0;

    const char* src = nullptr;
    size_t len = 0;

    if (VersionType == Developer)
    {
        src = "Developer";
        len = 9;
    }
    else if (VersionType == Gold)
    {
        src = "HD Remaster";
        len = 11;
    }

    if (src)
    {
        result->size = static_cast<int>(len);
        result->buf = new char[len + 1];
        memcpy(result->buf, src, len + 1);
    }

    return result;
}
bool SVersion::IsGoodVersion(const SVersion& otherVersion) const
{
    return VersionType == otherVersion.VersionType
        && MajorVersion == otherVersion.MajorVersion
        && MinorVersion == otherVersion.MinorVersion;
}

