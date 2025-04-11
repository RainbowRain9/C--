#include <bits/stdc++.h>
using namespace std;
int main() {
	long long a = 343720, b = 233333;
	double a1 = 343720, b1 =  233333;
//	cin >> a >> b;
	long long g = __gcd(a, b);
	cout << "gcd:" << g << endl;
	double x = 15, y = 17;
	double t1 = 13725.5;
	double x1 = 137838 / g;
	cout << t1 << " " << x1 << endl;
	double t2 = x1 / x;
	double y2 = 156216 / g;
	cout << t2 << " " << y2 << endl;

	return 0;
}
