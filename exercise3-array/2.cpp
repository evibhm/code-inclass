#include <iostream>
#include <list>

int main()
{
    std::list<int> lst = {1, 4, 9, 16, 9, 7, 4, 9, 11};
    for (auto i = lst.cbegin(); i != lst.cend(); ++i) {
        auto j = i;
        ++j;
        while (j != lst.cend()) {
            if (*j == *i) {
                auto tmp = j;
                ++j;
                lst.erase(tmp);
            } else {
                ++j;
            }
        }
    }
    for (const auto &i : lst) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    return 0;
}