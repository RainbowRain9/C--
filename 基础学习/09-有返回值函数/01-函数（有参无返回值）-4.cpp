/*
描述
输入一个正整数n和一个字符c，利用函数输出n行由字符c组成的V字图案。

输入
一个正整数n和一个字符c

输出
n行由字符c组成的V字图案。每行最后一个字符c后面不要输出空格，直接换行。

样例输入
5 +

样例输出
+       +
 +     +
  +   +
   + +
    +

提示说明
函数的声明应该是void f(int n, char c);
*/

#include <iostream>
using namespace std;

// 定义函数f，用于输出V字图案
void f(int n, char c) {
    for (int i = 1; i <= n; i++) { // 外层循环控制行数
        for (int j = 1; j < i; j++) { // 输出前半部分的空格
            cout << " ";
        }
        cout << c; // 输出字符c
        for (int j = 1; j <= 2 * (n - i) - 1; j++) { // 输出中间的空格
            cout << " ";
        }
        if (i != n) { // 如果不是最后一行，输出字符c
            cout << c;
        }
        cout << endl; // 换行
    }
}

int main() {
    int n;
    char c;
    cin >> n >> c; // 输入正整数n和字符c
    f(n, c); // 调用函数f输出V字图案
    return 0;
}
