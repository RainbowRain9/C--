/*
描述
    判断一个数字是不是既大于10，又是3的倍数。

输入
    一个正整数n，表示有n组案例。

    在每组案例中有一个整数a，表示要判断的数字。

输出
    针对每组案例，如果a既大于10，又是3的倍数，则输出Yes，否则输出No。每组案例输出完都要换行。

样例输入
    3
    9
    12
    14

样例输出
    No
    Yes
    No
*/

#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a > 10 && a % 3 == 0)
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
        cout << endl;
    }
    
    return 0;
}