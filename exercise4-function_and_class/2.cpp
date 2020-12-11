#include<iostream>

bool isPrime(int num)
{
    for (int i = 2;i * i <= num; ++i) {
        if(num % i == 0)
            return false;
    }
    return true;
}

int main(){
    int arr[800] = {5, 7, 11};
    int palindrome, ans = 2;
    for (int d1 = 1; d1 < 10; d1+=2) {
        for (int d2 = 0; d2 < 10; ++d2) {
            palindrome = 100*d1 + 10*d2 + d1;
            if (isPrime(palindrome)) {
                arr[++ans] = palindrome;
            }
        }
    }
    for (int d1 = 1; d1 < 10; d1+=2) {
        for (int d2 = 0; d2 < 10; ++d2) {
            for (int d3 = 0; d3 < 10; ++d3) {
                palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;
                if (isPrime(palindrome)) {
                    arr[++ans] = palindrome;
                }
            }
        }
    }
    for (int d1 = 1; d1 < 10; d1+=2) {
        for (int d2 = 0; d2 < 10; ++d2) {
            for (int d3 = 0; d3 < 10; ++d3) {
                for (int d4 = 0; d4 < 10; ++d4){
                    palindrome = 1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 +100*d3 + 10*d2 + d1;
                    if (isPrime(palindrome)) {
                        arr[++ans] = palindrome;
                    }
                }
            }
        }
    }

    int min, max;
    std::cin >> min >> max;
    for (int i = 0; i <= ans; ++i) {
        if (arr[i] >= min && arr[i] <= max) {
            std::cout << arr[i] << std::endl;
        }
    }
    return 0;
}