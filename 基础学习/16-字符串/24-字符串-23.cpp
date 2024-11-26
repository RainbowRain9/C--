/*
描述
输入一行可能带空格的字符串，删除该字符串的后置空格
（删除最后面的所有空格，直到看到一个非空格字符停止），
保存在另一个字符串变量中，输出删除后置空格后的结果。

输入
一个正整数n，表示n组案例。

每组案例由一行可能带空格的字符串构成。

输出
针对每组案例，输出该字符串删除后置空格后的结果。

每组案例输出完都要换行。

样例输入
2

   abc  ef

xyz   abc

样例输出
   abc  ef

xyz   abc

提示说明
样例输入每行最后有很多空格，样例输出每行最后没有空格。

本题中由于服务器使用的Linux的换行符是'\n'，
而Windows的换行符是"\r\n"，故代码必须额外地处理掉行尾多出来的'\r'字符后再输出。
*/

#include <iostream>
using namespace std;
int main()
{

    int n;
    cin >> n;
    string a;
    for (int i = 1; i < n + 2; i++)
    {
        getline(cin, a);
        int b = a.length() - 1;
        while (i != 1 && a[b] == ' ')
        {
            b--;
        }
        cout << a.substr(0, b + 1);
        if (i != 1)
        {
            cout << endl;
        }
    }

    return 0;
}