#include "Memory.h"
#pragma managed(push, off)
bool Memory::detour(BYTE* old_func, BYTE* new_func, const DWORD len)
{
	std::cout << std::hex << "Detour> detouring function at 0x" << reinterpret_cast<DWORD>(old_func) << " to 0x" << reinterpret_cast<DWORD>(new_func) << " overwriting 0x" << len << " bytes" << std::dec << std::endl;
	std::cout << "Detour> real function region 0x" << reinterpret_cast<DWORD>(old_func) << " - 0x" << (reinterpret_cast<DWORD>(old_func) + len - 1) << std::dec << std::endl;
	DWORD dw_real_old;
	DWORD dw_hook_old;
	DWORD dw_ignored;
	const size_t total_length = 5 + len;
	auto new_mem4_base = static_cast<BYTE*>(malloc(total_length));
	std::cout << "Detour> setting PAGE_READWRITE on allocated region" << std::endl;
	VirtualProtect(new_mem4_base, total_length, PAGE_EXECUTE_READWRITE, &dw_hook_old);

	std::cout << "Detour> allocated 0x" << std::hex << total_length << " bytes at " << reinterpret_cast<DWORD>(new_mem4_base) << std::dec << std::endl;
	std::cout << "Detour> allocated memory region 0x" << reinterpret_cast<DWORD>(new_mem4_base) << " - 0x" << reinterpret_cast<DWORD>(new_mem4_base + total_length - 1) << std::dec << std::endl;

	if (new_mem4_base == nullptr)
		return false;

	std::cout << "Detour> filling newly allocated region with NOPs" << std::endl;

	for (DWORD i = 0; i < total_length; i++)
		new_mem4_base[i] = 0x90;

	std::cout << "Detour> setting PAGE_READWRITE on real function region" << std::endl;

	VirtualProtect(old_func, len, PAGE_EXECUTE_READWRITE, &dw_real_old);

	std::cout << "Detour> copying bytes from real function to allocated region" << std::endl;

	memcpy(new_mem4_base, old_func, len);

	std::cout << std::hex << "Detour> setting CALL to 0x" << DWORD(new_func - old_func - 5) << " at 0x" << reinterpret_cast<DWORD>(old_func) << std::dec << std::endl;

	old_func[0] = 0xE8;
	*reinterpret_cast<DWORD*>(old_func + 0x01) = DWORD(new_func - old_func - 5);

	std::cout << std::hex << "Detour> setting JMP to 0x" << DWORD(new_mem4_base - (old_func + 0x5) - 5) << " at 0x" << reinterpret_cast<DWORD>(old_func + 0x06) << std::dec << std::endl;

	old_func[5] = 0xE9;
	*reinterpret_cast<DWORD*>(old_func + 0x06) = DWORD(new_mem4_base - (old_func + 0x5) - 5);
	BYTE* new_mem4_base_end = new_mem4_base + len;

	std::cout << std::hex << "Detour> setting JMP to 0x" << DWORD((old_func + 10) - new_mem4_base_end - 5) << " at 0x" << reinterpret_cast<DWORD>(new_mem4_base_end + 0x01) << std::dec << std::endl;

	new_mem4_base_end[0] = 0xE9;
	*reinterpret_cast<DWORD*>(new_mem4_base_end + 0x01) = DWORD((old_func + 10) - new_mem4_base_end - 5);

	std::cout << std::hex << "Detour> filling remaining 0x" << (len - 10) << " real function bytes with NOPs" << std::dec << std::endl;

	for (DWORD i = 10; i < len; i++)
		old_func[i] = 0x90;

	std::cout << "Detour> setting correct VirtualProtect" << std::endl;

	VirtualProtect(old_func, len, dw_real_old, &dw_ignored);

	std::cout << "Detour> if we're still alive then we're done!" << std::endl;

	return true;
}

bool Memory::dataCompare(const unsigned char* p_data, const unsigned char* b_mask, const char* sz_mask)
{
	for (; *sz_mask; ++sz_mask, ++p_data, ++b_mask)
		if (*sz_mask == 'x' && *p_data != *b_mask)
			return false;
	return (*sz_mask) == 0;
}

DWORD Memory::findPattern(const BYTE* b_mask, const char* sz_mask)
{
	const DWORD dw_address = 0x00400000;
	const DWORD dw_len = 0x00436000;

	for (DWORD i = 0; i < dw_len; i++)
		if (dataCompare(reinterpret_cast<unsigned char*>(dw_address + i), b_mask, sz_mask))
			return static_cast<DWORD>(dw_address + i);
	return 0;
}

#pragma managed(pop)