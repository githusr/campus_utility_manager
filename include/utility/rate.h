#ifndef RATE_H
#define RATE_H

#include <istream>
class Rate
{
    friend std::istream &operator>>(std::istream &is, Rate &rate);

public:
    void setFromUser();
    const double &getFreeQuota() const;
    const double &getUnitPrice() const;

public:
    Rate(double free_quota, double unit_price);

private:
    double free_quota;
    double unit_price;
};

#endif