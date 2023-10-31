#include "Menu.h"
#include <iostream>

int main()
{
    try
    {
        Menu menu;
        menu.run();
    }
    catch (std::exception& e)
    {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
}
