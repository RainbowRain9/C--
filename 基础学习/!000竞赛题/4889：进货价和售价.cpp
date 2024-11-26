/*
问题描述
已知小卖部对某样商品的进货价是a元，小卖部准备把这件商品标价x元出售，x是个整数，且相对于进货价至少要挣b元。问x的最小值是多少？

输入描述
两个正浮点数a和b，含义见问题描述。（a<=10000，b<=10000）

输出描述
一个正整数x，含义见问题描述。

不要换行。

样例输入
10.5 1.6

样例输出
13
*/

#include <iostream>
using namespace std;

int main()
{
    float x;
    float a, b;
    cin >> a >> b;
    x = a + b;
    if (int(x) == x)
    {
        cout << int(x);
    }
    else
        cout << int(x) + 1;

    return 0;
}