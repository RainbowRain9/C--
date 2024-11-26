/*
描述
定义一个函数f，有2个double类型的参数a和b，函数返回长为a宽为b的长方形的周长。
主函数中输入2个double型的数字x和y，调用f函数，输出f(x,y)的结果。

输入
2个double类型数字x和y

输出
以x为长，y为宽的长方形周长

样例输入
4  3

样例输出
14
*/

#include <iostream>
using namespace std;
void f(double a, double b){
    double sum;
    sum = (a + b) * 2;
    cout << sum;
}

int main()
{
    double x, y;
    cin >> x >> y;
    f(x, y);
    
    return 0;
}