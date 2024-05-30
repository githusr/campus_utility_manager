#ifndef USER_H
#define USER_H

#include "system/user_data_manager.h"
#include "utility/utility_data.h"
#include "utility/utility_type.h"
#include <array>
#include <string>
class User
{
friend void UserDataManager<User>::sortDataByFee(UtilityType utility_type);

public:
    User(std::string id, std::string name);
    void getId() const;
    void getName() const;

protected:
    std::string id;
    std::string name;
    std::array<UtilityData, UTILITY_TYPE_TOTAL> utility;
};

#endif