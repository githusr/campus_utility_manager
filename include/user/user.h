#ifndef USER_H
#define USER_H

#include "utility/rate.h"
#include "utility/utility_data.h"
#include "utility/utility_type.h"
#include <array>
#include <istream>
#include <string>
#include "user/user_type.h"
class User
{
    friend std::istream &operator>>(std::istream &is, User &user);
    friend std::ostream &operator<<(std::ostream &os, const User &user);
public:
    virtual std::istream &read(std::istream &is) = 0;
    virtual std::ostream &print(std::ostream &os) const = 0;
    virtual void showTitleForHistory() = 0;
    virtual void showTitleForUserInfo() = 0;

public:
    static void setRate(UserType user_type, UtilityType utility_type);

public:
    const std::string &getId() const;
    const std::string &getName() const;
    const UtilityData &getUtilityData(UtilityType utility_type) const;

public:
    void addUtilityDataFromUser(UserType user_type, UtilityType utility_type);
    void addUtilityDataFromFile(UserType user_type, UtilityType utility_type, std::ifstream &file_name);
    void pay(UtilityType utility_type);

public:
    void showHistory(std::ostream &os) const;
    virtual void showUserInfo(std::ostream &os) const = 0;

public:
    User() = default;
    User(std::string id, std::string name);
    virtual ~User() = default;

protected:
    std::string id;
    std::string name;
    std::array<UtilityData, UTILITY_TYPE_TOTAL> utility;
    static std::array<std::array<Rate, UTILITY_TYPE_TOTAL>, USER_TYPE_TOTAL> rate;
};

#endif