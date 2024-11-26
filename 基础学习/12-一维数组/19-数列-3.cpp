/*
描述
有一组有规律的数字：1、2、3、6、11、20、…。这组数字的前三项是1、2、3，
从第四项开始，每个数字都是前三个数字的和。

输出数列的第n项。

输入
一个正整数n

输出
一个整数，表示数列第n项。不要换行。

样例输入
4

样例输出
6
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int* a = new int [n];
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    for (int i = 3; i < n; i++)
    {
        a[i] = a[i - 3] + a[i - 2] + a[i - 1];
    }
    cout << a[n-1];
    delete[]a;
    return 0;
}