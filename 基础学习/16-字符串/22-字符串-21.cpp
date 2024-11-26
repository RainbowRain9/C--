/*
描述
输入一行可能带空格的字符串，输出该字符串。（使用getline方法）

注意：在int n; cin>>n; 之后，需要把n所在这行的换行符清掉，故开头应该这样写：

 int n;
 cin >> n;
 string t;
 getline(cin, t);
 while (n--)
  ...

输入
一个正整数n，表示n组案例。

每组案例由一行可能带空格的字符串构成。

输出
针对每组案例，输出该字符串。

每组案例输出完都要换行。

样例输入
2

abc  ef

xyz

样例输出
abc  ef

xyz
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string t;
    for (int i = 0; i < n + 1; i++)
    {
        getline(cin, t);
        cout << t;
        if (i != 0)
        {
            cout << endl;
        }
    }

    return 0;
}
