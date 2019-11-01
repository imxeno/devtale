#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#include "MainForm.h"
#include "Protocol.h"
#include "PacketHandler.h"

void WINAPI DllThread()
{
	devtale::MainForm^ form = gcnew devtale::MainForm();
	devtale::Protocol::get()->setPacketHandler(new devtale::PacketHandler(form));
	System::Windows::Forms::Application::Run(form);
}

#pragma managed(push, off)
void CreateDebugWindow() {
	FILE* n_in; FILE* n_out; FILE* n_err;
	AllocConsole();
	freopen_s(&n_in, "CONIN$", "r", stdin);
	freopen_s(&n_out, "CONOUT$", "w", stdout);
	freopen_s(&n_err, "CONOUT$", "w", stderr);
	std::cout.clear();
}

void WINAPI Setup()
{
	devtale::Protocol::get();
	CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(DllThread), nullptr, 0, nullptr);
}

bool WINAPI DllMain(_In_ HINSTANCE instance, _In_ DWORD call_reason, _In_ LPVOID reserved)
{
	switch (call_reason)
	{
	case DLL_PROCESS_ATTACH:
#ifdef _DEBUG
		CreateDebugWindow();
#endif
		CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(Setup), nullptr, 0, nullptr);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
	default:
		break;
	}
	return TRUE;
}
#pragma managed(pop)
