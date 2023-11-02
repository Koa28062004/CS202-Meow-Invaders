#include "Applications/Application.h"
#include <iostream>

int main()
{
    try
    {
        Application application;
        application.run();
    }
    catch (std::exception& exception)
    {
        std::cout << "\nEXCEPTION: " << exception.what() << std::endl;
    }
}
