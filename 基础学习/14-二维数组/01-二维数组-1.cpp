/*
描述
定义一个100*100的二维数组，为数组中的元素分别赋值1, 2, 3, 4, …, 10000，输出所有元素的总和。

输入
无

输出
一个整数，表示二维数组所有元素的和。不要换行。

样例输入
样例输出
自己算吧
*/

#include <iostream>
using namespace std;
int main ()
{
    int a[100][100];
    int sum = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            a[i][j] = i * 100 + j + 1;
            sum += a[i][j];
        }
    }
    cout << sum;
    return 0;
}