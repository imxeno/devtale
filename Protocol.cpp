#include "Protocol.h"

#include "NosString.h"
#include "Memory.h"

#pragma managed(push, off)
namespace devtale {

	Protocol::Protocol()
	{
		setup();
	}

	void Protocol::setOnPacket(PacketHandler* handler)
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
		const BYTE send_pattern_byte[] = { 0x53, 0x56, 0x8B, 0xF2, 0x8B, 0xD8, 0xEB, 0x04 };
		const auto send_pattern_mask = "xxxxxxxx";
		_send = Memory::findPattern(send_pattern_byte, send_pattern_mask);
		std::cout << std::hex << "Protocol> send at 0x" << _send << std::dec << std::endl;

		const BYTE receive_pattern_byte[] = { 0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xFF, 0x53, 0x56, 0x57, 0x33, 0xC9, 0x89, 0x4D, 0xF4, 0x89, 0x55, 0xFC, 0x8B, 0xD8, 0x8B, 0x45, 0xFC };
		const auto receive_pattern_mask = "xxxxx?xxxxxxxxxxxxxxxx";
		_receive = Memory::findPattern(receive_pattern_byte, receive_pattern_mask);
		std::cout << std::hex << "Protocol> receive at 0x" << _receive << std::dec << std::endl;

		const BYTE ptr_pattern_byte[] = { 0xA1, 0xFF, 0xFF, 0xFF, 0xFF, 0x8B, 0x00, 0xBA, 0xFF, 0xFF, 0xFF, 0xFF, 0xE8, 0xFF, 0xFF, 0xFF, 0xFF, 0xE9, 0xFF, 0xFF, 0xFF, 0xFF, 0xA1, 0xFF, 0xFF, 0xFF, 0xFF, 0x8B, 0x00, 0x8B, 0x40, 0x40 };
		const auto ptr_pattern_mask = "x????xxx????x????x????x????xxxxx";
		_ptr = *reinterpret_cast<DWORD*>(Memory::findPattern(ptr_pattern_byte, ptr_pattern_mask) + 0x01);
		std::cout << std::hex << "Protocol> ptr at 0x" << _ptr << std::dec << std::endl;
		Memory::detour(reinterpret_cast<BYTE*>(_send), reinterpret_cast<BYTE*>(hookedSend), 16);
		Memory::detour(reinterpret_cast<BYTE*>(_receive), reinterpret_cast<BYTE*>(hookedReceive), 14);
	}

	void __fastcall Protocol::onPacketSend(char* packet)
	{
		const std::string ps(packet);
		get()->handler_->onPacketSend(packet);
	}

	void __fastcall Protocol::onPacketReceive(char* packet)
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

		DWORD network_ptr = _ptr;
		DWORD network_send = _send;
		// ReSharper restore CppUseAuto
		// ReSharper restore CppDeclaratorNeverUsed

		__asm
		{
			MOV EDX, nt_packet
			MOV EAX, DWORD PTR DS : [network_ptr]
			MOV EAX, DWORD PTR DS : [EAX]
			MOV EAX, DWORD PTR DS : [EAX]
			CALL network_send
		}
	}

	void Protocol::receive(char* packet) const
	{
		std::cout << "Protocol> injecting received packet '" << packet << "'" << std::endl;
		// ReSharper disable CppDeclaratorNeverUsed
		// ReSharper disable CppUseAuto
		char* nt_packet = NosString(packet).get();

		DWORD network_ptr = _ptr;
		DWORD network_receive = _receive;
		// ReSharper restore CppUseAuto
		// ReSharper restore CppDeclaratorNeverUsed

		__asm
		{
			MOV EAX, DWORD PTR SS : [network_ptr]
			MOV EAX, DWORD PTR SS : [eax]
			MOV EAX, DWORD PTR SS : [eax]
			MOV EAX, DWORD PTR DS : [eax + 0x34]
			MOV EDX, nt_packet
			CALL network_receive
		}
	}

	void Protocol::send(const std::string& packet) const
	{
		const auto size = packet.length() + 1;
		const auto cstr = new char[size];
		strcpy_s(cstr, size, packet.c_str());
		send(cstr);
		delete[] cstr;
	}

	void Protocol::receive(const std::string& packet) const
	{
		const auto size = packet.length() + 1;
		const auto cstr = new char[size];
		strcpy_s(cstr, size, packet.c_str());
		receive(cstr);
		delete[] cstr;
	}

	void Protocol::hookedSend()
	{
		char* packet;
		_asm
		{
			pushad
			pushfd
			MOV packet, EDX
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
			MOV packet, EDX
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