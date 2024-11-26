/*
描述
    输入一个正整数m，代表年份，如果m是闰年，则输出yes，否则输出no。
    定义闰年的判断规则是：
        能被4整除的大多是闰年，但能被100整除而不能被400整除的年份不是闰年，能被3200整除的也不是闰年。
        例如1900年不是闰年，2000年是闰年，3200年不是闰年。

输入
    1个正整数m，表示年份。

输出
    如果m年是闰年，则输出yes，否则输出no。不要换行。

样例输入
    2016

样例输出
    yes
*/

#include <iostream>
using namespace std;

int main ()
{
    int m;
    cin >> m;

    if (m % 100 == 0 && m % 400 != 0)
    {
        cout << "no";
    }

    else if (m % 3200 == 0)
    {
        cout << "no";
    }
    
    else if (m % 4 == 0)
    {
        cout << "yes";
    }
    
    else
    {
        cout << "no";
    }
    

    return 0;
}