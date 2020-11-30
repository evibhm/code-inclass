// LUOGU P2615
#include <iostream>
#include <cmath>
#include <cstdio>

int main(){
    int n, kx, ky;
    int arr[40][40] = {};
    std::cin >> n;
    if (n&1) {
        kx = 1;
        ky = n/2 + 1;
        for (int i = 1; i <= n * n; i ++) {
            arr[kx][ky] = i;
            if (kx == 1 && ky != n) {
                kx = n;
                ky ++;
            } else if (kx != 1 && ky == n) {
                kx --;
                ky = 1;
            } else if (kx == 1 && ky == n) {
                kx ++;
            } else if (arr[kx - 1][ky + 1] == 0) {
                kx --;
                ky ++;
            } else {
                kx ++;
            }
        }
    } else if (n%4) {
        // 不写了， 反正题目不要求；
    } else {
        int cnt = 0;
        int k = n / 4;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                arr[i][j] = ++cnt;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (i > k && i <= 3*k) {
                for (int j = 1; j <= k; ++j) {
                    arr[i][j] = n*n - arr[i][j] + 1;
                }
                for (int j = 3*k+1; j <= 4*k; ++j) {
                    arr[i][j] = n*n - arr[i][j] + 1;
                }
            } else {
                for (int j = k + 1; j <= 3*k; ++j) {
                    arr[i][j] = n*n - arr[i][j] + 1;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            std::cout << arr[i][j] << '\t';
        }
        std::cout << std::endl;
    }
    return 0;
}