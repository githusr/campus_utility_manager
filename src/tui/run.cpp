#include "tui/run.h"
#include <cstdio>
#include <cstdlib>


void run()
{
    while (true)
    {
        showMainMenu();
        char choice;
        do
        {
            scanf("%c", &choice);
        } while (choice < '1' || choice > '3');
        getchar();
        switch (choice)
        {
        case '1':
            showBillQueryMenu();
            break;
        case '2':
            showAdminLoginMenu();
            break;
        case '3':
            return;
        }
        waitForKey();
    }

    
}


void showBillQueryMenu() { clearScreen(); }