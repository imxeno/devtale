#include "PacketHandler.h"

void devtale::PacketHandler::onPacketSend(std::string packet) const
{
	if (!form_->logSentPacketsCheckBox->Checked) return;
	String^ s = gcnew String(packet.c_str()) + "\r\n";
	auto en = form_->filterSentPacketList->Items->GetEnumerator();
	while(en->MoveNext())
	{
		String^ filter = (String^)en->Current;
		if (s->Contains(filter))
		{
			if(form_->sentWhitelistRadio->Checked)
			{
				form_->packetLogTextBox->AppendText(s);
			}
			return;
		}
	}
	
	if (form_->sentBlacklistRadio->Checked)
	{
		form_->packetLogTextBox->AppendText(s);
	}
}

void devtale::PacketHandler::onPacketReceive(std::string packet) const
{
	if (!form_->logReceivedPacketsCheckBox->Checked) return;
	System::String^ s = gcnew String(packet.c_str()) + "\r\n";
	auto en = form_->filterReceivedPacketList->Items->GetEnumerator();
	while (en->MoveNext())
	{
		String^ filter = (String^)en->Current;
		if (s->Contains(filter))
		{
			if (form_->receivedWhitelistRadio->Checked)
			{
				form_->packetLogTextBox->AppendText(s);
			}
			return;
		}
	}
	if (form_->receivedBlacklistRadio->Checked)
	{
		form_->packetLogTextBox->AppendText(s);
	}
}
