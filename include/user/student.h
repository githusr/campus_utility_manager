#ifndef STUDENT_H
#define STUDENT_H

#include "admin.h"
#include "user.h"
#include "utility/utility_data.h"

class Student : public User
{
    friend class Admin;
public:
    Student(std::string id, std::string name);

private:
    static std::array<Rate, TOTAL> rate;
};

#endif