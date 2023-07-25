#include <iostream>

__declspec(dllexport) void Hey()
{
    std::cout << "Hey!" << std::endl;
}