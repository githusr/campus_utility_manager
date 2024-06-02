#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"
#include <istream>

class Student : public User
{
public:
    void showTitleForHistory() override; 
    void showTitleForUserInfo() override;

public:
    void showUserInfo(std::ostream &os) const override;
    
public:
    Student() = default;
    Student(std::string id, std::string name, int grade);

private:
    int grade;

private:
    std::istream &read(std::istream &is) override;
    std::ostream &print(std::ostream &os) const override;
};

#endif