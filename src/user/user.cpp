#include "user/user.h"
#include <string>
#include <utility>

const auto &User::getId() const { return id; }
const auto &User::getName() const { return name; }
const auto &User::getUtilityData(auto &utility_type) const { return utility[utility_type]; }
User::User(std::string id, std::string name) : id(std::move(id)), name(std::move(name)) {}