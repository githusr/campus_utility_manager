#ifndef INTERACTION_H
#define INTERACTION_H

#include <string>

void clearScreen();

void waitForKey();

void showWelcome();

void outputError(const std::string &err);

void showGoodbye();

#endif