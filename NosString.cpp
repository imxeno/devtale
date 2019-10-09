#include "NosString.h"

NosString::NosString(char* i8_string)
{
	this->_i32_length = strlen(i8_string);

	this->_i8_string = static_cast<char*>(malloc(this->_i32_length + 8 + 1));

	*reinterpret_cast<unsigned long*>(this->_i8_string + 0x00) = 1;
	*reinterpret_cast<unsigned long*>(this->_i8_string + 0x04) = this->_i32_length;

	memcpy(this->_i8_string + 0x08, i8_string, this->_i32_length);

	*(this->_i8_string + this->_i32_length + 8) = '\0';
}

char* NosString::get() const
{
	return this->_i8_string + 0x08;
}

unsigned long NosString::length() const
{
	return this->_i32_length;
}