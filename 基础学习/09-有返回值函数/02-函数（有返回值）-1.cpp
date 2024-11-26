/*
描述
定义一个函数f，有一个int类型的参数a，函数返回a的2倍。
主函数中输入一个整数b，调用f函数，输出f(b)的结果。

输入
一个整数b

输出
2倍的b，不要换行

样例输入
5

样例输出
10

提示说明
函数的声明应该是int f(int n);
*/

#include <iostream>
using namespace std;

void f(int a){
    a *= 2;
    cout << a;
}
int main()
{
    int b;
    cin >> b;
    f(b);
    
    return 0;
}