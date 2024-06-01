#include "user/student.h"
#include "system/student_manager.h"
#include "utility/utility_type.h"
#include <cstdio>
#include <iostream>
#include <istream>

std::istream &operator>>(std::istream &is, Student &student)
{
    is >> student.id >> student.name >> student.grade;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Student &student)
{
    os << student.id << "\t" << student.name << "\t" << student.grade << "\t";
    return os;
}

void Student::showTitleForHistory()
{
    std::cout << "编号\t姓名\t年级\n";
    puts("----------------------------");
}

Student::Student(std::string id, std::string name, int grade) : User(std::move(id), std::move(name)), grade(grade) {}