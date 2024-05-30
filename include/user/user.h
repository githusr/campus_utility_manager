#ifndef USER_H
#define USER_H

#include "utility/rate.h"
#include "utility/utility_data.h"
#include "utility/utility_type.h"
#include <array>
#include <string>
class User
{
public:
    User(std::string id, std::string name);

protected:
    std::string id;
    std::string name;
    std::array<UtilityData, TOTAL> utility;
};

#endif