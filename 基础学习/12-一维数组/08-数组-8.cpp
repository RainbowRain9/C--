/*
描述
写一个函数用于根据参数传入的年月日，返回该天是所在年份的第几天。在主函数中输入年月日，通过调用函数，在主函数中输出结果。


输入
一个正整数n，表示n组案例。

每组案例由三个整数a、b、c构成，其中a代表年份，b代表月份，c代表日期。
（1<=a<=3199，a、b、c组成的日期是合法的）

输出
针对每组案例，输出一个整数，表示a年b月c日是所在年份的第几天。

每组案例输出完都要换行。

样例输入
2

2017 12 31

2018 1 5

样例输出
365

5
*/
#include <iostream>
using namespace std;

// 判断是否为闰年的函数
bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0; // 整百年必须是400的倍数才是闰年
        } else {
            return true; // 非整百年的年份，能被4整除就是闰年
        }
    } else {
        return false; // 不能被4整除的年份不是闰年
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int year, month, day;
        cin >> year >> month >> day;
        int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // 判断是否为闰年，并调整2月的天数
        if (isLeapYear(year)) {
            daysInMonth[2] = 29;
        }

        int sum = 0;
        // 累加之前月份的天数
        for (int j = 0; j <= month - 1; j++) {
            sum += daysInMonth[j];
        }
        // 加上当前月份的天数
        sum += day;

        cout << sum << endl;
    }
    
    return 0;
}