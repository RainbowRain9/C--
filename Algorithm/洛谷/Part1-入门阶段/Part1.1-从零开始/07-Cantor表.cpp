/*https://www.luogu.com.cn/problem/P1014*/

#include <iostream>
using namespace std;

int main()
{
    long long N;
    cin >> N;
    long long count = 0;
    while (N > 0)
    {
        count++;
        N -= count;
    }

    if (count % 2 == 0)
    {
        cout << count + N << "/" << 1 - N << endl;
    }
    else
    {
        cout << 1 - N << "/" << count + N << endl;
    }

    return 0;
}