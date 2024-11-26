/*
描述
有一个数列是这样的规律：1、2、4、8、16、…。这组数字的前一项是1，后面每一项都是前一项的两倍。求该数列中首个比1000大的数字。


输入
无

输出
一个整数，是该数列中首个比1000大的数字。
*/

#include <iostream>
using namespace std;
int main()
{
    int n = 1;
    while (n < 1000)
    {
        n *= 2;
    }
    
    cout << n;
    
    return 0;
}