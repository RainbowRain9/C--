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
        cout << a << "=";
        bool b = true;
        while (a % 2 == 0)
        {
            if (!b)
            {
                cout << "*";
            }
            cout << "2";
            b = false;
            a = a / 2;
        }
        for (long long i = 3; i * i <= a; i += 2)
        {
            while (a % i == 0)
            {
                if (!b)
                {
                    cout << "*";
                }
                cout << i;
                b = false;
                a = a / i;
            }
        }
        if (a > 2)
        {
            if (!b)
            {
                cout << "*";
            }
            cout << a;
        }

        cout << endl;
    }

    return 0;
}