#include "NosString.h"

NosString::NosString(char* i8_string)
{
	this->i32_length_ = strlen(i8_string);

	this->i8_string_ = static_cast<char*>(malloc(this->i32_length_ + 8 + 1));

	*reinterpret_cast<unsigned long*>(this->i8_string_ + 0x00) = 1;
	*reinterpret_cast<unsigned long*>(this->i8_string_ + 0x04) = this->i32_length_;

	memcpy(this->i8_string_ + 0x08, i8_string, this->i32_length_);

	*(this->i8_string_ + this->i32_length_ + 8) = '\0';
}

char* NosString::get() const
{
	return this->i8_string_ + 0x08;
}

unsigned long NosString::length() const
{
	return this->i32_length_;
}