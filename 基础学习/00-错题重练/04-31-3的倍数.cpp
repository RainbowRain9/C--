/*
描述
    判断一堆数字中，是否有某两个数的和是3的倍数

输入
    一个正整数n，表示数字的个数。（n<=100000）
    然后是n个整数。

输出
    如果这n个整数中，存在某两个数字的和恰好是3的倍数，那么输出Yes，
    否则输出No。不要换行。

样例输入
    3
    3 4 5

样例输出
    Yes
*/

#include <iostream>
using namespace std;
int main()
{
    int n, cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        if (a % 3 == 0)
        {
            cnt0++;
        }
        if (a % 3 == 1)
        {
            cnt1++;
        }
        if (a % 3 == 2)
        {
            cnt2++;
        }
        if (a % 3 == -1)
        {
            cnt3++;
        }
        if (a % 3 == -2)
        {
            cnt4++;
        }
    }
    if (cnt0 >= 2 || (cnt1 >= 1 && cnt2 >= 1) || (cnt1 >= 1 && cnt3 >= 1) || (cnt2 >= 1 && cnt4 >= 1) || (cnt3 >= 1 && cnt4 >= 1))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}