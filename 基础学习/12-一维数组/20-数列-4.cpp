/*
描述
有一组有规律的数字：2、3、5、7、10、15、22…。
这组数字的前三项是2、3、5，从第四项开始，每个数字都是前1项数字加上前3项数字的和。

输出数列的第n项。

输入
一个正整数n

输出
一个整数，表示数列第n项。不要换行。

样例输入
4

样例输出
7
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int* a = new int [n];

    for (int i = 1; i <= n; i++)
    {
        if(i == 1) a[1] = 2;
        if(i == 2) a[2] = 3;
        if(i == 3) a[3] = 5;
        if(i >= 4) a[i] = a[i - 3] + a[i - 1];
    }
    cout << a[n];
    delete[]a;
    return 0;
}