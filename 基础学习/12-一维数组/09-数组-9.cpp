/*
描述
求一堆整数的最大值、最小值、平均值

输入
一个正整数n，然后是n个整数

输出
这n个数的最大值、最小值、平均值（四舍五入到整数），中间各用一个空格间隔，最后一个数后不要有空格或者换行

样例输入
3

2 3 15

样例输出
15 2 7
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; // 读取整数的数量

    // 定义一个数组来存储n个整数
    int numbers[n];

    // 读取n个整数到数组中
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    // 初始化最大值、最小值和总和
    int maxVal = numbers[0];
    int minVal = numbers[0];
    float sum = 0;

    // 遍历数组，更新最大值、最小值和总和
    for (int i = 0; i < n; ++i) {
        sum += numbers[i]; // 累加每个整数到总和

        // 更新最大值
        if (numbers[i] > maxVal) {
            maxVal = numbers[i];
        }

        // 更新最小值
        if (numbers[i] < minVal) {
            minVal = numbers[i];
        }
    }

    // 计算平均值并四舍五入到整数
    int avgVal = sum / n + 0.5; // 由于整数除以整数结果还是整数，这里不需要四舍五入

    // 输出结果
    cout << maxVal << " " << minVal << " " << avgVal;

    return 0;
}