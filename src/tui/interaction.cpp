#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
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
    } while (tmp != '\n' && tmp != EOF);
    getchar();

    // int ch;
    // while ((ch = getchar()) != '\n' && ch != EOF);
    // getchar();

    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // 等待用户输入换行符
    // std::string line;
    // std::getline(std::cin, line);

}

void showWelcome()
{
    clearScreen();
    puts("------------------------------------------");
    puts("\t欢迎使用水电气信息管理系统\t");
    puts("------------------------------------------");
    puts("Press Enter to continue...");
    getchar();
    clearScreen();
}

void outputError(const std::string &err)
{
    clearScreen();
    std::cerr << err << std::endl;
    waitForKey();
    clearScreen();
    isWaitingForKey = true;
}

void showGoodbye()
{
    clearScreen();
    puts("------------------------------------------");
    puts("感谢您的使用, 再见!");
    puts("------------------------------------------");
}