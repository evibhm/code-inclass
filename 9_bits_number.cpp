/*
*   Question URL: https://s3.ax1x.com/2020/11/22/D8ntfO.jpg
*/
#include <iostream>

// 定义全局变量是为了方便在所有函数中使用
bool bk[10]; // book 用来标记是否数字 1~9 是否使用
int num = 0; // 所求的 9 位数

void dfs(int n) { // 第 10-n 位
    for (int i = 1; i < 10; ++i) {
        if (!bk[i]) { // 如果没有使用 i
            if ((num * 10 + i) % n == 0) { // 如果符合 reminder == 0
                num = num*10 + i; // 改变 num
                bk[i] = true; // 标记 已使用 i
                if (n == 9) {
                    std::cout << num << std::endl;
                    return;
                }
                dfs(n + 1); // 递归
                num /= 10; // 改回之前的 num
                bk[i] = false; // 取消标记 i
            }
        }
    }
    return;
}

int main()
{
    dfs(1);
    return 0;
}