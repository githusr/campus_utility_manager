#include <functional> // 用于存储菜单项动作的函数对象
#include <iostream>
#include <string>
#include <vector>
#include <stack>

class MenuItem
{
public:
    std::string name;
    std::function<void()> action; // 存储菜单项动作的函数对象
    std::vector<MenuItem *> subItems;

    MenuItem(const std::string &name, std::function<void()> action = nullptr) : name(name), action(action) {}

    void addSubItem(MenuItem *item) { subItems.push_back(item); }

    void printMenu() const
    {
        std::cout << name << std::endl;
        for (size_t i = 0; i < subItems.size(); ++i) {
            std::cout << "  " << i + 1 << ". " << subItems[i]->name << std::endl;
        }
    }

    void executeAction() const
    {
        if (action) {
            action();
        }
    }
};

void navigateMenu(MenuItem *currentMenu)
{
    std::stack<MenuItem *> menuStack;
    menuStack.push(currentMenu);

    while (!menuStack.empty()) {
        MenuItem *menu = menuStack.top();
        menu->printMenu();

        std::cout << "Enter number to select menu, 0 to go back: ";
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            menuStack.pop();
            if (menuStack.empty()) {
                std::cout << "Exiting menu." << std::endl;
                break;
            }
        } else if (choice > 0 && choice <= menu->subItems.size()) {
            MenuItem *selectedMenu = menu->subItems[choice - 1];
            if (selectedMenu->action) {
                selectedMenu->executeAction();
            } else {
                menuStack.push(selectedMenu);
            }
        } else {
            std::cout << "Invalid choice." << std::endl;
        }
    }
}

// 一些示例动作函数
void action1() { std::cout << "Action 1 executed." << std::endl; }

void action2() { std::cout << "Action 2 executed." << std::endl; }

int main() {
    MenuItem mainMenu("Main Menu");
    MenuItem fileMenu("File");
    MenuItem editMenu("Edit");
    MenuItem viewMenu("View");

    MenuItem newFile("New", action1);
    MenuItem openFile("Open", action2);
    MenuItem saveFile("Save");

    fileMenu.addSubItem(&newFile);
    fileMenu.addSubItem(&openFile);
    fileMenu.addSubItem(&saveFile);

    mainMenu.addSubItem(&fileMenu);
    mainMenu.addSubItem(&editMenu);
    mainMenu.addSubItem(&viewMenu);

    navigateMenu(&mainMenu);

    return 0;
}
