/*
描述
输入月份，输出2017年该月份有多少天。

输入
一个正整数n，表示n组案例。

每组案例由一个整数a构成（1<=a<=12），代表月份。

输出
针对每组案例，输出一个整数，表示2017年（平年）a月的天数。

每组案例输出完都要换行。

样例输入
2

1

2

样例输出
31

28
*/
#include <iostream>
using namespace std;
int main ()
{
    int n;
    cin >> n;
    while (n--)
    {
        int i;
        cin >> i;
        int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        cout << a[i - 1] << endl;
    }
    return 0;
}