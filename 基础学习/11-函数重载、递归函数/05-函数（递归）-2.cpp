/*
描述
m块饼每天吃2块或者3块（注意：不能吃1块），吃到完为止。问有多少种不同的吃法。

输入
一个正整数n，表示n组案例。

每组案例由一个正整数m构成。（m<=20）

输出
针对每组案例，输出共有多少种吃完的方法。

每组案例输出完都要换行。

样例输入
1

10

样例输出
7
*/

#include <iostream>
using namespace std;
int count(int m)
{
    if (m == 1) return 0;
    else if (m == 2 || m == 3) return 1;
    else return count(m - 2) + count(m - 3);
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        cout << count(m) << endl;
    }
    return 0;
}