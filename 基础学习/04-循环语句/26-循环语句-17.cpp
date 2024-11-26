/*
描述
    某数列是一组有规律的数字：1、1、1、3、5、9、17、31、57、…。这组数字的前三项都是1，从第四项开始，每个数字都是前三个数字的和。输出这个数列第n项的值。

输入
    一个正整数n

输出
    数列第n项的值

样例输入
    6

样例输出
    9
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int first = 1, second = 1, third = 1, next;

    if (n == 1 || n == 2 || n == 3)
    {
        next = 1;
    }
    else
    {
        while (n--)
        {
            if (n == 1 || n == 2 || n == 3)
            {
                next = 1;
            }
            else
            {
                next = first + second + third;
                first = second;
                second = third;
                third = next;
            }
        }
    }
    cout << next;
    
    return 0;
}