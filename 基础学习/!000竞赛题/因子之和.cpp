#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long a;
        cin >> a;
        long long sum = 0;
        for (int i = 1; i * i <= a; i++)
        {
            if (a % i == 0)
            {
                sum += i;
                if (i * i != a)
                {
                    sum += a / i;
                }
            }
        }
        cout << sum << endl;
    }

    return 0;
}
