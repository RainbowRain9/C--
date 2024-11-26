/*
描述
    数学上，若一个数能表示成某个整数的平方的形式，则称这个数为完全平方数。
    计算 a 到 b 之间所有完全平方数的和。

输入
    一个正整数 n，表示案例的数量。
    每组案例由 2 个整数 a 和 b 组成。（-9×108 ≤ a ≤ b ≤ 9×108）

输出
    针对每组案例，输出一个长整数（long long int）表示 a 到 b 之间（包含 a 和 b）所有完全平方数的和。
    每组案例输出完都要换行。

样例输入
    2
    4 10
    -1 5

样例输出
    13
    5

提示说明
    第一组样例中，4 到 10 之间的完全平方数有 4、9，总和是 13。
    第二组样例中，-1 到 5 之间的完全平方数有 0、1、4，总和是 5。
*/

#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long int a, b, sum = 0;
        cin >> a >> b;

        if (a < 0) a = 0;
        if (b < 0) b = 0;

        long long int sqrta = static_cast<long long int>(sqrt(a));
        long long int sqrtb = static_cast<long long int>(sqrt(b));

        if (sqrta * sqrta != a)
        {
            sqrta++;
        }
        if (sqrtb * sqrtb > b) 
        {
            sqrtb--;
        }
        for (long long int i = sqrta; i <= sqrtb; ++i) 
        {
            sum += i * i;
        }
        cout << sum << endl;
    }
    
    return 0;
}