#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}

long long countDivisible(long long n, long long d)
{
    return n / d;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        long long x, y, a, b, c;
        cin >> x >> y >> a >> b >> c;

        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ac = lcm(a, c);
        long long abc = lcm(ab, c);

        long long countY = y -
                           (y / a + y / b + y / c -
                            y / ab - y / bc - y / ac +
                            y / abc);

        long long countX = (x - 1) -
                           ((x - 1) / a + (x - 1) / b + (x - 1) / c -
                            (x - 1) / ab - (x - 1) / bc - (x - 1) / ac +
                            (x - 1) / abc);

        cout << (countY - countX) << endl;
    }

    return 0;
}