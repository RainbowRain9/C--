/*
描述
利用函数输出n行，每行4个#

输入
一个正整数n

输出
n行，每行4个#。最后一行后面也要换行。

样例输入
3

样例输出
####

####

####
*/

#include <iostream>
using namespace std;

void printPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "####" << endl;
    }
    
}

int main ()
{
    int n;
    cin >> n;
    printPattern(n);

    return 0;
}