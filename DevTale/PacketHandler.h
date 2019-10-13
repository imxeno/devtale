#pragma once
#include "MainForm.h"

#include "vcclr.h"
#include <string>

namespace devtale {

class PacketHandler
{
public:
	PacketHandler(MainForm^ form)
	{
		form_ = form;
	}

	void onPacketSend(std::string packet) const;
	void onPacketReceive(std::string packet) const;
	
private:
	gcroot<MainForm^> form_;
	void appendLog(System::String^ packet, bool is_received) const;
};

}
