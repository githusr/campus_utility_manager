#include "tui/interaction.h"
#include "tui/menu_build.h"
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <menu.h>
#include <stdexcept>
#include "tui/menu_item.h"
#include "tui/navigate_menu.h"

extern std::shared_ptr<MenuItem> main_menu;

int main(int argc, char *argv[])
{
    showWelcome();

    menuBuild();

    try {
        navigateMenu(main_menu);
    } catch (const std::runtime_error &err) {
        outputError(err);
    }
    showGoodbye();

    return EXIT_SUCCESS;
}