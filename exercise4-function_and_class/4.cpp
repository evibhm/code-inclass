#include <iostream>
#include <string>

int main()
{
    int n;
    std::string buf;
    std::cin >> n;
    for (int i = 0; i < (1<<n); ++i) {
        for (int j = 0; j < (1<<n); ++j) {
            if (((i|j) != (((1<<n)-1)) ? 0 : 1)) {
                buf += "1 ";
            } else {
                buf += "0 ";
            }
        }
        buf += '\n';
    }
    std::cout << buf;
    return 0;
}