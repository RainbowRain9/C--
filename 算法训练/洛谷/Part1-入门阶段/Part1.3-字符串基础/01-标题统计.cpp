/*https://www.luogu.com.cn/problem/P5015*/

#include <iostream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int num = 0;
    for (char c : s)
    {
        if (c != ' ' && c != '\n')
        {
            num++;
        }
    }
    cout << num;
    return 0;
}

