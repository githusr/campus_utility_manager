#include "user/student.h"
#include "utility/utility_type.h"
#include <cstdio>
#include <iostream>
#include <istream>

std::istream &Student::read(std::istream &is)
{
    is >> id >> name >> grade;
    return is;
}
std::ostream &Student::print(std::ostream &os) const
{
    os << id << "\t" << name << "\t" << grade << "\t";
    return os;
};

void Student::showTitleForHistory()
{
    std::cout << "编号\t姓名\t年级\n";
    puts("----------------------------");
}

void Student::showTitleForUserInfo()
{
    std::cout << "编号\t姓名\t年级\t应缴水费\t应缴电费\t应缴气费\n";
    puts("----------------------------");
}

void Student::showUserInfo(std::ostream &os) const
{
    print(os);
    for (int i = 0; i != UTILITY_TYPE_TOTAL; ++i) {
        os << utility[i].getFeeToPay() << "\t";
    }
    os << std::endl;
}

Student::Student(std::string id, std::string name, int grade)
    : User(std::move(id), std::move(name)), grade(grade)
{
}