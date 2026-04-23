#include <Windows.h>

uintptr_t module_base = (uintptr_t)GetModuleHandleA(0);

using print = DWORD64(__cdecl*)(unsigned int type, const char* msgg, ...);
print rbx_print = reinterpret_cast<print>(module_base + 0x1DEA630); // NEEDS UPDATING, JOIN DISCORD FOR OFFSETS

void start()
{
    MessageBoxA(NULL, "Successfully injected! Press OK to close.", "Success", MB_OK);
    int seconds = 1;
    while (true) {
        rbx_print(1LL, "injected for %ds", seconds);
        seconds++;
        Sleep(1000);
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        start();
    }
    return TRUE;
}
