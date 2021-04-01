#include <iostream>
#include <list>

using namespace std;

typedef list<int> Stack;

int main()
{
    Stack s;
    int n;
    while (true) {
        cin >> n;
        if (n == -1) {
            break;
        }
        s.push_back(n);
    }
    for (auto i = s.rbegin(); i != s.rend(); i++) {
        cout << *i << " ";
    }
    return 0;
}