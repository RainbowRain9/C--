/*https://www.luogu.com.cn/problem/P1980*/

#include <iostream>
using namespace std;

int main()
{
    long long n, x, b, c;
    int count = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        b = i;
        while (b != 0)
        {
            c = b % 10;
            b = b / 10;
            if (c == x)
                count++;    
        }
    }
    cout << count;
    return 0;
}