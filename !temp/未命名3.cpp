#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	double d;
	cin >> n >> d;
	unsigned long long m = pow(2,n);
	unsigned long long a = ceil(m * d);
	cout << a;

	return 0;
}

