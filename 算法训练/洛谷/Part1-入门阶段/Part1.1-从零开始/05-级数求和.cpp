/*https://www.luogu.com.cn/problem/P1035*/

#include <iostream>
using namespace std;

int main()
{
    double k, n = 1;
    double S = 0;
    cin >> k;
    while (1)
    {
        S += 1 / (n++);
        if (S > k)
        {
            cout << n - 1;
            break;
        }
    }

    return 0;
}