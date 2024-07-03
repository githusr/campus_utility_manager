#include "tui/interaction.h"
#include "tui/menu_item.h"
#include <cstdio>
#include <iostream>
#include <memory>
#include <stack>

extern bool isWaitingForKey;
extern bool isLogin;
extern bool login_status;

void navigateMenu(const std::shared_ptr<MenuItem> &main_menu)
{
    std::stack<std::shared_ptr<MenuItem>> menu_stack;

    menu_stack.push(main_menu);

    while (!menu_stack.empty()) {
        auto current_menu = menu_stack.top();

        if (current_menu->sub_items.empty() && current_menu->action) {
            current_menu->printMenu();
            current_menu->action();
            if (isWaitingForKey) {
                isWaitingForKey = false;
            } else {
                waitForKey();
                clearScreen();
            }
            menu_stack.pop();

        } else if (!current_menu->sub_items.empty() && !current_menu->action) {
            current_menu->printMenu();
            puts("  0. 返回");
            puts("------------------------------------------");
            std::cout << "请选择: ";
            size_t choice;
            while (true) {
                std::cin >> choice;
                if (std::cin.fail()) {
                    std::cin.clear();
                    clearScreen();
                    std::cerr << "无效输入! 请重新选择." << std::endl;
                    waitForKey();
                    clearScreen();
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
            } else if (choice > 0 && choice <= current_menu->sub_items.size()) {
                auto selected_menu = current_menu->sub_items[choice - 1];
                clearScreen();
                menu_stack.push(selected_menu);
            } else {
                clearScreen();
                std::cerr << "无效输入! 请重新选择." << std::endl;
                waitForKey();
                clearScreen();
            }

        } else if (!current_menu->sub_items.empty() && current_menu->action) {

            current_menu->action();
            if (isLogin) {
                if (!login_status) {
                    waitForKey();
                    clearScreen();
                }
                current_menu->printMenu();
                puts("  0. 返回");
                puts("------------------------------------------");
                std::cout << "请选择: ";
                size_t choice;
                while (true) {
                    std::cin >> choice;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        clearScreen();
                        std::cerr << "无效输入! 请重新选择." << std::endl;
                        waitForKey();
                        clearScreen();
                        current_menu->printMenu();
                        puts("  0. 返回");
                        puts("------------------------------------------");
                        std::cout << "请选择: ";
                    } else {
                        break;
                    }
                }
                if (choice == 0) {
                    login_status = false;
                    menu_stack.pop();
                    clearScreen();
                } else if (choice > 0 && choice <= current_menu->sub_items.size()) {
                    login_status = true;
                    auto selected_menu = current_menu->sub_items[choice - 1];
                    clearScreen();
                    menu_stack.push(selected_menu);
                } else {
                    std::cerr << "无效输入! 请重新选择." << std::endl;
                    waitForKey();
                    clearScreen();
                }
            } else {
                menu_stack.pop();
            }
        }
    }
}
