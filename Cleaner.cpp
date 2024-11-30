#include <iostream>
#include <windows.h>
#include <string>
#include <random>
#include <ctime>

void T(const std::wstring& filePath) {
    HANDLE hFile = CreateFileW(filePath.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        return;
    }
    SetFilePointer(hFile, 0, NULL, FILE_BEGIN);
    SetEndOfFile(hFile);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);
    char randomData[1024];
    for (int i = 0; i < sizeof(randomData); ++i) {
        randomData[i] = dis(gen);  
    }
    DWORD bytesWritten;
    WriteFile(hFile, randomData, sizeof(randomData), &bytesWritten, NULL);
    CloseHandle(hFile);
}

void M(const std::wstring& filePath) {
    std::wstring tempDir = L"C:\\Windows\\Temp\\";
    std::wstring randomFileName = tempDir + L"" + std::to_wstring(rand()) + L".tmp";
    if (MoveFileW(filePath.c_str(), randomFileName.c_str())) {
        DeleteFileW(randomFileName.c_str());
    }
}
void D() {
    const wchar_t* prefetchPath = L"C:\\Windows\\Prefetch\\";
    WIN32_FIND_DATA findFileData;

    HANDLE hFind = FindFirstFileW((std::wstring(prefetchPath) + L"*").c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        return;
    }

    do {
        if (wcscmp(findFileData.cFileName, L".") != 0 && wcscmp(findFileData.cFileName, L"..") != 0) {
            std::wstring filePath = prefetchPath + std::wstring(findFileData.cFileName);

          
            T(filePath);
            M(filePath);
        }
    } while (FindNextFileW(hFind, &findFileData) != 0);

    FindClose(hFind);
}
void S() {
    SC_HANDLE hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (hSCManager == NULL) {
        return;
    }

    SC_HANDLE hService = OpenService(hSCManager, L"SysMain", SERVICE_STOP | SERVICE_QUERY_STATUS);
    if (hService == NULL) {
        CloseServiceHandle(hSCManager);
        return;
    }

    SERVICE_STATUS status;
    if (ControlService(hService, SERVICE_CONTROL_STOP, &status)) {
        
    }

    CloseServiceHandle(hService);
    CloseServiceHandle(hSCManager);
}
int main() {
    D();  
    return 0;
}
