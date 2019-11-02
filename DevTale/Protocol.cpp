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

#include "Protocol.h"

#include "NosString.h"
#include "Memory.h"
#include "PacketHandler.h"

#pragma managed(push, off)
namespace devtale
{
	Protocol::Protocol()
	{
		setup();
	}

	void Protocol::setPacketHandler(PacketHandler* handler)
	{
		this->handler_ = handler;
	}

	Protocol* Protocol::get()
	{
		static Protocol* p;
		if (p == nullptr) p = new Protocol();
		return p;
	}
#pragma optimize("", off)

	void Protocol::setup()
	{
		// ReSharper disable StringLiteralTypo
		const BYTE send_pattern_byte[] = {0x53, 0x56, 0x8B, 0xF2, 0x8B, 0xD8, 0xEB, 0x04};
		const auto send_pattern_mask = "xxxxxxxx";
		const BYTE receive_pattern_byte[] = {
			0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xFF, 0x53, 0x56, 0x57, 0x33, 0xC9, 0x89, 0x4D, 0xF4, 0x89, 0x55, 0xFC, 0x8B,
			0xD8, 0x8B, 0x45, 0xFC
		};
		const auto receive_pattern_mask = "xxxxx?xxxxxxxxxxxxxxxx";
		const BYTE ptr_pattern_byte[] = {
			0xA1, 0xFF, 0xFF, 0xFF, 0xFF, 0x8B, 0x00, 0xBA, 0xFF, 0xFF, 0xFF, 0xFF, 0xE8, 0xFF, 0xFF, 0xFF, 0xFF, 0xE9,
			0xFF, 0xFF, 0xFF, 0xFF, 0xA1, 0xFF, 0xFF, 0xFF, 0xFF, 0x8B, 0x00, 0x8B, 0x40, 0x40
		};
		const auto ptr_pattern_mask = "x????xxx????x????x????x????xxxxx";
		// ReSharper restore StringLiteralTypo

		send_ = Memory::findPattern(send_pattern_byte, send_pattern_mask);
		std::cout << std::hex << "Protocol> send at 0x" << send_ << std::dec << std::endl;

		receive_ = Memory::findPattern(receive_pattern_byte, receive_pattern_mask);
		std::cout << std::hex << "Protocol> receive at 0x" << receive_ << std::dec << std::endl;

		ptr_ = *reinterpret_cast<DWORD*>(Memory::findPattern(ptr_pattern_byte, ptr_pattern_mask) + 0x01);
		std::cout << std::hex << "Protocol> ptr at 0x" << ptr_ << std::dec << std::endl;
		Memory::detour(reinterpret_cast<BYTE*>(send_), reinterpret_cast<BYTE*>(hookedSend), 16);
		Memory::detour(reinterpret_cast<BYTE*>(receive_), reinterpret_cast<BYTE*>(hookedReceive), 14);
	}

	void __stdcall Protocol::onPacketSend(char* packet)
	{
		const std::string ps(packet);
		get()->handler_->onPacketSend(packet);
	}

	void __stdcall Protocol::onPacketReceive(char* packet)
	{
		const std::string ps(packet);
		get()->handler_->onPacketReceive(packet);
	}

	void Protocol::send(char* packet) const
	{
		std::cout << "Protocol> sending packet '" << packet << "'" << std::endl;
		// ReSharper disable CppDeclaratorNeverUsed
		// ReSharper disable CppUseAuto
		char* nt_packet = NosString(packet).get();

		DWORD network_ptr = ptr_;
		DWORD network_send = send_;
		// ReSharper restore CppUseAuto
		// ReSharper restore CppDeclaratorNeverUsed

		__asm
			{
			mov edx, nt_packet
			mov eax, dword ptr ds : [network_ptr]
			mov eax, dword ptr ds : [eax]
			mov eax, dword ptr ds : [eax]
			call network_send
			}
	}

	void Protocol::receive(char* packet) const
	{
		std::cout << "Protocol> injecting received packet '" << packet << "'" << std::endl;
		// ReSharper disable CppDeclaratorNeverUsed
		// ReSharper disable CppUseAuto
		char* nt_packet = NosString(packet).get();

		DWORD network_ptr = ptr_;
		DWORD network_receive = receive_;
		// ReSharper restore CppUseAuto
		// ReSharper restore CppDeclaratorNeverUsed

		__asm
			{
			mov eax, dword ptr ss : [network_ptr]
			mov eax, dword ptr ss : [eax]
			mov eax, dword ptr ss : [eax]
			mov eax, dword ptr ds : [eax + 0x34]
			mov edx, nt_packet
			call network_receive
			}
	}

	void Protocol::send(const std::string& packet) const
	{
		const auto size = packet.length() + 1;
		const auto str = new char[size];
		strcpy_s(str, size, packet.c_str());
		send(str);
		delete[] str;
	}

	void Protocol::receive(const std::string& packet) const
	{
		const auto size = packet.length() + 1;
		const auto str = new char[size];
		strcpy_s(str, size, packet.c_str());
		receive(str);
		delete[] str;
	}

	void Protocol::hookedSend()
	{
		char* packet;
		_asm
			{
			pushad
			pushfd
			mov packet, edx
			}

		get()->onPacketSend(packet);

		_asm
			{
			popfd
			popad
			}
	}

	void Protocol::hookedReceive()
	{
		char* packet;

		_asm
			{
			pushad
			pushfd
			mov packet, edx
			}

		get()->onPacketReceive(packet);

		_asm
			{
			popfd
			popad
			}
	}
#pragma optimize("", on)
}

#pragma managed(pop)
