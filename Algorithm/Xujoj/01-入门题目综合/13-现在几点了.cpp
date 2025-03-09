/*
问题描述
输出现在的时间（精确到分钟）

输入描述
无

输出描述
现在的时间（格式见样例）

样例输入
样例输出
2020/4/18 15:00

提示说明
看右下角
*/
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
    // 获取当前时间
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // 输出格式化的时间
    cout << 1900 + ltm->tm_year << '/'
         << setfill('0') << setw(2) << 1 + ltm->tm_mon << '/'
         << setfill('0') << setw(2) << ltm->tm_mday << ' '
         << setfill('0') << setw(2) << ltm->tm_hour << ':'
         << setfill('0') << setw(2) << ltm->tm_min << endl;

    return 0;
}