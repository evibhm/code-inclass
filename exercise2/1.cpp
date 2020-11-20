#include <iostream>

int gcd(int a, int b) // 最大公约数
{
    return (b == 0)?a:gcd(b, a%b);
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << a * b / gcd(a, b);
    return 0;
}