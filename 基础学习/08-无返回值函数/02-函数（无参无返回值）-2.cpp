/*
描述
定义函数f，用于输出一行共4个#，然后在主函数中调用两次

输入
无

输出
两行，每行4个#，最后一行后面也要换行。

样例输入
 

样例输出
####

####
*/

#include <iostream>
using namespace std;

void f()
{
    cout << "####" << endl;
}

int main ()
{
    f();
    f();
    return 0;
}