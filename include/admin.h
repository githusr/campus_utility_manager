#ifndef ADMIN_H
#define ADMIN_H

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

#endif