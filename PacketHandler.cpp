#include "PacketHandler.h"

void devtale::PacketHandler::onPacketSend(std::string packet) const
{
	if (!form_->logSentPacketsCheckBox->Checked) return;
	String^ s = gcnew String(packet.c_str()) + "\r\n";
	auto en = form_->filterSentPacketList->Items->GetEnumerator();
	while(en->MoveNext())
	{
		String^ filter = (String^)en->Current;
		if (s->Contains(filter)) return;
	}
	form_->packetLogTextBox->AppendText(s);
}

void devtale::PacketHandler::onPacketReceive(std::string packet) const
{
	if (!form_->logReceivedPacketsCheckBox->Checked) return;
	System::String^ s = gcnew String(packet.c_str()) + "\r\n";
	auto en = form_->filterReceivedPacketList->Items->GetEnumerator();
	while (en->MoveNext())
	{
		String^ filter = (String^)en->Current;
		if (s->Contains(filter)) return;
	}
	form_->packetLogTextBox->AppendText(s);
}
