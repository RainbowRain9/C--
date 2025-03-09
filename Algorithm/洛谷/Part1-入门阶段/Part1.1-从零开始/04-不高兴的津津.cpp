/*https://www.luogu.com.cn/problem/P1085*/

#include <iostream>
using namespace std;

int main()
{
    bool happy = true;
    int sum = 0;
    int day;
    for (int i = 1; i <= 7; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        if (t1 + t2 > 8)
        {
            happy = false;
            if (sum < t1 + t2)
            {
                sum = t1 + t2;
                day = i;
            }
        }
    }
    if (happy)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << day << endl;
    }

    return 0;
}