// #include "tui/handle_invalid_input.h"
#include <iostream>
#include <stdexcept>

void handleInvalidInput(const std::runtime_error &error_message)
{
    std::cout << error_message.what() << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Press Enter to continue...";
    char tmp;
    do {
        scanf("%c", &tmp);
    } while (tmp != '\n');
    getchar();
}