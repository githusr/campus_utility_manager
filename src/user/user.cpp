#include "user/user.h"
#include <string>
#include <utility>

User::User(std::string id, std::string name) : id(std::move(id)), name(std::move(name)) {}