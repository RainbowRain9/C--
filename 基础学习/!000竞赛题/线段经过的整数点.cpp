#include <iostream>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b)
{
    while (b)
    {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long long dx = abs(x2 - x1);
        long long dy = abs(y2 - y1);

        if (dx == 0 && dy == 0)
        {
            cout << 1 << endl;
            continue;
        }

        if (dy == 0)
        {
            cout << dx + 1 << endl;
            continue;
        }

        if (dx == 0)
        {
            cout << dy + 1 << endl;
            continue;
        }

        cout << gcd(dx, dy) + 1 << endl;
    }

    return 0;
}