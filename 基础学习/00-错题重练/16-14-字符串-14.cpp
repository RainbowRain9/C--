/*
描述
输出字符串中的小写字符，但如果一个小写字符不是第一次出现，那么第二次开始起都不要输出。

输入
一个正整数n，表示有n组案例。

每组案例由一个字符串构成。

输出
针对每组案例，输出字符串中的小写字符，但如果一个小写字符不是第一次出现，那么第二次开始起都不要输出。

每组案例输出完都要换行。

样例输入
2

aaBBCccba

aaaaa

样例输出
acb

a
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
        cin >> a;
        int cnt[a.length()] = {0};
        for (int i = 0; i < a.size(); i++)
        {
            if (islower(a[i]))
            {
                b[a[i] - 97]++;
                if (b[a[i] - 97] == 1)
                {
                    cout << a[i];
                }
            }
        }
        cout << endl;
    }

    return 0;
}
