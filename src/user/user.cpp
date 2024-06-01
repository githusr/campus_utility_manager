#include "user/user.h"
#include "system/user_data_manager.h"
#include "utility/utility_type.h"
#include <array>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>

void User::setRate(const auto &utility_type) { rate[utility_type].setFromUser(); }

const auto &User::getId() const { return id; }

const auto &User::getName() const { return name; }

auto &User::getUtilityData(auto &utility_type) const { return utility[utility_type]; }

void User::addUtilityDataFromUser(const auto &utility_type)
{
    utility[utility_type].addFromUser(rate[utility_type]);
}

void User::addUtilityDataFromFile(const auto &utility_type, std::ifstream &file_name)
{
    utility[utility_type].addFromFile(rate[utility_type], file_name);
}

void User::pay(const auto &utility_type) { utility[utility_type].pay(); }

void User::showHistory(std::ostream &os) const
{
    std::string utility_type[UTILITY_TYPE_TOTAL] = {"water", "electricity", "gas"};
    for (int i = 0; i != UTILITY_TYPE_TOTAL; ++i) {
        os << utility_type[i] << ":\n";
        os << utility[i];
    }
}

User::User(std::string id, std::string name) : id(std::move(id)), name(std::move(name)) {}