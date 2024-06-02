#ifndef MENU_COMPONENT_H
#define MENU_COMPONENT_H

#include <string>
class MenuComponent 
{
public:
    MenuComponent(const std::string &name);

    virtual void execute() = 0;
    virtual std::string getName() const;

    virtual ~MenuComponent() = default;

private:
    std::string name;
};

#endif