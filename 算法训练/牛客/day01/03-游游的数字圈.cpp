#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    for (char c : s)
    {
        if (c == '0' || c == '6' || c == '9')
            cnt++;
        if (c == '8')
            cnt += 2;
    }
    cout << cnt;

    return 0;
}