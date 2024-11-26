/*
描述
定义一个函数f，有一个int类型的参数a，函数返回a的平方。主函数中输入一个整数b，调用f函数，输出f(b)的结果。

输入
一个整数b

输出
b的平方

样例输入
4

样例输出
16
*/

#include <iostream>
using namespace std;
void f(int a)
{
    a *= a;
    cout << a;
}

int main()
{
    int b;
    cin >> b;
    f(b);
    
    return 0;
}