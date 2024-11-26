/*
描述
输入0~9之间的整数，输出其对应的英文单词。


输入
一个正整数n，表示n组案例。

每组案例由一个0~9之间的整数构成。

输出
针对每组案例，输出数字对应的英文单词。

每组案例输出完都要换行。

样例输入
2

0

5

样例输出
zero

five
*/

#include <iostream>
using namespace std;

int main() {
    int n; // 测试案例的数量
    cin >> n; // 读取测试案例的数量
    while (n--) { // 对于每个测试案例
        int num; // 定义一个整数变量num来存储输入的数字
        cin >> num; // 读取输入的数字
        // 根据输入的数字输出对应的英文单词
        switch (num) {
            case 0: cout << "zero" << endl; break;
            case 1: cout << "one" << endl; break;
            case 2: cout << "two" << endl; break;
            case 3: cout << "three" << endl; break;
            case 4: cout << "four" << endl; break;
            case 5: cout << "five" << endl; break;
            case 6: cout << "six" << endl; break;
            case 7: cout << "seven" << endl; break;
            case 8: cout << "eight" << endl; break;
            case 9: cout << "nine" << endl; break;
        }
    }
    return 0; // 程序结束
}