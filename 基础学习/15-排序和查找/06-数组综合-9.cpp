/*
描述
确定一堆数字中有没有某个特定的值。

输入
一个正整数n，表示有n组案例。

每组案例中，先是一个正整数m，然后是m个整数，最后是一个整数key。

输出
针对每组案例，如果这m个整数中有某个数字等于key，则输出true，否则输出false。

每组案例输出完都要换行。

样例输入
2

5 1 2 3 4 5 3

5 1 2 3 4 5 10

样例输出
true

false
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        int *a = new int[m];
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        int key;
        cin >> key;
        bool t = false;
        for (int i = 0; i < m; i++)
        {
            if (a[i] == key)
            {
                t = true;
            }
        }
        if (t)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
        delete []a;
    }
    return 0;
}