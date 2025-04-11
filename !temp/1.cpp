#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 13, m = 5;
//	cin >> n >> m;
	vector<int> a(n);
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
	vector<int> b(n);
	for (int k = 1; k <= n; k++) {
		string s = to_string(a[k]);
		int sum = 0;
		for (char i : s) {
			int j = i - '0';
			sum += j;
		}
		b[k] = sum;
	}
	int idx = distance(b.begin(), max_element(b.begin(), b.end()));
	int max_b = b[idx];
	
	vector<int> c(n);
	int cnt = 1;
	for (int j = 1; j <= max_b; j++) {
		for (int i = 1; i <= n; i++) {
			if (b[i] == j) {
				c[cnt++] = j;
			}
		}
	}
	cout << c[m];
}
