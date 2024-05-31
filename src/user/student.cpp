#include "user/student.h"
#include "system/student_manager.h"
#include "utility/utility_type.h"
#include <iostream>
#include <istream>

std::istream &operator>>(std::istream &is, Student &student)
{
    std::cout << "请输入学生编号: ";
    is >> student.id;
    std::cout << "请输入学生姓名: ";
    is >> student.name;
    std::cout << "请输入学生年级: ";
    is >> student.grade;
    std::cout << "请输入类型 (water, electricity, gas): ";
    std::string type;
    is >> type;

    if (type == "water") {
        is >> student.utility[WATER];
    } else if (type == "electricity") {
        is >> student.utility[ELECTRICITY];
    } else if (type == "gas") {
        is >> student.utility[GAS];
    } else {
        throw std::runtime_error("未知类型");
        return is;
    }

    return is;
}