#include "tui/menu_component.h"
#include <string>

MenuComponent::MenuComponent(const std::string &name) : name(name) {}

std::string MenuComponent::getName() const { return name; }