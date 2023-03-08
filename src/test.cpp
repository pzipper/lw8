#include <cstdint>
#include <cstdio>
#include <lw8.h>

#ifdef _WIN32
#include <Windows.h>
#endif

using namespace lw8;

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // Enable UTF-8 output on Windows
#endif

    Utf8 source = Utf8("Hello! 😊");
    Chars chars = Chars(&source);

    char buffer[5];
    while (!chars.end())
    {
        Codepoint codepoint = chars.next();
        codepoint.to_utf8((uint8_t *)buffer);

        buffer[codepoint.utf8_len()] = 0; // add null terminator

        printf("%s\n", buffer);
    }
}