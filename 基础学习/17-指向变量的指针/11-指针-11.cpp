/*
描述
定义一个长度为m的整型数组a，利用指针为数组每个元素赋值a[i]=(i*i)%25，
然后利用指针输出该数组，赋值和输出过程中不得使用数组名字a。

输入
只有一组案例。

一个正整数m，表示数组的长度。

输出
利用指针输出数组每个元素，每两个元素之间有一个空格，最后一个元素后面没有空格和换行。

样例输入
3

样例输出
0 1 4
*/

#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >> m;
    int *a = new int[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = (i * i) % 25;
    }
    for (int i = 0; i < m; i++)
    {
        if (i != 0)
        {
            cout << " " << *(a + i);
        }
        else
        {
            cout << *(a + i);
        }
    }

    return 0;
}