#include<iostream>
using namespace std;

int main() {
    int m, n, p;

    cin >> m >> n >> p;

    // 检查p是否处于m和n之间
    if (p > m && p < n) {
        cout << "1";
    } else {
        cout << "0";
    }

    return 0;
}