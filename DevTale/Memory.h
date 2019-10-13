#pragma once
#include <windows.h>

class Memory
{
public:
	static bool detour(BYTE* old_func, BYTE* new_func, DWORD len);
	static bool dataCompare(const unsigned char* p_data, const unsigned char* b_mask, const char* sz_mask);
	static DWORD findPattern(const BYTE* b_mask, const char* sz_mask);
};

