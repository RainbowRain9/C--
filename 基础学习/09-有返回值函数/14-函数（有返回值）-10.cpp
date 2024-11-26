/*
描述
编写两个函数，分别求两个正整数的最大公约数和最小公倍数。
在主函数输入两个正整数，分别输出它们的最大公约数和最小公倍数。


输入
一个正整数n，表示n组案例。

每组案例由两个正整数a和b构成。

输出
针对每组案例，输出a和b的最大公约数和最小公倍数，用空格相隔。

每组案例输出完都要换行。

样例输入
2

2 3

8 10

样例输出
1 6

2 40

提示说明
辗转相除法
*/

#include <iostream>  // 引入C++的输入输出流库
using namespace std; // 使用std命名空间，避免每次调用cout、cin等时都需要写std::

// 计算最大公约数
int GCD(int a, int b) {
    while (b != 0) {
        int temp = b; // 临时存储b的值
        b = a % b;    // 计算a除以b的余数，并赋值给b
        a = temp;     // 将b的原始值赋给a
    }
    return a; // 当b为0时，a即为最大公约数
}

// 计算最小公倍数
int LCM(int a, int b) {
    return (a * b) / GCD(a, b); // 使用最大公约数计算最小公倍数
}

int main() {
    int n;
    cin >> n; // 读取案例的数量

    while (n--) { // 循环处理每个案例
        int a, b;
        cin >> a >> b; // 读取两个整数
        cout << GCD(a, b) << " " << LCM(a, b) << endl; // 输出它们的GCD和LCM
    }

    return 0; // 程序结束
}
