/*https://www.luogu.com.cn/problem/P1046*/

#include <iostream>
using namespace std;

int main()
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    int h, num = 0;
    cin >> h;
    h += 30;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] <= h)
        {
            num++;
        }
    }
    cout << num;

    return 0;
}