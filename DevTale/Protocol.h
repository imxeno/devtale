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

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <string>
#include <iostream>

namespace devtale {

	class PacketHandler;

class Protocol
{
public:
	static Protocol* get();
	void send(char* packet) const;
	void send(const std::string& packet) const;
	void receive(char* packet) const;
	void receive(const std::string& packet) const;
	void setPacketHandler(PacketHandler* handler);


private:
	Protocol();

	void setup();
	static void hookedSend();
	static void hookedReceive();
	static void __stdcall onPacketSend(char* packet);
	static void __stdcall onPacketReceive(char* packet);
	DWORD ptr_ = 0, send_ = 0, receive_ = 0;
	PacketHandler *handler_;
};

}