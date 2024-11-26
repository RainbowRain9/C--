/*
描述
斐波那契数列是这样一组有规律的数字：1、1、2、3、5、8、13、21、34、…。
这组数字的前两项都是1，从第三项开始，每个数字都是前两个数字的和。

把数列的前n项输出出来。

输入
一个正整数n（n>=2）

输出
n个整数，表示数列前n项。要求每两个数字之间有一个空格，最后那个数字后面不要有空格，直接换行。

样例输入
4

样例输出
1 1 2 3
*/

#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    int* a = new int [n];
    a[0] = 1;
    a[1] = 1;
    cout << a[0] << " " << a[1];
    bool f = true;
    for (int i = 2; i < n; i++)
    {
        a[i] = a[i - 2] + a[i - 1];
        cout << " " << a[i];

    }
    
    return 0;
}