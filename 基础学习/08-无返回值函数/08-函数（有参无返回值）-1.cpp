/*
描述
定义一个函数f，有一个int类型的参数a，用于输出比a大的最小的偶数。
在主函数中输入一个整数b，然后调用f函数输出比b大的最小的偶数。

输入
一个整数b

输出
比b大的最小的偶数，不要换行。

样例输入
3

样例输出
4
*/

#include <iostream>
using namespace std;

void f(int a){
    if (a % 2 == 0) cout << a + 2 << endl;
    else cout << a + 1 << endl;
}

int main ()
{
    int b;
    cin >> b;
    f(b);
    return 0;
}