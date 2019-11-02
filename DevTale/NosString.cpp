// This file is part of DevTale.
// Copyright (c) 2019 Piotr "Xeno" Adamczyk
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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