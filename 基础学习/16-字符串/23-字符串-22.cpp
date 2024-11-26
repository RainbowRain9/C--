/*
描述
输入一行可能带空格的字符串，删除该字符串的前置空格
（删除最前面的所有空格，直到看到一个非空格字符停止），
保存在另一个字符串变量中，输出删除前置空格后的结果。

要求使用基础的循环语句实现，不要用erase方法。

输入
一个正整数n，表示n组案例。

每组案例由一行可能带空格的字符串构成。

输出
针对每组案例，输出该字符串删除前置空格后的结果。

每组案例输出完都要换行。

样例输入
2

      abc  ef

xyz   abc

样例输出
abc  ef

xyz   abc

*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n + 1; i++)
    {
        string t;
        getline(cin, t);
        int b = 0;
        while (t[b] == ' ')
        {
            b++;
        }
        cout << t.substr(b);
        if (i != 0)
        {
            cout << endl;
        }
    }
    return 0;
}