#include <iostream>
using namespace std;
int f(int x, int y)
{
    if (x == 0)
        return 1;
    if (y == 1)
        return 1;
    if (x < y)
        return f(x, x);
    return f(x, y - 1) + f(x - y, y);
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << f(x, y) << endl;
    return 0;
}