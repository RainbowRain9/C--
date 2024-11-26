/*
描述
    求三天以后是哪天

输入
    三个正整数a、b、c，表示今天是a年b月c日，可以确保该天是合法存在的。

输出
    三个数字x y z，表示输入时间的三天以后是x年y月z日。每个数字之间用一个空格隔开，最后不要换行。

样例输入
    2017 9 25

样例输出
    2017 9 28

提示说明
    闰年的判断规则是：能被4整除的大多是闰年，
    但能被100整除而不能被400整除的年份不是闰年，能被3200整除的也不是闰年。
    例如1900年不是闰年，2000年是闰年，3200年不是闰年。
*/

#include <iostream>
using namespace std;

bool year(int a){
    if (a % 100 == 0 && a % 400 != 0) return false;
    else if (a % 3200 == 0) return false;
    else if (a % 4 == 0) return true;
    else return false;
}

int main ()
{
    int a, b, c;
    int x, y, z;
    cin >> a >> b >> c;

    x = a;
    y = b;
    z = c + 3;

    if (b == 2)
    {
        if (year(a))
        {        
            if (c >= 27)
            {
                y = b + 1;
                z = c + 3 - 29;
            }
        }
        else
        {
            if (c >= 26)
            {
                y = b + 1;
                z = c + 3 - 28;
            }
            
        }
    }


    if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10)
    {
        if (c >= 29)
        {
            y = b + 1;
            z = c + 3 - 31;
        }
    }
    
    if (b == 4|| b == 6 || b == 9 || b == 11)
    {
        if (c >= 28)
        {
            y = b + 1;
            z = c + 3 - 30;
        }
    }
    

    if (b == 12 && c >= 29)
    {
        x = a + 1;
        y = 1;
        z = c + 3 - 31;
    }    

    cout << x << " " << y << " " << z;
    return 0;
}