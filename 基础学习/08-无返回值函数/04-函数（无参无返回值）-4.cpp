/*
描述
利用函数输出8行，每行4个#

输入
无

输出
8行，每行4个#。最后一行后也要换行。

样例输入

样例输出
####
####
####
####
####
####
####
####
*/

#include <iostream>
using namespace std;

void printPattern(){
    for (int i = 0; i < 8; i++)
    {
        cout << "####" << endl;
    }
    
}

int main ()
{
    printPattern();
    return 0;
}