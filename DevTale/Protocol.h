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