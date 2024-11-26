/*
描述
m块饼每天吃1块或者2块，吃到完为止。问有多少种不同的吃法。
注意：第1天吃2块第2天吃1块和第1天吃1块第2天吃2块，是两种不同的吃法。

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
89
*/

#include <iostream>
using namespace std;
int f(int m)
{
    if (m == 1)
    {
        return 1;
    }
    else if (m == 2)
    {
        return 2;
    }
    
    return f(m - 1) + f(m - 2);
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        cout << f(m) << endl;        
    }
    return 0;
}