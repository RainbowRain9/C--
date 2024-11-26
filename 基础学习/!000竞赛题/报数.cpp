#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b;
        int count = b - a;
        int sum1 = 0, sum2 = 0;
        for (int i = a; i <= b; i++)
        {
            sum1 += i;
        }
        for (int i = 0; i < count; i++)
        {
            int num;
            cin >> num;
            sum2 += num;
        }
        cout << sum1 - sum2 << endl;
    }
    return 0;
}