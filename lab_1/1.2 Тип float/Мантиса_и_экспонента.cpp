#include <iostream>
#include <bitset>
#include <cstring>

#include <windows.h>

union FloatBits
{
    float f;
    uint32_t i;
};

void printFloatBits(float num)
{
    FloatBits fb;
    fb.f = num;

    std::bitset<32> bits(fb.i);
    std::cout << "Число: " << num << std::endl;
    std::cout << "Двоичное представление: " << bits << std::endl;
    std::cout << "Знак: " << bits[31] << std::endl;
    std::cout << "Экспонента: " << bits.to_string().substr(1, 8) << std::endl;
    std::cout << "Мантисса: " << bits.to_string().substr(9, 23) << std::endl;
}

int main()
{
    SetConsoleOutputCP(65001); // Устанавливаем кодировку UTF-8 для вывода
    SetConsoleCP(65001);       // Устанавливаем кодировку UTF-8 для ввода

    float numbers[] = {1.0f, -1.0f, 3.14f, 0.1f, 2.25f, 8388608.0f, 8388609.0f, 16777216.0f};

    for (float num : numbers)
    {
        printFloatBits(num);
        std::cout << std::endl;
    }

    return 0;
}
