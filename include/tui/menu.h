#ifndef MENU_H
#define MENU_H

#include "tui/menu_component.h"
#include <memory>
#include <vector>
class Menu : public MenuComponent
{
public:
    Menu(const std::string &name);

    void execute() override;
    void add(auto item);

private:
    std::vector<std::unique_ptr<MenuComponent>> items;
};

#endif