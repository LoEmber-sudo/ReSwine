#pragma once
// swineversion.h
#include "../core/string2.h" // SString
enum SwineVersionType { Developer = 0, Gold = 1 };
class SVersion {
public:
    SwineVersionType VersionType;
    int MajorVersion;
    int MinorVersion;
    SString* GetLongString(SString* result);
    double GetFloat();
    SVersion();
    int GetInt() const;
	SString* GetNetworkString(SString* result);
    SString* GetShortString(SString* result);
    bool GetVersionTypeFromString(const char* strVersionType);
    SString* GetVersionTypeString(SString* result);
	bool IsGoodVersion(const SVersion& otherVersion) const;
};