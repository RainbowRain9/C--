/*
描述
有一个以原点(0,0)为中心的平放的正方形（即四条边要么与x轴平行，要么与y轴平行），
另外还有一个点，判断这个点是否处于正方形内部（如果恰好在正方形的边上，也算在内部）

输入
1个正整数n，表示测试案例的数量。

每组测试案例有一个正数m和两个数字x和y。其中m表示正方形的边长，x和y表示这个点的横坐标和纵坐标。

输出
针对每组案例，如果该点在正方形内部（包含在正方形的边上），则输出Yes，否则输出No。
每组案例输出后都要换行。

样例输入
2

1 100 100

10 1 1

样例输出
No

Yes

提示说明
m、x、y不保证是整数
*/

#include <iostream>
using namespace std;
bool isInside(float m, float x, float y)
{
    m /= 2;
    if (abs(x) <= m && abs(y) <= m)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        float m, x, y;
        cin >> m >> x >> y;
        if (isInside(m, x, y))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}