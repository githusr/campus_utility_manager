#ifndef ADMIN_H
#define ADMIN_H

#include "user/faculty.h"
#include "student.h"
#include <string>
#include <vector>
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
    std::vector<Student> student;
    std::vector<Faculty> faculty;
};

#endif