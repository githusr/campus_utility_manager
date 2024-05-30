#ifndef FACULTY_H
#define FACULTY_H

#include "user.h"
class Faculty : public User
{
    friend class Admin;
};

#endif