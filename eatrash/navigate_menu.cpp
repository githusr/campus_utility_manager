#include "tui/interaction.h"
#include "tui/menu_item.h"
#include <cstdio>
#include <iostream>
#include <memory>
#include <stack>

extern bool isWaitingForKey;

std::stack<std::shared_ptr<MenuItem>> menu_stack;

void navigateMenu(const std::shared_ptr<MenuItem> &main_menu)
{
    menu_stack.push(main_menu);

    while (!menu_stack.empty()) {
        auto current_menu = menu_stack.top();
        current_menu->printMenu();
        if (!current_menu->sub_items.empty()) {
            puts("  0. 返回");
            puts("------------------------------------------");
            std::cout << "请选择: ";
        }

        size_t choice;
        while (true) {
            std::cin >> choice;
            if (std::cin.fail()) {
                std::cin.clear();
                outputError("无效输入! 请重新选择.");
                current_menu->printMenu();
                puts("  0. 返回");
                puts("------------------------------------------");
                std::cout << "请选择: ";
            } else {
                break;
            }
        }

        if (choice == 0) {
            menu_stack.pop();
            clearScreen();
            // if (menu_stack.empty()) {
            //     break;
            // }
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
            outputError("无效输入! 请重新选择.");
        }
    }
}