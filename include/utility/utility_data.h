#ifndef UTILITY_DATA_H
#define UTILITY_DATA_H

#include <string>
#include <utility>
#include <vector>
class UtilityData
{
public:
    UtilityData();

private:
    std::vector<std::pair<std::string, double>> utility_data;
    std::vector<std::pair<double, bool>> fee_data;
    double fee_to_pay;
    bool is_overdue;
};

#endif