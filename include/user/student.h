#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"
#include "utility/utility_data.h"
#include "utility/utility_type.h"

class Student : public User
{
    friend class Admin;
public:
    Student(std::string id, std::string name);

private:
    static std::array<Rate, UTILITY_TYPE_TOTAL> rate;
};

#endif