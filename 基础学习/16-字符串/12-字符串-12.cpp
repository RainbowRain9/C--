/*
描述
计算字符串里有几个大写字母字符，几个小写字母字符，几个数字字符，几个其他字符

输入
一个正整数n，表示有n组案例。

每组案例由一个字符串组成。

输出
针对每组案例，输出4个整数，分别表示有几个大写字母字符，几个小写字母字符，几个数字字符，几个其他字符。

4个数字之间用空格隔开，最后一个数字后面不能有空格。

每组案例输出完都要换行。

样例输入
2

aT&T

12AA**

样例输出
2 1 0 1

2 0 2 2
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
        int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] >= 'A' && a[i] <= 'Z')
            {
                cnt1++;
            }
            else if (a[i] >= 'a' && a[i] <= 'z')
            {
                cnt2++;
            }
            else if (a[i] >= '0' && a[i] <= '9')
            {
                cnt3++;
            }
            else
            {
                cnt4++;
            }
        }
        cout << cnt1 << " " << cnt2 << " " << cnt3 << " " << cnt4 << endl;
    }
    return 0;
}