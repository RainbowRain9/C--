/*
描述
    根据a和b的值输出一个由*组成的杠铃形状。
    其中a表示杠铃的高度有多少行，杠铃的两端都是长度为b的正方形。

输入
    只有一组案例，由2个正整数a和b组成，其中b是奇数，a>=2b+1。（a<=30, b<=11）

输出
    根据a和b的值输出一个由*组成的杠铃形状。不要输出不必要的空格，最后一行星号输出完有一个换行。

样例输入
    10 3

样例输出
***
***
***
 *
 *
 *
 *
***
***
***
*/

#include <iostream>
using namespace std;

int main ()
{
    int a, b;
    cin >> a >> b;

    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    for (int i = 0; i < a - 2 * b; i++)
    {
        for (int j = 0; j < b / 2; j++)
        {
            cout << " ";
        }
        
        for (int k = 0; k < 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
    

    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}