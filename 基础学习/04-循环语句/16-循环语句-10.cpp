/*
描述
    输入5个整数，使用循环语句计算它们的和并输出

输入
    5个整数

输出
    这5个整数之和

样例输入
    1 2 3 4 5

样例输出
    15
*/

#include <iostream>
using namespace std;

int main ()
{
    int num;
    int sum = 0;
    for (int i = 1; i <= 5; i++)
    {
        cin >> num;
        sum += num;
    }
    
    cout << sum;

}