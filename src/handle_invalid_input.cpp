#include "handle_invalid_input.h"
#include <iostream>

void handleInvalidInput(const char *error_message)
{
    std::cout << error_message << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Press Enter to continue...";
    char tmp;
    do {
        scanf("%c", &tmp);
    } while (tmp != '\n');
    getchar();
}