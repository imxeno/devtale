#pragma once
#include <memory>
class NosString
{
private:
	char* i8_string_;
	unsigned long i32_length_;

public:
	explicit NosString(char* i8_string);

	char* get() const;

	unsigned long length() const;
};