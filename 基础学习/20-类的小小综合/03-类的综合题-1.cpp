/*
描述
定义一个平面直角坐标系下的坐标点类Point，输入两个点x轴和y轴的坐标，输出两个坐标点到原点的距离，以及两个坐标点之间的距离。与正确答案的误差不大于0.01即算正确。

主函数如下：

int main()
{
 double x1, y1, x2, y2;
 cin >> x1 >> y1 >> x2 >> y2;
 Point p1(x1, y1), p2(x2, y2);
 cout << p1.getDistance() << endl; //输出p1到原点的距离
 cout << p2.getDistance() << endl; //输出p2到原点的距离
 cout << p1.getDistance(p2) << endl; //输出p1到p2的距离
 return 0;
}

输入
只有一组案例。

4个浮点数，分别是第一个点的x轴、y轴坐标，第二个点的x轴、y轴坐标

输出
3个浮点数，分别是第一个点到原点的距离、第二个点到原点的距离、两个点之间的距离。

每个数字输出完都要换行。与正确答案的误差不大于0.01即算正确。

样例输入
1 1 2 2

样例输出
1.41421
2.82843
1.41421
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    Point(double _x, double _y) : x(_x), y(_y) {}
    double getDistance()
    {
        return sqrt(x * x + y * y);
    }

    double getDistance(Point &p)
    {
        return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
    }
};

int main()
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Point p1(x1, y1), p2(x2, y2);
    cout << p1.getDistance() << endl;   // 输出p1到原点的距离
    cout << p2.getDistance() << endl;   // 输出p2到原点的距离
    cout << p1.getDistance(p2) << endl; // 输出p1到p2的距离
    return 0;
}
