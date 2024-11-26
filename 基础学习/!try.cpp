#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int x = 1;
    while (n >= 10)
    {
        while (n != 0)
        {
            int a = n % 10;
            sum += a;
            x = x * a;
            n /= 10;
        }
        n = sum;
    }

    cout << x-sum;
}