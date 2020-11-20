#include <iostream>
#include <string>
using std::string;

int main()
{
    int a; // 菱形边长
    string s;
    std::cin >> a;
    for (int i = 1; i <= a; ++i) {
        for (int j = 0; j < a - i; ++j) {
            s += ' '; 
        }
        for (int j = 0; j < 2 * i - 1; ++j) {
            s += '*';
        }
        s += '\n';
    }
    for (int i = a - 1; i >= 1; --i) {
        for (int j = 0; j < a - i; ++j) {
            s += ' '; 
        }
        for (int j = 0; j < 2 * i - 1; ++j) {
            s += '*';
        }
        s += '\n';
    }
    std::cout << s;
    return 0;
}