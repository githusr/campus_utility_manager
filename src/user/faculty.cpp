#include "user/faculty.h"
#include <iostream>

std::istream &Faculty::read(std::istream &is)
{
    is >> id >> name;
    return is;
}

std::ostream &Faculty::print(std::ostream &os) const
{
    os << id << "\t" << name << "\t";
    return os;
}

void Faculty::showTitleForHistory()
{
    std::cout << "编号\t\t姓名\n";
    puts("----------------------------");
}

void Faculty::showTitleForUserInfo()
{
    std::cout << "编号\t\t姓名\t应缴水费\t应缴电费\t应缴气费\n";
    puts("----------------------------");
}

void Faculty::showUserInfo(std::ostream &os) const
{
    print(os);
    for (int i = 0; i != UTILITY_TYPE_TOTAL; ++i) {
        os << utility[i].getFeeToPay() << "\t\t";
    }
    os << std::endl;
}

Faculty::Faculty(std::string id, std::string name) : User(std::move(id), std::move(name)) {}