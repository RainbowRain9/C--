#include<iostream>
using namespace std;

int main() {
    int m, n, p, temp;

    cin >> m >> n >> p;

    if (m > n) {
    int temp = m;
    m = n;
    n = temp;//m < n
}
    // 检查p是否处于m和n之间
    if (p > m && p < n) {
        cout << "1";
    } else {
        cout << "0";
    }

    return 0;
}