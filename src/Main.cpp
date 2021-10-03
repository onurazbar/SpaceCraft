/*
 *
 * @file Main.cpp
 * @brief This file contains the main function of the space craft game.
 *
 */

#include <iostream>

int main()
{
    try
    {
        std::cout << "Space Craft game!" << std::endl;
    }
    catch (const char* ex)
    {
        std::cerr << ex << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Exception occured!" << std::endl;
    }
    
    return 0;
}
