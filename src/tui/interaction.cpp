#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "tui/interaction.h"

bool isWaitingForKey = false;

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

void showWelcome()
{
    clearScreen();
    puts("------------------------------------------");
    puts("\t欢迎使用水电气信息管理系统\t");
}

void outputError(const std::runtime_error &err)
{
    clearScreen();
    std::cerr << err.what() << std::endl;
    waitForKey();
    isWaitingForKey = true;
}

void showGoodbye()
{
    clearScreen();
    puts("------------------------------------------");
    puts("感谢您的使用, 再见!");
    puts("------------------------------------------");
}