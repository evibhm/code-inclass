#include <iostream>
#include <vector>

bool isPrime(int num)
{
    for (int i = 2;i * i <= num; ++i) {
        if(num % i == 0)
            return false;
    }
    return true;
}

int main(){
    std::vector<int> arr = {5, 7, 11};
    int palindrome;
    for (int d1 = 1; d1 < 10; d1+=2) {
        for (int d2 = 0; d2 < 10; ++d2) {
            palindrome = 101*d1 + 10*d2;
            if (isPrime(palindrome)) {
                arr.push_back(palindrome);
            }
        }
    }
    for (int d1 = 1; d1 < 10; d1+=2) {
        for (int d2 = 0; d2 < 10; ++d2) {
            for (int d3 = 0; d3 < 10; ++d3) {
                palindrome = 10001*d1 + 1010*d2 +100*d3;
                if (isPrime(palindrome)) {
                    arr.push_back(palindrome);
                }
            }
        }
    }
    for (int d1 = 1; d1 < 10; d1+=2) {
        for (int d2 = 0; d2 < 10; ++d2) {
            for (int d3 = 0; d3 < 10; ++d3) {
                for (int d4 = 0; d4 < 10; ++d4){
                    palindrome = 1000001*d1 + 100010*d2 + 10100*d3 + 1000*d4;
                    if (isPrime(palindrome)) {
                        arr.push_back(palindrome);
                    }
                }
            }
        }
    }

    int min, max;
    std::cin >> min >> max;
    for (const auto &i : arr) {
        if (i >= min && i <= max) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}