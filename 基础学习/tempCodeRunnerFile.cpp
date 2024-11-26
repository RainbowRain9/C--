#include <iostream>
using namespace std;

// 计算世纪
int calculateCentury(int year) {
    if (year < 0) { // 公元前
        return (-year + 99) / 100 + 1;
    } else { // 公元后
        return (year + 99) / 100;
    }
}

int main() {
    int a, b;
    cin >> a >> b;

    // 计算年份数量
    int years = 0;
    if (a <= 0 && b >= 0) {
        years = -a + b + 1; // 注意没有公元0年
    } else if (a <= 0 && b < 0) {
        years = b - a + 1;
    } else if (a > 0 && b > 0) {
        years = b - a + 1;
    }

    // 计算世纪数量
    int centuries = calculateCentury(b) - calculateCentury(a);

    cout << years << " " << centuries << endl;

    return 0;
}