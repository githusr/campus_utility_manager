#ifndef USER_H
#define USER_H

#include "utility/utility_data.h"
#include "utility/utility_type.h"
#include <array>
#include <string>
class User
{
public:
    const auto &getId() const;
    const auto &getName() const;
    const auto &getUtilityData(auto &utility_type) const;

public:
    User(std::string id, std::string name);

protected:
    std::string id;
    std::string name;
    std::array<UtilityData, UTILITY_TYPE_TOTAL> utility;
};

#endif