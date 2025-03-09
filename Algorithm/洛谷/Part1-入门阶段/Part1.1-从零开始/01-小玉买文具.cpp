/*https://www.luogu.com.cn/problem/P1421*/

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    double price = a + 0.1 * b;
    int count = (a + 0.1 * b) / 1.9;
    cout << count;

    return 0;
}