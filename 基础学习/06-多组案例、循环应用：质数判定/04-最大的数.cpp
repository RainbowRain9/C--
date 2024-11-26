/*
描述
    输出三个数中最大的数

输入
    第1行是一个正整数n，表示测试样例的数量。

    从第2~第n+1行，每行为一组测试数据，包含三个浮点数，用空格相隔。

输出
    针对每行测试数据，输出这行三个数中的最大数。
    每组案例输出完都要换行。

样例输入
    1
    1 2 3

样例输出
    3
*/

#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        float a, b, c, temp;
        cin >> a >> b >> c;

        if (a < b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        if (a < c)
        {
            temp = a;
            a = c;
            c = temp;
        }
        cout << a << endl;
    }
    
    return 0;
}