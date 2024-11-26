/*
描述
    输入三个整数，输入其中所有奇数的乘积，如果其中都没有奇数，则输出0。

输入
    第1行是一个正整数n，表示测试案例的数量。
    从第2行到第n+1行，每行有3个整数。

输出
    针对每组测试案例，输出3个整数中所有奇数的乘积，如果其中都没有奇数，则输出0。
    每组案例输出完后都要换行。

样例输入
    2
    1 2 3
    4 5 6

样例输出
    3
    5
*/

#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int temp = 1;
        if (a % 2 != 0) temp *= a;
        if (b % 2 != 0) temp *= b;
        if (c % 2 != 0) temp *= c;

        if (temp == 1 && a * b * c != 1)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << temp << endl;
        }
        
    }
    
    return 0;
}