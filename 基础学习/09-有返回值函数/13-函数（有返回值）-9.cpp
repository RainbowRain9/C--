/*
描述
写一个函数返回斐波那契数列的第m项元素。斐波那契数列：1 1 2 3 5…

输入
一个正整数n，表示n组案例。

每组案例由一个正整数m构成。

输出
针对每组案例，输出斐波那契数列的第m项元素的值。（不必考虑int溢出的问题）

每组案例输出完都要换行。

样例输入
2

2

4

样例输出
1

3
*/

#include <iostream>
using namespace std;
void f(int m){
    int first = 1, second = 1, next;
    if (m == 1 || m == 2) next = 1;
    for (int i = 3; i <= m; i++)
    {
        if (m == 1 || m == 2)
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
    cout << next << endl;
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
    }
    
}