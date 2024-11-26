/*
描述
    判断一个点是否在一条直线上

输入
    第1行是一个正整数n，表示测试案例的数量
    从第2行到第n+1行，每行有五个数字a、b、c、d、e（不一定是整数，c和d不会都为0），
    其中a和b是点的横坐标和纵坐标，c、d、e构成了一条直线cx+dy=e。

输出
    如果点(a,b)在直线cx+dy=e上，则输出true，否则输出false。
    每组案例输出完都要换行。

样例输入
    1
    1 1 1 1 2

样例输出
    true
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        float a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        if (abs(c * a + d * b - e) <= 1e-6)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
    return 0;
}