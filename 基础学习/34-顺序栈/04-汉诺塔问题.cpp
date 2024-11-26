/*
问题描述
汉诺塔问题：有三根柱子A、B、C，A柱子上有n个盘子，盘子大小从下到上依次变小。要求将所有盘子从A柱子移到C柱子，期间可以借助B柱子，但必须遵循以下规则：
1. 每次只能移动一个盘子
2. 大盘子不能放在小盘子上面

输入描述
输入一个整数n，表示A柱子上初始的盘子数量

输出描述
输出将n个盘子从A柱子移动到C柱子所需的最少步数

样例输入
3

样例输出
7

提示说明
输出结果后需要换行
*/

#include <iostream>
#include <cmath>
using namespace std;

int Hanoi(int n) {
    return pow(2, n) - 1;
}

int main()
{
    int n;
    cin >> n;
    cout << Hanoi(n) << endl;
    return 0;
}