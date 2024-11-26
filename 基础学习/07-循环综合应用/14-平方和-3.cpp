/*
描述
    已知一个正整数x，问x能否凑成三个互不相同的正整数的平方和。

输入
    一个正整数n，表示测试案例的数量。
    每组案例由一个正整数x组成（x不大于1e+8）。

输出
    针对每组案例，如果x可以表示成三个互不相同的正整数的平方和，那么输出Yes，否则输出No。
    每组案例输出完都要换行。

    样例输入
    2
    30
    10

样例输出
    Yes
    No

提示说明
    30=1*1+2*2+5*5
*/

#include <iostream> // 包含输入输出流库
#include <cmath>    // 包含数学函数库，用于计算平方根

using namespace std; // 使用标准命名空间

int main()
{
    int n;    // 存储测试案例的数量
    cin >> n; // 从标准输入读取测试案例的数量

    while (n--)
    {                    // 对于每个测试案例
        long long int x; // 存储当前案例的正整数x
        cin >> x;        // 从标准输入读取正整数x

        // 如果x小于3的平方，直接输出No
        if (x < 14)
        {
            cout << "No" << endl; // 输出No并换行
        }
        else
        {
            // 如果x不小于3的平方且是奇数，尝试找到三个互不相同的正整数的平方和等于x
            bool found = false; // 初始化找到的标记为false
            for (long long int i = 1; i * i < x && !found; ++i)
            { // 从1开始遍历正整数i
                for (long long int j = i; j * j + i * i < x && !found; ++j)
                { // 从i开始遍历正整数j
                    // 计算第三个数的平方根
                    long long int k = sqrt(x - (i * i + j * j));
                    // 检查k是否是整数且不等于i和j
                    if (k * k == x - (i * i + j * j) && k != i && j != k && i != j)
                    {
                        // 如果找到了三个互不相同的正整数的平方和等于x，设置标记为true
                        found = true;
                    }
                }
            }
            // 如果找到了这样的组合，输出Yes，否则输出No
            if (found)
            {
                cout << "Yes" << endl; // 输出Yes并换行
            }
            else
            {
                cout << "No" << endl; // 输出No并换行
            }
        }
    }

    return 0; // 程序结束
}