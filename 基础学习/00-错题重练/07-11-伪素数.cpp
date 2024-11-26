/*
描述
    判断一个数字a是否是m-伪素数。
        m-伪素数的定义如下：
        如果一个大于1的整数a，除了1和自身外，
        能够整除的数字不多于m个，则称数字a是一个m-伪素数。
            例如10是一个2-伪素数，因为10除了1和10以外，
            能够整除的数字有2和5，不多于2个。当然10也可以称为3-伪素数。

输入
    第1行是一个正整数n，表示测试案例的数量。
    从第2行到第n+1行，每行是一组测试案例，
    有两个整数a和m（其中2<=a<=10亿，0<=m<=100）

输出
    针对每组案例，如果a是m-伪素数，则输出yes，否则输出no。每组案例输出完都要换行。

样例输入
    2
    12 2
    12 4

样例输出
    no
    yes
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, m;
        cin >> a >> m;
        int cnt = 0;
        for (int i = 2; i * i <= a; i++)
        {
            if (a % i == 0)
            {
                cnt++;
                if (i * i != a)
                {
                    cnt++;
                }
                
            }
        }
        if (cnt <= m)
        {
            cout << "yes";
        }
        else
        {
            cout << "no";
        }
        cout << endl;
    }
}