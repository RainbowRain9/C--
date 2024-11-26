/*
描述
    根据两个数字和运算符（加减乘除），计算结果

输入
    1个正整数n，表示测试案例的数量。

    每组测试案例中，有两个正整数和一个字符（+、-、*、/ 中的某一个）。

输出
    针对每组案例，输出运算的结果。每组案例输出后都要换行。

样例输入
    2

    3 4 +

    5 2 /

样例输出
    7

    2.5
*/

#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        float a, b;
        char c;
        cin >> a >> b >> c;

        if (c == '+')
        {
            cout << a + b;
        }
        else if (c == '-')
        {
            cout << a - b;
        }
        else if (c == '*')
        {
            cout << a * b;
        }
        else
        {
            cout << a / b;
        }
        
        cout << endl;
    }
    
    return 0;
}
