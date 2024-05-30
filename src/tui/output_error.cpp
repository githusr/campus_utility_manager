#include "tui/output_error.h"
#include <iostream>

void outputError(const std::runtime_error &error_message)
{
    std::cerr << error_message.what() << std::endl;
    waitForKey();
}