/*
问题描述
根据a和b的值输出由*组成的双向箭头形状。

其中a是正奇数，代表图案有几行；

b是正整数，代表双向箭头中间的横线有多长。

输入描述
只有一组案例，由两个正整数a和b组成。
输出描述
根据a和b的值输出由*组成的双向箭头形状。每行最后不要有多余空格。最后一行星号输出完有个换行。

样例输入
 5 3

样例输出
*/

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a / 2; i++)
    {
        for (int j = a / 2 - i; j > 0; j--)
        {
            cout << " ";
        }
        for (int h = 0; h < i + 1; h++)
        {
            cout << "*";
        }
        for (int k = 0; k < b; k++)
        {
            cout << " ";
        }
        for (int h = 0; h < i + 1; h++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 0; i < (a / 2 + 1) * 2 + b; i++)
    {
        cout << "*";
    }
    cout << endl;

    for (int i = 0; i < a / 2; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << " ";
        }
        for (int h = 0; h < a / 2 - i; h++)
        {
            cout << "*";
        }
        for (int k = 0; k < b; k++)
        {
            cout << " ";
        }
        for (int h = 0; h < a / 2 - i; h++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}