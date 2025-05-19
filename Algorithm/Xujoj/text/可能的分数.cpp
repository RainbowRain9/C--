#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

void rain()
{
    int a, b;
    cin >> a >> b;
    vector<int> sc(a);
    for (int& i : sc) {
        cin >> i;
    }
    sort(all(sc));
    set<int> possible;
    
    for (int correct = b; correct <= a; correct++) {
        vector<bool> v(a, false);
        for (int i = 0; i < correct; i++) {
            v[i] = true;
        }
        
        do {
            int sum = 0;
            for (int i = 0; i < a; i++) {
                if (v[i]) sum += sc[i];
            }
            possible.insert(sum);
        } while (prev_permutation(all(v)));
    }
    
    for (int score : possible) {
        cout << score << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        rain();
    }
    return 0;
}