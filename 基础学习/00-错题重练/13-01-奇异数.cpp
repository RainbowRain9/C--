/*
描述
定义：如果一个数字中的每位数都互不相同，则称该数字为奇异数。
例如，1234是一个奇异数，因为1、2、3、4这四个数字都互不相同。
当正整数m为偶数时，返回比m大的最小的奇异数；当m为奇数时，返回比m小的最大的奇异数。

输入
第1行是一个正整数n，表示测试案例的数量。

从第2行到第n+1行，每行有1个正整数m（m<=100000000）

输出
针对每组测试案例，当m为偶数时，返回比m大的最小的奇异数；
当m为奇数时，返回比m小的最大的奇异数。每组案例输出完后都要换行。

样例输入
2

10

119

样例输出
12

109
*/

#include <iostream>
using namespace std;
bool isOddDiff(int n)
{
    int a[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        do
        {
            int d = n % 10;
            a[d]++;
            if (a[d] >= 2)
            {
                return false;
            }
            n /= 10;
        } while (n != 0);
        return true;
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        if (m % 2 == 0)
        {
            do
            {
                m++;
            } while (!isOddDiff(m));
        }
        else
        {
            do
            {
                m--;
            } while (!isOddDiff(m));
        }
        cout << m << endl;
    }
    return 0;
}