#include <iostream>
using namespace std;

string whoWins(int m)
{
    return (m & (m + 1)) == 0 ? "Bob" : "Alice";
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        cout << whoWins(m) << endl;
    }
    return 0;
}