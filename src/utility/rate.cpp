#include "utility/rate.h"
#include <iostream>

std::istream &operator>>(std::istream &is, Rate &rate)
{
    double free_quota;
    double unit_price;
    is >> free_quota >> unit_price;

    if (rate.free_quota < 0 || rate.unit_price < 0) {
        throw std::runtime_error("免费额度和单价不能为负数，请重新输入");
        return is;
    }

    rate.free_quota = free_quota;
    rate.unit_price = unit_price;

    return is;
}

void Rate::setFromUser()
{
    std::cout << "当前的免费额度和单价为: " << free_quota << " " << unit_price << std::endl;
    std::cout << "请输入新的免费额度和单价（用空格分隔）:";
    std::cin >> *this;
}

Rate::Rate(double free_quota, double unit_price) : free_quota(free_quota), unit_price(unit_price) {}