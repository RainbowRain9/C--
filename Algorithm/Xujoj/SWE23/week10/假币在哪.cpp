/*
 * @Author: RainbowRain9
 * @Date: 2025-05-05 15:32:04
 * @LastEditTime: 2025-05-05 16:07:10
 * @FilePath: \C++\Algorithm\Xujoj\SWE23\week10\假币在哪.cpp
 * @Description:
 */
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
void rain()
{
    struct Weighing {
        string left;
        string right;
        string result;
    };

    auto check = [&](char fake_coin, bool is_heavy, const vector<Weighing>& weighings) -> bool {
        for (const auto& w : weighings) {
            string expected_result;
            bool left_has_fake = (w.left.find(fake_coin) != string::npos);
            bool right_has_fake = (w.right.find(fake_coin) != string::npos);

            if (!left_has_fake && !right_has_fake) {
                expected_result = "EVEN";
            } else if (left_has_fake) {
                if (is_heavy) {
                    expected_result = "UP";
                } else {
                    expected_result = "DOWN";
                }
            } else {
                if (is_heavy) {
                    expected_result = "DOWN";
                } else {
                    expected_result = "UP";
                }
            }

            if (expected_result != w.result) {
                return false;
            }
        }
        return true;
    };

    vector<Weighing> weighings(3);
    for (int i = 0; i < 3; ++i) {
        cin >> weighings[i].left >> weighings[i].right >> weighings[i].result;
    }

    for (char c = 'A'; c <= 'L'; ++c) {
        if (check(c, true, weighings)) {
            cout << c << " is fake and it is heavy." << endl;
            return;
        }
        if (check(c, false, weighings)) {
            cout << c << " is fake and it is light." << endl;
            return;
        }
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