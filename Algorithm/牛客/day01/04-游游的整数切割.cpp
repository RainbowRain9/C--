#include <iostream>
using namespace std;

int main()
{
    string a;
    cin >> a;
    int cnt = 0;
    int last = a.back() - '0';
    for (int i = 0; i < a.length() - 1; i++)
    {
        if ((a[i] - '0' + last) % 2 == 0)
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}