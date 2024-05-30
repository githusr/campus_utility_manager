#ifndef ADMIN_H
#define ADMIN_H

#include <string>
class Admin
{
public:
    Admin(const char *password);
    void setPassword();

private:
    std::string password;
};

#endif