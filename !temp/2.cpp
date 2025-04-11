#include <bits/stdc++.h>
using namespace std;

bool f(long long i) {
	if (i < 10 && i % 2 != 0) {
		return true;
	}
	string s = to_string(i); //123
	reverse(s.begin(), s.end()); //321
	bool t;
	for (int j = 0; j < s.size(); j++) { //12
		if (j % 2 == 0) {
			if (s[j] % 2 == 0) {
				return false;
			}
		} else {
			if (s[j] % 2 != 0) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	int cnt = 0;
	cin >> n;
	for(long long i = 1; i <= n; i++) {
		if(f(i)) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}

