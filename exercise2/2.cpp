#include <iostream>

int main()
{
    int n;
    bool b[40] = {}; // sizeof(int) = 8 bytes = 32 bits < 40 bits
    std::cin >> n;
    for (int i = 0; i < 32; ++i) {
        b[i] = (n >> i)&1;
    }
    int ans = 31;
    while(true) {
        if (b[ans]) {
            for (int i = ans; i >= 0; --i) {
                std::cout << b[i];
            }
            break;
        }
        --ans;
    }
    return 0;
}