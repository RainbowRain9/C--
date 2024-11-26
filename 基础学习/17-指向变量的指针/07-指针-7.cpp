/*
描述
输入两个整数a和b，利用指针把第一个数变成a+b，第二个数变成a-b，输出这两个数。

输入
两个整数a和b

输出
利用指针把第一个数变成a+b，第二个数变成a-b，输出这两个数，用空格间隔，不要换行。

样例输入
3 5

样例输出
8 -2
*/

#include <iostream>
using namespace std;

void adjustValues(int *a, int *b) {
    int temp = *a + *b; // 计算a和b的和
    *b = *a - *b; // 由于a已经是a+b，我们可以通过a-b来计算新的b值
    *a = temp; // 将a的值更新为a+b
}

int main() {
    int a, b;
    cin >> a >> b; // 读取输入的两个整数
    adjustValues(&a, &b); // 调用函数，传入a和b的地址
    cout << a << " " << b; // 输出修改后的a和b，用空格间隔
    return 0;
}