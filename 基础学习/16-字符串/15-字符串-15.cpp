/*
描述
输出字符串中只出现过一次的小写字符

输入
一个正整数n，表示有n组案例。

每组案例由一个字符串构成。

输出
针对每组案例，输出字符串中只出现过一次的小写字符，要按照在字符串中出现的先后顺序输出。

每组案例输出完都要换行。

样例输入
2

aaBBCccba

zyaaaaaxx

样例输出
b

zy
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string a;
        cin >> a;
        int f[26] = {0};
        int index;
        for (int i = 0; i < a.size(); i++)
        {
            index = a[i] - 'a';
            if (islower(a[i]))
            {
                f[index]++;
            }
        }
        for (int i = 0; i < a.size(); i++)
        {
            index = a[i] - 'a';
            if (f[index] == 1)
            {
                cout << a[i];
            }
        }

        cout << endl;
    }

    return 0;
}