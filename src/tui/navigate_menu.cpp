#include "tui/interaction.h"
#include "tui/menu_item.h"
#include <cstdio>
#include <iostream>
#include <memory>
#include <stack>
#include <stdexcept>

extern bool isWaitingForKey;

void navigateMenu(const std::shared_ptr<MenuItem>& mainMenu)
{
    std::stack<std::shared_ptr<MenuItem>> menu_stack;
    menu_stack.push(mainMenu);

    while (!menu_stack.empty()) {
        auto current_menu = menu_stack.top();
        current_menu->printMenu();

        puts("  0. 返回");
        puts("------------------------------------------");
        std::cout << "请选择: ";

        size_t choice;
        std::cin >> choice;

        if (choice == 0) {
            menu_stack.pop();
            if (menu_stack.empty()) {
                break;
            }
        } else if (choice > 0 && choice <= current_menu->sub_items.size()) {
            auto selected_menu = current_menu->sub_items[choice - 1];
            clearScreen();
            if (selected_menu->action) {
                selected_menu->action();
                if (selected_menu->sub_items.empty()) {
                    if (isWaitingForKey) {
                        isWaitingForKey = false;
                    } else {
                        waitForKey();
                    }
                    clearScreen();
                } else {
                    menu_stack.push(selected_menu);
                }
            } else {
                menu_stack.push(selected_menu);
                clearScreen();
            }
        } else {
            throw std::runtime_error("无效输入! 请重新选择.");
        }
    }
}