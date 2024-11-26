/*
描述
    输入m，输出m到2m之间（包含m和2m）最大的素数减去最小的素数的结果。

输入
    一个正整数n，表示测试案例的数量。

    每组案例中有一个正整数m。

输出
    针对每组案例，输出一个整数，表示m到2m之间（包含m和2m）最大的素数减去最小的素数的结果。每组案例输出完都要换行。

样例输入
    2
    1
    7

样例输出
    0
    6

提示说明
    1到2之间最大的素数是2，最小的素数是2，2-2=0
    7到14之间最大的素数是13，最小的素数是7，13-7=6
*/

#include <iostream>
using namespace std;
bool isPrime (int j) {
    if (j <= 1) return false;
    if (j == 2) return true;
    if (j % 2 == 0) return false;
    for (int i = 3; i * i <= j; i += 2)
    {
        if (j % i == 0) return false;
    }
    return true;
}

int main ()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        int a, b;

        for (int j = m; j <= 2 * m; j++)
        {
            if (isPrime(j))
            {
                a = j;
                break;
            }
            
        }
        for (int j = 2 * m; j >= m; j--)
        {
            if (isPrime(j))
            {
                b = j;
                break;
            }
            
        }
        cout << b - a << endl;
    }
    
    return 0;
}