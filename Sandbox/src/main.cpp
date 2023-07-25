#include <iostream>

__declspec(dllimport) void Hey();

int main(int argc, char** argv)
{
    std::cout << "Burger!" << std::endl;
    Hey();
    std::cin.get();
}