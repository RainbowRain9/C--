/*
问题描述
采用穷举法求最大公约数，输入两数m，n，找出较小的数（假如较小的数是n），从n开始到1进行遍历，找出一个数同时能被n和m整除。

输入描述
m n（两个自然数）

输出描述
k:最大公约数

样例输入
48 36

样例输出
12

提示说明
输出不换行
*/

#include <iostream>
using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n;
    if(m < n)
    {
        int temp = m;
        m = n;
        n = temp;
    }
    for (int i = n; i >= 1; i--)
    {
        if (m % i == 0 && n % i == 0)
        {
            k = i;
            break;
        }
    }
    cout << k;
}