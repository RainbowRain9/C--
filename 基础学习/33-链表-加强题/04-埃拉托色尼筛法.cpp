/*
问题描述
埃拉托色尼筛法简称埃氏筛法，基本思想是，假定区间[1, n]内的所有数都是素数，再去掉所有合数，剩下的就是所有素数。判断合数的方法是从 2 开始依次过筛，如果是 2 的倍数则该数不是素数，进行标记处理，直至将 n/2 过筛，将所有合数打上标记。

【想法】假设有一个筛子存放整数 1～n，依次将 2、3、5、…的倍数筛去（标记），最后没有打上标记的数都是素数。

输入描述
待确定素数的范围 n

输出描述
小于n的所有素数，以空格分开，最后不需要回车换行。

样例输入
10

样例输出
2 3 5 7

提示说明
最后不需要回车换行。
*/

#include <iostream>
using namespace std;

// 素数
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        if (isPrime(i))
        {
            if (i == 2)
            {
                cout << i;
            }
            else
                cout << " " << i;
        }
    }

    return 0;
}