#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());
	for (auto i : a) {
		cout << i << (i == a.back() ? "" : " ");
	}
	return 0;
}
