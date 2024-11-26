/*
问题描述
求a到b之间（包含a和b）所有能分解成两个相邻整数乘积的整数之和。（例如30可以分解成两个相邻整数5和6的乘积，所以如果a到b之间有30，那么30符合条件）

输入描述
多组案例。一个正整数n，表示案例的数量。（n<=20）

每组案例由两个正整数a和b组成。（a<=b<=20亿）

输出描述
针对每组案例，输出一个长整数，表示所有符合条件的整数之和。

每组案例输出完都要换行。

样例输入
2

10 30

1 100000000

样例输出
62

333333330000

提示说明
10到30之间符合条件的数字有12、20、30。
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
        long long a, b;
        cin >> a >> b;

        // ceil向上取整
        long long start = ceil((-1 + sqrt(1 + 4 * a)) / 2);

        // floor向下取整
        long long end = floor((-1 + sqrt(1 + 4 * b)) / 2);

        long long sum = 0;
 
        for (long long k = start; k <= end; ++k)
        {
            sum += k * (k + 1);
        }

        cout << sum << endl;
    }

    return 0;
}   