/*
描述
    输入一个正整数n，输出1到n中所有能被2整除而且能被3整除的数字的和

输入
    一个正整数n

输出
    1到n中所有能被2整除而且能被3整除的数字的和

样例输入
    10

样例输出
    6
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
        if (i % 2 == 0 && i % 3 == 0)
        {
            sum += i;
        }
        
    }
    cout << sum;

    return 0;
}