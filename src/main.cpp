#include "handle_invalid_input.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
int main(int argc, char *argv[])
{
    system("clear");
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "\t欢迎使用水电气信息管理系统\t" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "1. 账单查询" << std::endl;
    std::cout << "2. 管理员登陆" << std::endl;
    std::cout << "3. 退出系统" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "请选择功能: ";
    int choice = 0;
    std::cin >> choice;
    try {
    switch (choice) {
    case 1:
        system("clear");
        std::cout << "请输入您的编号: ";
        // std::string id;
        // std::cin >> id;
        std::cout << "请输入您的姓名: ";
        // std::string name;
        // std::cin >> name;
        break;
    case 2:
        system("clear");
        std::cout << "请输入管理员账号: ";
        // std::string acount;
        // std::cin >> acount;
        std::cout << "请输入管理员密码: ";
        // std::string password;
        // std::cin >> password;
        break;
    case 3:
        system("clear");
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "感谢您的使用, 再见!" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        break;
    default:
        system("clear");
        throw std::runtime_error("无效输入, 请重新输入!");
        handleInvalidInput("无效输入, 请重新输入!");
        break;
    }
    }
    catch (const std::runtime_error &err) {
        handleInvalidInput(err.what());
    }
}