#ifndef FACULTY_H
#define FACULTY_H

#include "user.h"
#include <istream>

class Faculty : public User
{
public:
    void showTitleForHistory() override;
    void showTitleForUserInfo() override;

public:
    void showUserInfo(std::ostream &os) const override;

public:
    Faculty() = default;
    Faculty(std::string id, std::string name);

private:
    std::istream &read(std::istream &is) override;
    std::ostream &print(std::ostream &os) const override;
};

#endif