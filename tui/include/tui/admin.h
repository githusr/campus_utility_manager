#pragma once

#include <string>

class Admin
{
public:
    void setPassword(std::string password);
    const std::string &getPassword() const;

public:
    Admin(std::string password);

private:
    std::string password;
};
