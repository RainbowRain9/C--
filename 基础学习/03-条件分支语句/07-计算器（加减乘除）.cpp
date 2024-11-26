/*
描述
    实现一个最简单的计算器，支持+, -, *, / 四种运算。仅需考虑输入输出为整数的情况，
    数据和运算结果不会超过int表示的范围。输入两个整数以及一个运算符（+, -, *, / ），输出运算结果。
    然而：
    （1）如果出现除数为0的情况，则输出：Divided by zero!
    （2）如果出现无效的运算符（即不为 +, -, *, / 之一），则输出：Invalid operator!

输入
    两个整数m和n，以及一个运算符  

输出
    （1）如果出现无效的运算符（即不为 +, -, *, / 之一），则输出：Invalid operator!

    （2）如果运算符为/，且除数n为0，输出：Divided by zero!

    （3）其他情况，根据运算符输出计算结果

    不要换行。

样例输入
    4 5 *

样例输出
    20
*/

#include<iostream>
using namespace std;
int main(){
    int m, n;
    char a;
    cin >> m >> n >> a;
    if (a == '+' ){
        cout << m+n;
    }
    else if (a == '-' ){
        cout << m-n;
    }
    else{
        cout << "无效运算";
    }
    return 0;
}