/*
描述
    输出一个倒立的三角形星号阵列

输入
    一个正整数n

输出
    n行，每行都比上一行的左右两侧各少一个星号，直到最后一行1个星号。最后一行结束后也要换行。每行最后一个星号输出后不要输出额外的空格。

样例输入
    4

样例输出
*******
 *****
  ***
   *
*/

#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < i; k++)
        {
            cout << " ";
        }
        
        for (int j = 0; j < 2 * (n - i) - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}