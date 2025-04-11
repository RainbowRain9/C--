#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int N = 1e7 + 5;

int sieve(int n) {
	vector<bool> p(n,true);

	p[0] = p[1] = false;
	for (long long i = 2; i * i <= n; i++) {
		if (p[i]) {
			for(int j = i * i; j <=n ; j += i) {
				p[j] = false;
			}
		}
	}
}

int qpow(int a, int b) {
	int res = 1;
	while(b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}


void rain() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int& num : nums) {
		cin >> num;
	}
	sort(all(nums));
	do {
		for (int num:nums) {
			cout << num << " ";
		}
		cout << endl;
	} while(next_permutation(all(nums)));
}

signed main() {
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t--) {
		rain();
	}
	return 0;
}
