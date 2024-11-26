/*https://www.luogu.com.cn/problem/P1307*/

#include <iostream>
using namespace std;

int main()
{
    long long N;
    cin >> N;
    if (N == 0)
    { // 特判0
        cout << 0;
        return 0;
    }
    if (N < 0)
    {
        cout << "-";
        N = -N;
    }
    while (N % 10 == 0) // 处理前导0
        N = N / 10;
    while (N != 0)
    {
        cout << N % 10;
        N /= 10;
    }
    return 0;
}