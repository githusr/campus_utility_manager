#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"
#include <fstream>
#include <istream>

class Student : public User
{
    friend std::istream &operator>>(std::istream &is, Student &student);
    friend std::ostream &operator<<(std::ostream &os, const Student &student);
public:
    static void showTitleForHistory(); 
    static void showTitleForUserInfo();
    
public:
    Student(std::string id, std::string name, int grade);

private:
    int grade;
};

#endif