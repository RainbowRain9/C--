/*
描述
    输入一个正整数n，输出1到n中所有能被4整除的数字的和

输入
    一个正整数n

输出
    1到n中所有能被4整除的数字的和

样例输入
    10

样例输出
    12
*/

#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 4 == 0)
        {
            sum += i;
        }
        
    }
    cout << sum;

    return 0;
}