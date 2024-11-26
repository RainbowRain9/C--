/*
描述
输入两个字符串，把它们用字符串连接方法连接起来，保存在另一个字符串变量里。

输入
一个正整数n，表示有n组案例。

每组案例中有两个字符串a、b，用空格相隔。

输出
针对每组案例，定义一个字符串变量c，保存a连接b的值，并输出c。

每组案例输出完都要换行。

样例输入
1

abc dd

样例输出
abcdd
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string a, b, c;
        cin >> a >> b;
        c = a + b;
        cout << c << endl;
    }
    
    return 0;
}