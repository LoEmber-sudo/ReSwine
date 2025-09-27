#pragma once
#include "stream.h"
class SString {
public:
	char* buf;
	int size;
	static SString Format(SString* result, const char* format, ...);
	SString& stringEQ(const char* str);
	SString& stringEQ2(const SString& src);
	SString() : buf(nullptr), size(0) {}
	SString(const SString& src);
	SString* stringPLUS(SString * result, const char* str);
	void Load(SStream* is);
	void Save(SStream* stream);
	SString(const char* str);
	SString* Dirname(SString* result);
};