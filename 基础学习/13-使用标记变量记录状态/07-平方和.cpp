/*
描述
验证某个正整数m是否可以表示成若干个互不相同正整数的平方和

输入
一个正整数n，表示有n组案例。

每组案例由一个正整数m组成。（m<=1000000）

输出
针对每组案例，如果m能表示成多个（可以是一个，也可以不止一个）互不相同整数的平方和，那么输出Yes，否则输出No。

每组案例输出完都要换行。

样例输入
3

14

15

16

样例输出
Yes

No

Yes

提示说明
14=1*1+2*2+3*3

16=4*4
*/

#include<iostream>
using namespace std;

// 全局变量flag，用于标记是否找到满足条件的平方和
bool flag = false;

// 递归函数f，用于判断整数x是否可以表示为不同正整数平方和的总和
void f(int x, int y) {
    if (x == 0) {
        // 如果x减至0，说明找到了一个有效的平方和表示，设置flag为true
        flag = true;
        return;
    }
    for (int i = y + 1; i <= 1000; i++) {
        // 从y+1开始，尝试所有可能的正整数平方
        if (x - i * i >= 0) {
            // 如果x减去i的平方后仍然非负，递归调用f函数
            f(x - i * i, i);
            if (flag == true) {
                // 如果在递归过程中找到了有效的平方和表示，返回
                return;
            }
        } else {
            // 如果x减去i的平方后为负，说明i的平方太大，跳出循环
            break;
        }
    }
}

int main() {
    int n; // 测试案例的数量
    cin >> n; // 读取测试案例的数量
    while (n--) { // 对于每个测试案例
        int a; // 待验证的正整数
        flag = false; // 重置flag为false
        cin >> a; // 读取待验证的正整数
        f(a, 0); // 调用函数f开始验证
        if (flag) {
            cout << "Yes"; // 如果找到了有效的平方和表示，输出Yes
        } else {
            cout << "No"; // 否则输出No
        }
        cout << endl; // 每个测试案例输出后换行
    }
    return 0; // 程序结束
}        