#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"
#include <fstream>
#include <istream>

class Student : public User
{
public:
    Student(std::string id, std::string name, int grade);

private:
    int grade;
};

#endif