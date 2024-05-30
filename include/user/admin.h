#ifndef ADMIN_H
#define ADMIN_H

#include <string>
class Admin
{
public:
    Admin();
    void resetPassword();
    void addUtilityData();
    void removeUtilityData();
    void updateUtilityData();
    void viewUtilityData();
    void addRate();
    void removeRate();
    void updateRate();
    void viewRate();

private:
    std::string password;
};

#endif