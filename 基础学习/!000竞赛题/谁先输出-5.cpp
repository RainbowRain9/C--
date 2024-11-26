#include <iostream>
using namespace std;

int countFactors(int num)
{
    int count = 0;
    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            count++;
            if (i * i != num)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        long long a, b;
        cin >> a >> b;

        int f1 = countFactors(a);
        int f2 = countFactors(b);

        if (f1 > f2)
        {
            cout << a << " " << b << endl;
        }
        else if (f2 > f1)
        {
            cout << b << " " << a << endl;
        }
        else
        {
            if (a > b)
            {
                cout << a << " " << b << endl;
            }
            else
            {
                cout << b << " " << a << endl;
            }
        }
    }

    return 0;
}