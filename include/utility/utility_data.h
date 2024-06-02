#ifndef UTILITY_DATA_H
#define UTILITY_DATA_H

#include "utility/rate.h"
#include <fstream>
#include <istream>
#include <string>
#include <utility>
#include <vector>
class UtilityData
{
    friend std::istream &operator>>(std::istream &is, UtilityData &utility_data);
    friend std::ostream &operator<<(std::ostream &os, const UtilityData &utility_data);

public:
    bool operator<(const UtilityData &utility_data) const;

public:
    void addFromUser(Rate rate);
    void addFromFile(const Rate &rate, std::ifstream &file_name);
    void pay();

public:
    UtilityData();

public:
    double getFeeToPay() const;

private:
    std::vector<std::pair<std::string, double>> utility_data;
    std::vector<std::pair<double, bool>> fee_data;
    double fee_to_pay;

private:
    void setFeeData(const Rate &rate);
    void calculateFeeToPay();
    void updateFeeData(const Rate &rate);
};

#endif