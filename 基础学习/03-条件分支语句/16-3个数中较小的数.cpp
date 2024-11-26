#include<iostream>
using namespace std;

int main() {
    int a, b, c, temp;

    // 输入三个整数
    cin >> a >> b >> c;

    // 比较并排序
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (a > c) {
        temp = a;
        a = c;
        c = temp;
    }
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }

    // 输出排序后的整数
    cout << a;

    return 0;
}