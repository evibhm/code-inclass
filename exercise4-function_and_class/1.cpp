#include <iostream>

int getGcdCount(int a, int b)
{
    int count = 0;
    if (a < b) {
        int t = a;
        a = b;
        b = t;
    }
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
        ++count;
    }
    return count;
}

int main()
{
    int t, ma = 0, mb = 0, mcount = 0;
    std::cin >> t;
    while (t--) {
        int a, b;
        std::cin >> a >> b;
        int count = getGcdCount(a, b);
        if (count > mcount) {
            ma = a;
            mb = b;
            mcount = count;
        }
    }
    std::cout << mcount << std::endl;
    std::cout << ma << ' ' << mb << std::endl;
    return 0;
}