#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int count = 0;

        if (a + b == c)
        {
            count++;
        }
        if (a - b == c)
        {
            count++;
        }
        if (a * b == c)
        {
            count++;
        }

        if (b != 0 && a % b == 0 && a / b == c)
        {
            count++;
        }

        cout << count << endl;
    }

    return 0;
}