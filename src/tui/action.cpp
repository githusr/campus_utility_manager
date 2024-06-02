#include "tui/action.h"
#include "admin.h"
#include "system/user_data_manager.h"
#include "tui/interaction.h"
#include "user/faculty.h"
#include "user/student.h"
#include "user/user_type.h"
#include "utility/utility_type.h"
#include <cstdio>
#include <functional>
#include <iostream>
#include <memory>
#include <string>

UserDataManager student_manager("../data/student_input.txt", "../data/student_output.txt");
UserDataManager faculty_manager("../data/faculty_input.txt", "../data/faculty_output.txt");

Admin admin("admin");

bool isLogin = false;

void adminLogin()
{
    std::cout << "请输入管理员密码: ";
    std::string password;
    std::cin >> password;
    if (password == admin.getPassword()) {
        isLogin = true;
        std::cout << "登录成功" << std::endl;
    } else {
        isLogin = false;
        outputError("密码错误");
    }
}

void queryStudentBill()
{
    puts("请输入学生编号和姓名(用空格隔开): ");
    std::string id, name;
    std::cin >> id >> name;
    student_manager.searchDataByUser(id, name);
}
void queryFacultyBill()
{
    puts("请输入教工编号和姓名(用空格隔开): ");
    std::string id, name;
    std::cin >> id >> name;
    faculty_manager.searchDataByUser(id, name);
}

void resetPassword()
{
    std::string new_password;
    std::cout << "请输入新密码: ";
    std::cin >> new_password;
    admin.setPassword(new_password);
}

void payBillStudent()
{
    std::cout << "请输入用户编号: ";
    std::string id;
    std::cin >> id;
    std::cout << "请输入缴费项目(water/electricity/gas): ";
    std::string utility_type;
    std::cin >> utility_type;
    student_manager.pay(id, utility_type);
}

void payBillFaculty()
{
    std::cout << "请输入用户编号: ";
    std::string id;
    std::cin >> id;
    std::cout << "请输入缴费项目(water/electricity/gas): ";
    std::string utility_type;
    std::cin >> utility_type;
    faculty_manager.pay(id, utility_type);
}

void addDataStudent()
{
    std::cout << "请输入学生编号和数据类型(water/electricity/gas), 用空格隔开: " << std::endl;
    student_manager.addData(STUDENT);
}

void addDataFaculty()
{
    std::cout << "请输入教工编号和数据类型(water/electricity/gas), 用空格隔开: " << std::endl;
    faculty_manager.addData(FACULTY);
}

void addUserStudent()
{
    std::cout << "请依次输入学生编号、姓名、年级 (用空格隔开): " << std::endl;
    auto student = std::make_shared<Student>();
    student_manager.addUser(student);
}

void addUserFaculty()
{
    std::cout << "请依次输入教工编号、姓名 (用空格隔开): " << std::endl;
    auto faculty = std::make_shared<Faculty>();
    faculty_manager.addUser(faculty);
}

void removeUserStudent()
{
    std::cout << "请输入学生编号: ";
    student_manager.removeUser();
}

void removeUserFaculty()
{
    std::cout << "请输入教工编号: ";
    faculty_manager.removeUser();
}

void setRateStudent()
{
    std::cout << "请输入要设置的类型(water/electricity/gas): ";
    UtilityType utility_type;
    std::string str;
    std::cin >> str;
    if (str == "water") {
        utility_type = WATER;
    } else if (str == "electricity") {
        utility_type = ELECTRICITY;
    } else if (str == "gas") {
        utility_type = GAS;
    } else {
        outputError("未知的水电气类型");
        return;
    }
    Student::setRate(STUDENT, utility_type);
}

void setRateFaculty()
{
    std::cout << "请输入要设置的类型(water/electricity/gas): ";
    UtilityType utility_type;
    std::string str;
    std::cin >> str;
    if (str == "water") {
        utility_type = WATER;
    } else if (str == "electricity") {
        utility_type = ELECTRICITY;
    } else if (str == "gas") {
        utility_type = GAS;
    } else {
        outputError("未知的水电气类型");
        return;
    }
    Faculty::setRate(FACULTY, utility_type);
}

void billDetailStudent() { student_manager.outputData(); }

void billDetailFaculty() { faculty_manager.outputData(); }

void historyDataStudent() { student_manager.outputHistory(); }

void historyDataFaculty() { faculty_manager.outputHistory(); }

void processAndExportDataStudent()
{

    std::cout << "请按顺序输入您想进行的操作: " << std::endl;
    std::cout << "1. 按编号排序" << std::endl;
    std::function<void()> actions[]{
        [&] { student_manager.sortDataById(); },       [&] { student_manager.sortDataByName(); },
        [&] { student_manager.sortDataByWaterFee(); }, [&] { student_manager.sortDataByElectricityFee(); },
        [&] { student_manager.sortDataByGasFee(); },   [&] { student_manager.reverseData(); },
        [&] { student_manager.outputData(); },         [&] {student_manager.saveToFile(); }};
    std::string str;
    std::cin >> str;
    for (const char &c : str) {
        if (c < '0' || c > '8') {
            outputError("无效输入! 请重新选择.");
        } else {
            actions[c - '1']();
        }
    }
}

void processAndExportDataFaculty()
{

    std::cout << "请按顺序输入您想进行的操作: " << std::endl;
    std::cout << "1. 按编号排序" << std::endl;
    std::function<void()> actions[]{
        [&] { faculty_manager.sortDataById(); },       [&] { faculty_manager.sortDataByName(); },
        [&] { student_manager.sortDataByWaterFee(); }, [&] { faculty_manager.sortDataByElectricityFee(); },
        [&] { faculty_manager.sortDataByGasFee(); },   [&] { faculty_manager.reverseData(); },
        [&] { faculty_manager.outputData(); },         [&] {faculty_manager.saveToFile(); }};
    std::string str;
    std::cin >> str;
    for (const char &c : str) {
        if (c < '0' || c > '8') {
            outputError("无效输入! 请重新选择.");
        } else {
            actions[c - '1']();
        }
    }
}