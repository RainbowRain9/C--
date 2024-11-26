/*
描述
    根据两个整数的大小关系，输出>、<或者=

输入
    1个正整数n，表示测试案例的数量。

    每组测试案例中，有两个整数a和b。

输出
    针对每组案例，如果a比b大，则输出>；如果a比b小，则输出<；如果a和b相等，则输出=。每组案例输出后都要换行。

样例输入
    2
    3 5
    2 2

样例输出
    <
    =
*/

#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        if (a > b)
        {
            cout << ">";
        }
        else if (a < b)
        {
            cout << "<";
        }
        else
        {
            cout << "=";
        }
        cout << endl;
    }
    
    return 0;
}