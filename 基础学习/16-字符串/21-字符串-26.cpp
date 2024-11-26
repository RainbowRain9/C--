/*
描述
输入1~12之间的整数，输出其对应的月份的英文单词。

输入
一个正整数n，表示n组案例。

每组案例由一个1~12之间的整数构成。

输出
针对每组案例，输出数字月份对应的英文单词。

每组案例输出完都要换行。

样例输入
2

1

5

样例输出
January

May
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;    // 测试案例的数量
    cin >> n; // 读取测试案例的数量
    while (n--)
    {                       // 对于每个测试案例
        int monthNumber;    // 定义一个整数变量来存储输入的月份数字
        cin >> monthNumber; // 读取输入的月份数字

        // 定义一个字符串数组来存储月份的英文名称
        string months[12] = {
            "January", "February", "March", "April",
            "May", "June", "July", "August",
            "September", "October", "November", "December"};

        // 检查输入的月份数字是否在1到12之间
        if (monthNumber >= 1 && monthNumber <= 12)
        {
            // 输出对应的月份英文名称
            cout << months[monthNumber - 1] << endl;
        }
    }
    return 0; // 程序结束
}