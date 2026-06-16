#include <Windows.h>

uintptr_t base = (uintptr_t)GetModuleHandleA(0); // get roblox base, since we are injected to it, we put 0, which indicates the exe we are in, in this case RobloxPlayerBeta.exe

using Print = DWORD64(__cdecl*)(unsigned int, const char*, ...);
Print r_print = reinterpret_cast<Print>(base + 0x1E08380); // needs updating uwu

void start()
{
    r_print(0, "injected"); // default print
    r_print(1, "injected"); // info print
    r_print(2, "injected"); // warning print
    r_print(3, "injected"); // error print
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        start();
    }
    return TRUE;
}
