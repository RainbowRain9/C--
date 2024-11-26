#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        long long p, q;
        cin >> p >> q;

        long long count = 0;
        long long sum = 0;

        for (long long i = -50000; i <= 50000; i++)
        {
            long long result = i * (i + 1);

            if (result >= p && result <= q)
            {
                count++;
                sum += result;
            }

            if (result > q && i > 0)
                break;
        }

        cout << count / 2 << " " << sum / 2 << endl;
    }

    return 0;
}