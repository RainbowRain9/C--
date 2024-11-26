/*
描述
输入一行可能带空格的字符串，删除该字符串的所有空格字符，保存在另一个字符串变量中，输出删除所有空格后的结果。

输入
一个正整数n，表示n组案例。

每组案例由一行可能带空格的字符串构成。

输出
针对每组案例，输出该字符串删除所有空格后的结果。

每组案例输出完都要换行。

样例输入
2

     abc  ef

xyz   abc

样例输出
abcef

xyzabc

提示说明
C++在读完n的值以后，需要

string t;

getline(cin, t);

来把n所在那行的换行符读走，否则会影响第一组数据的读。
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
        for (int j = 0; j < t.size(); j++)
        {
            if (t[j] != ' ')
            {
                cout << t[j];
            }
        }
        if (i != 0)
        {
            cout << endl;
        }
    }
    return 0;
}