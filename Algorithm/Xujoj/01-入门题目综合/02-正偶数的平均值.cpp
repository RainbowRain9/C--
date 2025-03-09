/*
问题描述
输入m个浮点数，统计其中正偶数（小数部分为0）的平均值，结果四舍五入到整数。

输入描述
多组案例。一个正整数n，表示案例的数量。（n<=20）

每组案例先是一个正整数m，表示浮点数的数量，然后是m个浮点数。（m<=20，每个浮点数都不会太大）

输出描述
针对每组案例，输出一个整数，表示满足条件的数字的平均值（四舍五入到整数）。如果这m个浮点数中都没有正偶数，则输出0。

每组案例输出完都要换行。

样例输入
2

3 5.3 3 1.4

5 2.0 4 10 -6 1.9

样例输出
0

5

提示说明
第二组样例中，不论是2.0，还是4和10，都算正偶数。
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;

        float sum = 0;
        int num = 0;
        for (int i = 0; i < m; i++)
        {
            float a;
            cin >> a;

            if (a > 0 && fmod(a, 2) == 0) // 判断是否为正偶数
            // 使用 fmod 函数来计算 a 除以 2 的余数是否为 0
            {
                sum += a;
                num++;
            }
        }
        if (num == 0) // 没有正偶数
        {
            cout << 0 << endl;
        }
        else 
        // 输出平均值，四舍五入到整数
            cout << round(sum / num) << endl;
    }

    return 0;
}