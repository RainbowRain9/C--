/*
描述
统计m以内（小于等于m）同时满足以下三个条件的数字的总个数：
1、是正整数；2、是完全平方数；3、各位数字上没有相同的数字。

输入
一个正整数n，表示有n组案例。

每组案例由一个正整数m构成（m可能有点大）。

输出
针对每组案例，输出m以内（小于等于m）同时满足以下三个条件的数字的总个数：
1、是正整数；2、是完全平方数；3、各位数字上没有相同的数字（例如171，由于有两个1，所以不满足条件）。

每组案例输出完都要换行。

样例输入
1

100

样例输出
9

提示说明
1 4 9 16 25 36 49 64 81都满足，100有2个重复的数字0，故不算。
*/

#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    while (n--)
    {
		int m;
		cin >> m;
		int cnt = 0;
		for (int i = 1; i * i <= m; i++)
		{
			int num = i * i;
			bool f = false;
			int cntBit[10] = { 0 };
			while (num != 0) 
			{
				if (++cntBit[num % 10] > 1)
				{
					f = true;
					break;
				}
				num = num / 10;
			}
			if (!f) 
			{
				cnt++;
			}
		}
		cout << cnt << endl;	
    }
    return 0;
}