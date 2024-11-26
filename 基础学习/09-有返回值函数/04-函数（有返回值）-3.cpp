/*
描述
定义一个函数f，有一个int类型的参数a，函数返回1+2+3+…+a的值。
主函数中输入一个整数b，调用f函数，输出f(b)的结果。

输入
一个整数b

输出
1+2+3+…+a的结果，不要换行

样例输入
4

样例输出
10
*/

#include <iostream>
using namespace std;
void f(int a){
    int sum = 0;
    for (int i = 1; i <= a; i++)
    {
        sum += i;
    }
    a = sum;
    cout << a;
}

int main()
{
    int b;
    cin >> b;
    f(b);
    
    return 0;
}