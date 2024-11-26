/*
问题描述
输入由多行组成。

如果某行由两个正整数a和b组成，那么把a乘b的结果累加到总和中；

如果某行只有一个整数0，那么输出当前累加的总和，并换行，然后把累加的和重置为0。

如果某行只有一个整数-1，那么输出当前累加的总和，并结束程序。


输入描述
输入由多行组成。

每行要么是两个正整数，要么是一个整数0，要么是一个整数-1。（保证只有最后一行是一个整数-1，累加的和不会超出int整数范围）

输出描述
根据问题描述输出结果。

样例输入
2 3

3 5

0

6 8

-1

样例输出
21

48
*/

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    int sum = 0;

    while (true)
    {
        if (cin >> a)
        {
            if (a == 0)
            {
                cout << sum << endl;
                sum = 0;
            }
            else if (a == -1)
            {
                cout << sum << endl;
                break;
            }
            else
            {
                if (cin >> b)
                {
                    sum += a * b;
                }
            }
        }
    }

    return 0;
}