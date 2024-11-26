/*
描述
在数组a中存放n个整数（n是偶数），定义函数void f(int a[], int n, int m)，
功能是把a中后一半的元素值增加m，其中函数形参中a表示数组，n表示数组长度，m表示后一半元素要增加的值。
输出经由f函数变化前和变化后数组各元素的和。

输入
只有一组案例。

一个正整数n表示数组元素的个数（n是偶数）；然后是n个整数，表示存放在数组中的元素值；
最后是一个整数m，表示数组后一半元素要增加的值。

输出
两个整数，分别表示数组元素的总和，以及数组后一半元素增加m以后，所有元素的总和。
两个数字中间有一个空格，不要换行。

请按照“描述”中要求定义的函数来实现对数组元素值的变更。

样例输入
6

1 2 3 4 5 6

3

样例输出
21 30
*/

#include <iostream>
using namespace std;

void f(int a[], int n, int m)
{
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++)
	{
		sum1 = sum1 + a[i];
	}
	for (int i = n / 2; i < n; i++)
	{
		a[i] = a[i] + m;
	}
	for (int i = 0; i < n; i++)
	{
		sum2 = sum2 + a[i];
	}
	cout << sum1 << " " << sum2;
}
int main ()
{
    int n, m;
    int* a = new int[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    f(a, n, m);
    delete []a;
    return 0;
}