/*
描述
编写函数int f(int a)，当a为偶数时返回1，当a为奇数时返回2。
然后在主函数中输入一个正整数n，然后输入n个整数，调用函数f，输出f的返回结果。


输入
一个正整数n，表示n组案例。

每组案例由一个整数构成。

输出
针对每组案例，当该整数为偶数时输出1，当该整数为奇数时输出2。每组案例输出完都要换行。

样例输入
2
7
10

样例输出
2
1
*/

#include <iostream>
using namespace std;
int f(int a){
    if (a % 2 == 0) return 1;
    if (a % 2 != 0) return 2;
}

int main ()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        cout << f(a) << endl;
    }
    
    return 0;
}