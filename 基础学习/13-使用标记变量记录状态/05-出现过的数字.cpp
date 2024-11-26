/*
描述
输入m个整数，问1到10000之间有多少个数字至少出现过一次。

输入
一个正整数n，表示有n组案例。

每组案例先是一个正整数m，然后是m个整数。

输出
针对每组案例，输出一个整数，表示在输入的m个整数中，1到10000之间有多少个数字至少出现过一次。

每组案例输出后都要换行。

样例输入
1

5 1 1 3 0 3

样例输出
2

提示说明
在输入的5个整数中，1和3都是1到10000之间的数字，0不属于该范围，所以一共有2个1到10000之间的数字出现过。
*/

#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;   
        int a[10001] = {0};
        int count = 0;
        for (int i = 1; i <= m; i++)
        {
            int b;
            cin >> b;
            if(b >= 1 && b <= 10000) a[b]++;
        }
        for (int i = 1; i <= 10000; i++)
        {
            if (a[i] > 0)
            {
                count++;
            }
            
        }
        cout << count << endl;
    }
    
    return 0;
}