#include <Windows.h>

uintptr_t ModuleBase = (uintptr_t)GetModuleHandleA(0); // Get RobloxPlayer.exe Module Handle (0 = Parent Window Handle)

using Print = DWORD64(__cdecl*)(unsigned int Type, const char* Message, ...); // Type for print
Print PrintConsole = reinterpret_cast<Print>(ModuleBase + 0x1DEA630); // Actual print, calling Print Offset, on the Module Base (Roblox)

void StartPrinting()
{
    int Seconds = 1; // How many seconds is 1 second (yes.)
    while (true) { // Loops the print
        PrintConsole(1LL, "injected for %ds", Seconds); // Prints how many seconds active
        Seconds++; // add 1 second each time
        Sleep(1000); // Slows down the loop to run once per second
                    // (1000 milliseconds = 1 second)
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) { // EntryPoint
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) { // If DLL is injected/attached then do..
        StartPrinting(); // Starting our printsploit
    }
    return TRUE;
}