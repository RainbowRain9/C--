/*
描述
编写函数bool isSquare(int a)，当a是完全平方数时返回true，否则返回false。
然后在主函数中输入一个正整数n，然后输入n个整数a，根据函数f的结果，如果a是完全平方数，则输出a is a perfect square number，否则输出a is not a perfect square number。其中a用具体的数值代入。

输入
一个正整数n，表示n组案例。

每组案例由一个整数a构成。

输出
针对每组案例，当a是完全平方数，则输出a is a perfect square number，否则输出a is not a perfect square number。其中a用具体的数值代入。

每组案例输出完都要换行。

样例输入
2

16

17

样例输出
16 is a perfect square number

17 is not a perfect square number
*/

#include <iostream>
#include <cmath>
using namespace std;
bool isSquare(int a){
    long long int sqrta = static_cast<long long int>(sqrt(a));
    if (sqrta * sqrta == a) return true;
    else return false;
}

int main ()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        if (isSquare(a))
        {
            cout << a << " is a perfect square number";
        }
        else
        {
            cout << a << " is not a perfect square number";
        }
        cout << endl;
    }
    
    return 0;
}