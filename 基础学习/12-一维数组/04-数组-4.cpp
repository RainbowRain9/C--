/*
描述
把一些整数存放在数组中，然后输出最开头和最末尾两个元素的和

输入
只有一组案例，有5个整数。

输出
把这5个整数先存到一个数组里，然后输出最开头和最末尾两个元素的和。不要换行。

样例输入
1 2 3 4 5

样例输出
6
*/
#include <iostream>
using namespace std;
int main()
{
    int a[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    cout << a[0] + a[4];
    
}