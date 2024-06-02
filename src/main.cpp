#include "tui/interaction.h"
#include "tui/menu_build.h"
#include "tui/menu_item.h"
#include "tui/navigate_menu.h"
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <menu.h>

extern std::shared_ptr<MenuItem> main_menu;

int main(int argc, char *argv[])
{
    showWelcome();

    menuBuild();

    navigateMenu(main_menu);

    showGoodbye();

    return EXIT_SUCCESS;
}