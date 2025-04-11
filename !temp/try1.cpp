#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
vector<bool> p(MOD);

void sieve(int n) {
	p.assign(n, true);
	p[0] = p[1] = false;
	for(int i = 2; i * i <= n; i++) {
		if (p[i]) {
			for (int j = i * i; j <= n; j += i) {
				p[j] = false;
			}
		}
	}
}

ll qpow(ll a, ll b) {
	int res = 1;
	while(b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

void np(vector<int> nums) {
	sort(all(nums));
	do {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	} while(next_permutation(all(nums)));
}

void rain() {
	int n;
	cin >> n;
//	vector<int> nums(n);
//	for (auto & num : nums) {
//		cin >> num;
//	}
//	np(nums);

//	sieve(n);
//	for(int i = 0; i <= n; i++) {
//		if (p[i]) cout << i << " ";
//	}

	cout << qpow(2,n);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _ = 1;
//	cin >> _;
	while (_--) {
		rain();
	}
	return 0;
}
