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
				appendLog(s, false);
			}
			return;
		}
	}
	
	if (form_->sentBlacklistRadio->Checked)
	{
		appendLog(s, false);
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
				appendLog(s, true);
			}
			return;
		}
	}
	if (form_->receivedBlacklistRadio->Checked)
	{
		appendLog(s, true);
	}
}

void devtale::PacketHandler::appendLog(System::String^ packet, bool is_received) const
{
	if(form_->packetLogPrependDirectionCheckBox->Checked)
	{
		packet = (is_received ? "[R] " : "[S] ") + packet;
	}

	if(form_->packetLogPrependTimeCheckBox->Checked)
	{
		packet = "[" + System::DateTime::Now.ToLongTimeString() + "] " + packet;
	}
	
	form_->packetLogTextBox->AppendText(packet);
}
