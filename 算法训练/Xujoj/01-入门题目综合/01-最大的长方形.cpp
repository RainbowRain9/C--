/*
问题描述
有m个长方形，在排除正方形的情况下，输出其中面积最大的长方形的长和宽以及面积。

输入描述
多组案例。一个正整数n，表示案例的数量。（n<=20）

每组案例中，先是一个正整数m，表示长方形（包括正方形）的数量；然后是m组数据，每组数据由两个正整数组成，表示一个长方形（也有可能是正方形）相邻两边的长度。（m<=20，面积不会超出int范围）

保证每组案例中至少有一个长方形，并且不会有多个长方形的面积并列最大。

输出描述
针对每组案例，输出其中面积最大的长方形（不能是正方形）的长、宽、面积（长必须比宽大），这三个数据两两之间有一个空格。

每组案例输出完都要换行。

样例输入
1

3

4 4

3 5

6 2

样例输出
5 3 15
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        int max_area = 0; // 设定一个最大面积用于作比较
        int max_a = 0;
        int max_b = 0;
        for (int i = 0; i < m; i++)
        {
            int a, b, area;
            cin >> a >> b;
            if (a < b) // 使a为长边，b为短边
            {
                int temp;
                temp = a;
                a = b;
                b = temp;
            }

            if (a == b) // 排除正方形
            {
                continue;
            }

            area = a * b; // 计算面积
            
            if (max_area < area) // 比较，取最大面积
            {
                max_area = area;
                max_a = a;
                max_b = b;
            }
        }
        cout << max_a << " " << max_b << " " << max_area << endl;
    }

    return 0;
}