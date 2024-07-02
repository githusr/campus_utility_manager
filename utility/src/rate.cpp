#include "utility/rate.h"
#include "tui/interaction.h"
#include <iostream>

std::istream &operator>>(std::istream &is, Rate &rate)
{
    double free_quota;
    double unit_price;
    is >> free_quota >> unit_price;

    if (rate.free_quota < 0 || rate.unit_price < 0) {
        outputError("免费额度和单价不能为负数");
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

const double &Rate::getFreeQuota() const { return free_quota; }

const double &Rate::getUnitPrice() const { return unit_price; }

Rate::Rate(double free_quota, double unit_price) : free_quota(free_quota), unit_price(unit_price) {}