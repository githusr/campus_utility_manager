#ifndef UTILITY_DATA_H
#define UTILITY_DATA_H

#include <istream>
#include <string>
#include <utility>
#include <vector>
#include "utility/rate.h"
class UtilityData
{
    friend std::istream &operator>>(std::istream &is, UtilityData &utility_data);

public:
    void addFromUser();
    void setRateFromUser();
    void pay();

public:
    UtilityData();

private:
    std::vector<std::pair<std::string, double>> utility_data;
    static Rate rate;
    std::vector<std::pair<double, bool>> fee_data;
    double fee_to_pay;

private:
    void setFeeData();
    void calculateFeeToPay();
    void updateFeeData();
};

#endif