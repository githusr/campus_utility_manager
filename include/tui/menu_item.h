#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include "tui/menu_component.h"
#include <string>
class MenuItem : public MenuComponent
{
public:
    MenuItem(const std::string &name, void (*action)());
    void execute() override;

private:
    void (*action)();
};

#endif