#include "tui/action.h"
#include "admin.h"
#include "system/user_data_manager.h"
#include "tui/interaction.h"
#include "user/faculty.h"
#include "user/student.h"
#include <cstdio>
#include <iostream>
#include <string>

UserDataManager<Student> student_manager;
UserDataManager<Faculty> faculty_manager;

void adminLogin()
{
    Admin admin("admin");
    std::cout << "请输入管理员密码: ";
    std::string password;
    std::cin >> password;
    if (password == admin.getPassword()) {
        clearScreen();
        std::cout << "登录成功" << std::endl;
        waitForKey();
    } else {
        throw std::runtime_error("密码错误");
    }
}

void queryStudentBill() {}