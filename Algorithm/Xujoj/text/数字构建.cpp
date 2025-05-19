#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

vector<string> words = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };

void solve()
{
    string s;
    cin >> s;
    vector<bool> ava(26);
    for (char c : s) {
        ava[c - 'a'] = true;
    }
    int count = 0;
    for (string word : words) {
        bool f = true;
        for (char w : word) {
            if (!ava[w - 'a']) {
                f = false;
                break;
            }
        }
        if (f) {
            count++;
        }
    }
    cout << count << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}