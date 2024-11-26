/*
问题描述
把一个字符串几乎原样输出，但是其中如果遇到数字字符，那么该字符需要重复输出该数字那么多遍。如果遇到数字字符0，则不要输出该字符。

输入描述
一个正整数n，表示测试案例的数量。

每组案例由一个不含空格、tab的字符串组成。

输出描述
针对每组案例，把字符串几乎原样输出，但是其中如果遇到数字字符，那么该字符需要重复输出该数字那么多遍。如果遇到数字字符0，则不要输出该字符。

每组案例输出完都要换行。


样例输入
1

ab3c2

样例输出
ab333c22
*/

#include <iostream>
using namespace std;
void processString(const string &a)
{
    for (char ch : a)
    {
        if (isdigit(ch))
        {
            int count = ch - '0';
            if (count > 0)
            {
                cout << string(count, ch);
            }
        }
        else
        {
            cout << ch;
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string a;
        cin >> a;
        processString(a);
    }

    return 0;
}