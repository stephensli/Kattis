#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char* argv[])
{
    int amount, width, height;
    std::cin >> amount >> width >> height;

    for (int i = 0; i < amount; ++i)
    {
        int length;
        std::cin >> length;

        if (length <= width || length <= height || length <= std::sqrt(std::pow(width, 2) + std::pow(height, 2)))
        {
            std::cout << "DA" << std::endl;
        } else
        {
            std::cout << "NE" << std::endl;
        }
    }
}
