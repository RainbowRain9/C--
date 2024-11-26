/*
描述
编写函数int compare(string s)，根据输入的字符串s，判断其中的大写字符（A~Z）多还是小写字符（a~z）多。
如果大写字符多，则返回1；如果小写字符多，则返回-1；如果两者一样多，则返回0。
输入字符串，利用上述函数，输出函数的返回值。

输入
一个正整数n，表示n组案例。

每组案例由一个字符串构成。

输出
针对每组案例，输出上述compare函数的返回值。

每组案例输出完都要换行。

样例输入
1

ABCde

样例输出
1

*/

#include <iostream>
using namespace std;
int compare(string s)
{
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (islower(s[i]))
        {
            cnt1++;
        }
        else
        {
            cnt2++;
        }
    }
    if (cnt1 > cnt2)
    {
        return -1;
    }
    else if (cnt1 == cnt2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string a;
        cin >> a;
        cout << compare(a) << endl;
    }
    return 0;
}