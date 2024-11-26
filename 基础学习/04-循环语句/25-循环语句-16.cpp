/*
描述
斐波那契数列是这样一组有规律的数字：1、1、2、3、5、8、13、21、34、…。这组数字的前两项都是1，从第三项开始，每个数字都是前两个数字的和。输出这个数列第n项的值。

输入
一个正整数n

输出
斐波那契数列第n项的值

样例输入
6

样例输出
8   
*/

#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    int first = 1, second = 1, next;

    if (n == 1 || n == 2)
    {
        next = 1;
    }
    else
    {
        while (n--)
        {
            if (n == 1 || n == 2)
            {
                next = 1;
            }
            else
            {
                next = first + second;
                first = second;
                second = next;
            }
        }
    }
    cout << next;
}