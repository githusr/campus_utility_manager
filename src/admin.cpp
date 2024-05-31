#include "admin.h"

Admin::Admin(std::string password) : password(std::move(password)) {}

void Admin::setPassword(std::string password) { this->password = std::move(password); }

const std::string &Admin::getPassword() const { return password; }