#pragma once
#include "MainForm.h"

#include "vcclr.h"
#include <string>

namespace devtale {

class PacketHandler
{
private:
	gcroot<MainForm^> form_;
public:
	PacketHandler(MainForm^ form)
	{
		form_ = form;
	}

	void onPacketSend(std::string packet);
	void onPacketReceive(std::string packet);
	
};

}
