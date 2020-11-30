#include <iostream>
#include <array>
#include <ctime>
#include <cstdio>

int main()
{
    std::array<int, 10> arr;
    srand((unsigned)time(nullptr));
    for (int i = 0; i < 10; ++i) {
        arr[i] = rand();
    }
    for (int i = 0; i < 10; i += 2) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
    for (const auto &eachn : arr) {
        if (!(eachn&1)) {
            std::cout << eachn << ' ';
        }
    }
    std::cout << std::endl;
    for (int i = 9; i >= 0; --i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
    std::cout << arr.front() << ' ' << arr.back() << std::endl;
    return 0;
}