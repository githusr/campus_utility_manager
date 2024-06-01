#ifndef USER_H
#define USER_H

#include "utility/utility_data.h"
#include "utility/utility_type.h"
#include <array>
#include <string>
class User
{
public:
    static void setRate(const auto &utility_type);
public:
    const auto &getId() const;
    const auto &getName() const;
    auto &getUtilityData(auto &utility_type) const;

public:
    void addUtilityDataFromUser(const auto &utility_type);
    void addUtilityDataFromFile(const auto &utility_type, std::ifstream &file_name);
    void pay(const auto &utility_type);

public:
    void showHistory(std::ostream &os) const;
    void showUserInfo(std::ostream &os) const;

public:
    

public:
    User(std::string id, std::string name);

protected:
    std::string id;
    std::string name;
    std::array<UtilityData, UTILITY_TYPE_TOTAL> utility;
    static std::array<Rate, UTILITY_TYPE_TOTAL> rate;
};

#endif