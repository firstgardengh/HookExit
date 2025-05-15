#include <windows.h>
#include <iostream>
#include <thread>
#include <vector>

bool detour(void* source, void* destination)
{
	uint8_t instructions[14] = {
		0xFF, 0x25, 0x0, 0x0, 0x0, 0x0, /* JMP opcode and [RIP + 0] */
		0, 0, 0, 0, 0, 0, 0, 0 /* Address placeholder to initialize 14 bytes */
	};

	uint64_t destination_addr = (uint64_t)destination;

	memcpy(instructions + 6, &destination_addr, sizeof(destination_addr));

	DWORD old;
	VirtualProtect(source, sizeof(instructions), PAGE_EXECUTE_READWRITE, &old);

	memcpy(source, instructions, sizeof(instructions));

	VirtualProtect(source, sizeof(instructions), old, &old);

	return true;
}

void destination()
{
	MessageBoxA(0, "Application has tried to exit. Press OK to exit.", 0, 0);

	TerminateProcess(GetCurrentProcess(), 0); // Apply your own exit logic here or revert the hook.
}

bool DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
		detour(&exit, &destination); // You can add your own functions
}

