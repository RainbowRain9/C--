/*
描述
输入年份和月份，输出该年该月有多少天。

输入
一个正整数n，表示n组案例。

每组案例由两个整数a和b构成，其中a代表年份，b代表月份。（1<=a<=3199，1<=b<=12）

输出
针对每组案例，输出一个整数，表示a年b月的天数。

每组案例输出完都要换行。

样例输入
2

2017 5

2016 2

样例输出
31

29
*/
#include <iostream>
using namespace std;
bool isYear(int m)
{
    if (m % 100 == 0 && m % 400 != 0)
    {
        return false;
    }

    else if (m % 3200 == 0)
    {
        return false;
    }
    
    else if (m % 4 == 0)
    {
        return true;
    }
    
    else
    {
        return false;
    }
}
int main ()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, i;
        cin >> a >> i;
        int b[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if (isYear(a) && i == 2)
        {
            cout << 29;
        }
        else
        {
            cout << b[i - 1];
        }
        cout << endl;
    }
    
    return 0;
}