#include <Windows.h>
#define rebase(x) (x + reinterpret_cast<uintptr_t>GetModuleHandleA(0))

const uinptr_t Print = 0x834D90; // needs updating
using r_print_t = int(__fastcall*)(unsigned int, const char*, ...);
r_print_t r_print = reinterpret_cast<r_print_t>(Print);

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
