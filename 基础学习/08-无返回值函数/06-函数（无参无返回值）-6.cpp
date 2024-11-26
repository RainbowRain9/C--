/*
描述
利用函数输出10行，奇数行是5个*，偶数行是5个#

输入
无

输出
10行，奇数行是5个*，偶数行是5个#

样例输入
 

样例输出
*****
#####
*****
#####
*****
#####
*****
#####
*****
#####

提示说明
最后一行后也要换行
*/

#include <iostream>
using namespace std;

void printPattern()
{
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 != 0)
        {
            cout << "*****" << endl;
        }
        else
        {
            cout << "#####" << endl;
        }
        
    }
    
}
int main ()
{
    printPattern();
    return 0;
}