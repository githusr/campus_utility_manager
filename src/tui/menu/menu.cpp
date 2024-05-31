#include "tui/interaction.h"
#include <cstdio>

void showMainMenu()
{
    clearScreen();
    puts("------------------------------------------");
    puts("\t欢迎使用水电气信息管理系统\t");
    puts("------------------------------------------");
    puts("1. 账单查询");
    puts("2. 管理员登陆");
    puts("3. 退出系统");
    puts("------------------------------------------");
    puts("请选择功能: ");
}