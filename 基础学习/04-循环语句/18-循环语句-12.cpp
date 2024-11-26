/*
描述
    输入n个整数，使用循环语句计算它们的乘积并输出

输入
    一个整数n，然后是n个整数

输出
    这n个整数的乘积

样例输入
    3
    2 3 4

样例输出
    24
*/

#include <iostream>
using namespace std;

int main ()
{
    int n, num;
    cin >> n;
    int sum = 1;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        sum *= num;
    }
    cout << sum;

    return 0;
}