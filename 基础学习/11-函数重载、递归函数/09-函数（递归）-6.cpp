/*
描述
编写递归函数将输入的整数逐个数字输出，每个数字之间用空格隔开，并且数字为几就应该有几个空格。

例如输入12345，则输出1 2  3   4    5     ，其中1后面有1个空格，2后面有2个空格，…，5后面有5个空格。

输入
一个正整数n，表示n组案例。

每组案例由一个正整数m构成。

输出
针对每组案例，将输入的整数逐个数字输出，每个数字之间用空格隔开，并且数字为几就应该有几个空格。

每组案例输出完都要换行。

样例输入
1

12345

样例输出
1 2  3   4    5    

*/

#include <iostream>
using namespace std;

int f(int m)
{
    if (m < 10)
    {
        cout << m;
        for (int i = 1; i <= m; i++)
        {
            cout << " ";
        }
        
    }
    else
    {
        f(m / 10);
        cout << m % 10;
        for (int i = 1; i <= m % 10; i++)
        {
            cout << " ";
        }
        
    }
    return 0;
}
int main ()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        f(m);
        cout << endl;
    }
    return 0;

}