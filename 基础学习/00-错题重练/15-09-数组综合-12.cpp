/*
描述
把一堆数字按照最小数—最大数—第二小数—第二大数—第三小数—第三大数…这样的规律输出所有的数字。


输入
只有一组案例。

一个正整数n，然后是n个整数。（n是偶数）

输出
把这n个整数按照最小数—最大数—第二小数—第二大数—第三小数—第三大数…这样的规律输出所有的数字。
每个数字之间有一个空格，最后的数字后面没有空格和换行

样例输入
6

1 2 3 4 5 6

样例输出
1 6 2 5 3 4
*/
#include <iostream>
using namespace std;
template <typename T>
void selSort(T a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	selSort(a, n);
	for (int i = 0; i < n / 2; i++)
	{
		if (i == n / 2 - 1)
		{
			cout << a[i] << " " << a[n - 1 - i];
		}
		else
		{
			cout << a[i] << " " << a[n - 1 - i] << " ";
		}
	}

	delete[] a;
	return 0;
}
