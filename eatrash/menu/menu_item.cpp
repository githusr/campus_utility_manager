#include "tui/menu_item.h"

MenuItem::MenuItem(const std::string &name, void (*action)()) : MenuComponent(name), action(action) {}

void MenuItem::execute() { action(); }