#include <iostream>
int main(int argC, char *argV[12])
{
    std::cout << " Длина Массива: " << argC;
    for (int i = 0; i < argC; i++)
    {
        std::cout << "Аргумент " << i << ": " << argV[i];
    }
}