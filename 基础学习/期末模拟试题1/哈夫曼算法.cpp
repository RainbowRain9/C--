#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x = n;
    int cnt = 0;
    while (x != 1)
    {
        cnt++;
        x /= 2;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i] * cnt;
    }
    cout << ans;

    return 0;
}