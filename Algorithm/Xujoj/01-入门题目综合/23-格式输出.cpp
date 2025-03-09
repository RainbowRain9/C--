/*
问题描述
输出一个正整数a，如果a的位数不到m位，则输出时需要在a前面补若干个0，以达到m位；如果a达到或者超过m位，则直接输出a。

输入描述
 一个正整数n，表示有n组案例。

每组案例由一个正整数a和一个正整数m组成。

输出描述
针对每组案例，如果a的位数不到m位，则输出时需要在a前面补若干个0，以达到m位；如果a达到或者超过m位，则直接输出a。

每组案例输出完毕后都要换行。

样例输入
2

1234 6

1234 3

样例输出
001234

1234
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, m;
        cin >> a >> m;
        string str = to_string(a);
        if (str.length() < m)
        {
            for (int i = 0; i < m - str.length(); i++)
            {
                cout << "0";
            }
        }
        cout << a << endl;
    }

    return 0;
}