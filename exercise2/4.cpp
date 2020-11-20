#include <iostream>

int main()
{
    int tmp = 10;
    for (int n = 2; n < 1000; ++n) { // 易知 1000 不是自守数
        if (n == 10) {
            tmp = 100;
        }
        if (n == 100) {
            tmp = 1000;
        }
        if (n*(n - 1) % tmp == 0) {            
            std::cout << n << std::endl;
        }
    }
    return 0;
}
