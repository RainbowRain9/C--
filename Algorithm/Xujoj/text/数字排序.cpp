#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

int dot(string str)
{
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            return i;
        }
    }
    return str.length();
}

void solve()
{
    int n;
    cin >> n;
    vector<string> str(n);
    for (string& i : str) {
        cin >> i;
    }

    sort(str.begin(), str.end(), [](const string& a, const string& b) {
        size_t dot_a = dot(a);
        size_t dot_b = dot(b);

        string int_a = a.substr(0, dot_a);
        string int_b = b.substr(0, dot_b);

        if (int_a.length() != int_b.length())
            return int_a.length() < int_b.length();

        if (int_a != int_b)
            return int_a < int_b;

        return a < b;
    });

    for (const string& s : str) {
        cout << s << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}