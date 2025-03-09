/*
问题描述
===========
小调每天都掉头发，有个星期小调预测了他每天会掉落的头发数量。

在这个星期里，每天小调都会预测他今天掉落的头发数量，分别记为a1、a2、...、a7，
同时也会统计每天事实上掉落的头发数量，分别记为b1、b2、...、b7。

预测是件困难事，在第一天没有任何参考的情况下，小调会随便想一个正整数，作为a1的值。

从第二天开始，小调会根据(上一天的预测值+上一天实际掉落数量)/2的值作为当天的预测值，
即a2=(a1+b1)/2, ..., a7=(a6+b6)/2

小调希望预测的掉落总数与事实上的掉落总数的误差尽可能的小，那么a1的值应该取多少？
（如果有多个符合条件的a1值，那么取其中最小的作为a1值）

输入描述
===========
一个正整数n，表示案例的数量。（n<=50）

每组案例由7个正整数组成，表示b1、b2、...、b7的值（均不大于10000）。

输出描述
===========
针对每组案例，输出a1的值（关于a1的详细说明见【描述】）。

每组案例输出完都要换行。

样例输入
===========
2
2 2 2 2 2 2 2
3 2 1 4 5 3 9

样例输出
===========
2
7

提示说明
===========
暴力出奇迹
*/

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int b[7];
        for (int i = 0; i < 7; i++)
        {
            cin >> b[i];
        }

        int bestA1 = 1;
        long long minDiff = LLONG_MAX;

        for (int a1 = 1; a1 <= 10000; a1++)
        {
            long long a[7] = {a1};
            long long totalA = a1, totalB = b[0];

            for (int i = 1; i < 7; i++)
            {
                a[i] = (a[i - 1] + b[i - 1]) / 2;
                totalA += a[i];
                totalB += b[i];
            }

            long long diff = abs(totalA - totalB);
            if (diff < minDiff)
            {
                minDiff = diff;
                bestA1 = a1;
            }

            if (minDiff == 0)
                break;
        }

        cout << bestA1 << endl;
    }

    return 0;
}
