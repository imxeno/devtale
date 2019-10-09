#include "PacketHandler.h"

void devtale::PacketHandler::onPacketSend(std::string packet)
{
	packet += "\r\n";
	if (form_->logSentPacketsCheckBox->Checked) {
		form_->packetLogTextBox->AppendText(gcnew String(packet.c_str()));
	}
}

void devtale::PacketHandler::onPacketReceive(std::string packet)
{
	packet += "\r\n";
	if (form_->logReceivePacketsCheckBox->Checked) {
		form_->packetLogTextBox->AppendText(gcnew String(packet.c_str()));
	}
}
