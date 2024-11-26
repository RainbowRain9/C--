/*
描述
把一些整数存放在数组中，然后计算并输出他们的总和

输入
只有一组案例，有5个整数。

输出
把这5个整数先存到一个数组里，然后输出他们的总和。不要换行。

样例输入
1 2 3 4 5

样例输出
15
*/
#include <iostream>

using namespace std;

int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += arr[i];
    }
    cout << sum;
    return 0;
}