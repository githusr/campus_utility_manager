#include "tui/menu_item.h"
#include <iostream>
#include <memory>
#include <string>

MenuItem::MenuItem(std::string name, void (*action)()) : name(std::move(name)), action(action) {}

void MenuItem::addSubItem(std::shared_ptr<MenuItem> sub_item) { sub_items.emplace_back(sub_item); }

void MenuItem::printMenu() const
{
    std::cout << "-----" << name << "-----" << std::endl;
    for (size_t i = 0; i != sub_items.size(); ++i) {
        std::cout << "  " << i + 1 << ". " << sub_items[i]->name << std::endl;
    }
}
