#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    int odd = 0, even = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    if ((odd >= 1 && even >= 2) || odd >= 3)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}