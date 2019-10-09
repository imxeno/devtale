#pragma once
#include <memory>
class NosString
{
private:
	char* _i8_string;
	unsigned long _i32_length;

public:
	explicit NosString(char* i8_string);

	char* get() const;

	unsigned long length() const;
};