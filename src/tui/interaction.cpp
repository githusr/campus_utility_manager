#include <cstdio>
#include <cstdlib>

void clearScreen()
{
#ifndef _WIN32
    system("clear");
#else
    system("cls");
#endif
}

void waitForKey()
{
    puts("------------------------------------------");
    puts("Press Enter to continue...");
    char tmp;
    do {
        scanf("%c", &tmp);
    } while (tmp != '\n');
    getchar();
}