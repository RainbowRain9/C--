/*
描述
通过重载函数（overloaded function），返回三个参数中较大的参数。

第一个重载接受 3 个 int 类型参数，函数返回三个数字中较大的数（整数）。

第二个重载接受 3 个 double 类型参数，函数返回三个数字中较大的数（浮点数）。

主函数中分别输入两组值，调用函数输出结果。

输入
一共有 6 个数字，首先是三个浮点数 a、b、c，然后是三个整数 d、e、f。

输出
先输出 a、b、c 的最大值，换行。

然后输出 d、e、f 的最大值，换行。

可能需要嵌套调用函数。

样例输入
1.5 2.5 3.5

3 2 1

样例输出
3.5

3
*/

#include <iostream>

using namespace std;

int max(int a, int b, int c)
{
    if (a < b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    if (a < c)
    {
        a = a ^ c;
        c = a ^ c;
        a = a ^ c;
    }
    return a;
}

float max(float d, float e, float f)
{
    float temp;
    if (d < e)
    {
        temp = d;
        d = e;
        e = temp;
    }
    if (d < f)
    {
        temp = d;
        d = f;
        f = temp;
    }
    return d;
}

int main()
{
    float a, b, c;
    int d, e, f;
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    cout << max(a, b, c) << endl;
    cout << max(d, e, f) << endl;
    return 0;
}