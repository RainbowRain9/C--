/*
描述
利用函数输出n行，奇数行是5个*，偶数行是5个#

输入
一个正整数n

输出
n行，奇数行是5个*，偶数行是5个#

样例输入
3

样例输出
*****

#####

*****

提示说明
  最后一行后也要换行
*/

#include <iostream>
using namespace std;

// 定义一个函数，用于输出指定数量的行
void printPattern(int n) {
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) { // 奇数行
            cout << "*****" << endl;
        } else { // 偶数行
            cout << "#####" << endl;
        }
    }
}

int main() {
    int n;
    cin >> n; // 输入正整数n
    printPattern(n); // 调用函数输出指定行数的图案
    return 0;
}
