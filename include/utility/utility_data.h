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
};

#endif