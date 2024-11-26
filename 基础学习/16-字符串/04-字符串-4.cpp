/*
描述
输入两个字符串，比较两个字符串的大小。

输入
一个正整数n，表示有n组案例。

每组案例中有两个字符串a、b，用空格相隔。

输出
针对每组案例，如果a比b大，则输出1；如果a和b相等，则输出0；如果a比b小，则输出-1。

每组案例输出完都要换行。

样例输入
3

abc edf

a a

abc XYZ



样例输出
-1

0

1
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string a, b;
        cin >> a >> b;
        if (a > b)
        {
            cout << 1 << endl;
        }
        else if (a == b)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}