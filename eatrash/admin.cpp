#include "admin.h"
#include <iostream>

Admin::Admin(const char *password) : password(password) {}

void Admin::setPassword()
{
    std::string new_password;
    std::cout << "请输入新密码: ";
    std::cin >> new_password;
    password = new_password;
    std::cout << "密码修改成功" << std::endl;
}