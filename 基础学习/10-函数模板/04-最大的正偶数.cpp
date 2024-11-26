/*
描述
输出一堆数字中最大的正偶数，如果所有这些数字都不是正偶数，则输出NONE

输入
1个正整数n，表示测试案例的数量。

每组测试案例有一个正整数m，表示数字的个数，然后是m个整数。

输出
针对每组案例，输出这m个整数中最大的正偶数，如果所有这m个数字都不是正偶数，则输出NONE。
每组案例输出后都要换行。

样例输入
2

4 0 1 2 3

3 1 3 5

样例输出
2

NONE
*/

#include <iostream>
using namespace std;

// 函数：找出并返回最大的正偶数
int findMaxEven(int *numbers, int size) {
    int maxEven = -1; // 初始化为-1，因为没有比0小的正偶数
    for (int i = 0; i < size; i++) {
        if (numbers[i] > 0 && numbers[i] % 2 == 0) {
            // 如果是正偶数，更新maxEven
            maxEven = maxEven < numbers[i] ? numbers[i] : maxEven;
        }
    }
    return maxEven; // 如果没有找到，返回-1
}

int main() {
    int n;
    cin >> n; // 读取测试案例的数量

    while (n--) {
        int m;
        cin >> m; // 读取数字的数量
        int *numbers = new int[m]; // 动态分配数组
        for (int i = 0; i < m; i++) {
            cin >> numbers[i]; // 读取数字
        }

        int maxEven = findMaxEven(numbers, m);
        if (maxEven != -1) {
            cout << maxEven << endl;
        } else {
            cout << "NONE" << endl;
        }
        delete[] numbers; // 释放内存
    }

    return 0;
}
