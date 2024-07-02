#include "user/user.h"
#include "utility/rate.h"
#include "utility/utility_data.h"
#include "utility/utility_type.h"
#include <array>
#include <cstdio>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <utility>

void User::setRate(UserType user_type, UtilityType utility_type)
{
    rate[user_type][utility_type].setFromUser();
}

const std::string &User::getId() const { return id; }

const std::string &User::getName() const { return name; }

const UtilityData &User::getUtilityData(UtilityType utility_type) const { return utility[utility_type]; }

void User::addUtilityDataFromUser(UserType user_type, UtilityType utility_type)
{
    utility[utility_type].addFromUser(rate[user_type][utility_type]);
}

void User::addUtilityDataFromFile(UserType user_type, UtilityType utility_type, std::ifstream &file_name)
{
    utility[utility_type].addFromFile(rate[user_type][utility_type], file_name);
}

void User::pay(UtilityType utility_type) { utility[utility_type].pay(); }

void User::showHistory(std::ostream &os) const
{
    std::string utility_type[UTILITY_TYPE_TOTAL] = {"water", "electricity", "gas"};
    for (int i = 0; i != UTILITY_TYPE_TOTAL; ++i) {
        os << utility_type[i] << ":\n";
        os << utility[i];
    }
}

User::User(std::string id, std::string name) : id(std::move(id)), name(std::move(name)) {}

std::istream &operator>>(std::istream &is, User &user) { return user.read(is); }

std::ostream &operator<<(std::ostream &os, const User &user) { return user.print(os); }

std::array<std::array<Rate, UTILITY_TYPE_TOTAL>, USER_TYPE_TOTAL> User::rate = {};