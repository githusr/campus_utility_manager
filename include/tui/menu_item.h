#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <memory>
#include <string>
#include <vector>

class MenuItem
{
public:
    MenuItem(std::string name, void (*action)() = nullptr);

public:
    void addSubItem(std::shared_ptr<MenuItem> sub_item);
    void printMenu() const;

public:
    std::string name;
    void (*action)();
    std::vector<std::shared_ptr<MenuItem>> sub_items;
};

#endif