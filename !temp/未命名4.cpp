#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 计算两个数的最小公倍数
ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;  // 先除后乘防止溢出
}

// 计算三个数的最小公倍数
ll lcm(ll a, ll b, ll c) {
    return lcm(a, lcm(b, c));
}

// 计算精美程度S
long double S(ll a, ll b, ll c) {
    // 确保a <= b <= c
    vector<ll> v = {a, b, c};
    sort(v.begin(), v.end());
    a = v[0]; b = v[1]; c = v[2];
    
    long double total = a * b * c;
    long double lcm_abc = lcm(a, b, c);
    long double lcm_ab = lcm(a, b);
    long double lcm_ac = lcm(a, c);
    long double lcm_bc = lcm(b, c);
    
    return total * lcm_abc / (lcm_ab * lcm_ac * lcm_bc);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<ll> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    long double max_s = 0;
    ll ans_a = LLONG_MAX, ans_b = LLONG_MAX, ans_c = LLONG_MAX;
    const long double EPS = 1e-15;
    
    // 三重循环枚举所有可能的组合
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                // 对三个数排序
                vector<ll> curr = {nums[i], nums[j], nums[k]};
                sort(curr.begin(), curr.end());
                
                long double cur_s = S(curr[0], curr[1], curr[2]);
                
                // 如果当前S值更大，或S值相等但字典序更小
                if(cur_s > max_s + EPS || 
                   (abs(cur_s - max_s) <= EPS && 
                    (curr[0] < ans_a || 
                     (curr[0] == ans_a && curr[1] < ans_b) ||
                     (curr[0] == ans_a && curr[1] == ans_b && curr[2] < ans_c)))) {
                    max_s = cur_s;
                    ans_a = curr[0];
                    ans_b = curr[1];
                    ans_c = curr[2];
                }
            }
        }
    }
    
    cout << ans_a << " " << ans_b << " " << ans_c << endl;
    
    return 0;
}