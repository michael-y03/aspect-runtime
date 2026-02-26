#include "pch.h"
#include <Windows.h>
#include <fstream>

DWORD WINAPI AspectMain(LPVOID lpParam)
{
    Sleep(3000);

    std::ofstream log("aspect_log.txt");
    log << "Aspect Core loaded successfully." << std::endl;
    log.close();

    while (true)
    {
        Sleep(1000);
    }

    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID reserved)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule);
        CreateThread(0, 0, &AspectMain, NULL, 0, NULL);
    }
    return TRUE;
}