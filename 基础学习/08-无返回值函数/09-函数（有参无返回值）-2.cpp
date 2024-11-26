/*
描述
定义一个函数f，有一个int类型的参数a，用于输出比a小的最大的奇数。
在主函数中输入一个整数b，然后调用f函数输出比b小的最大的奇数。



输入
一个整数b

输出
比b小的最大的奇数。不要换行。

样例输入
5

样例输出
3
*/

#include <iostream>
using namespace std;

void f(int a){
    cout << (a % 2 != 0 ? a - 2 : a - 1);
}

int main ()
{
    int b;
    cin >> b;
    f(b);
    return 0;
}