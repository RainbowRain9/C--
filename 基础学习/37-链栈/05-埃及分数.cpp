// Source : https://xujcoj.com/home/contest/1957/problem/5
// Date   : 2024-11-14

#include <iostream>
#include <vector>

using namespace std;

// 计算两个数的最大公约数并约分
// 参数:
// A: 第一个数(引用传递)
// B: 第二个数(引用传递)
// 返回值: 最大公约数
int CommFactor(int &A, int &B)
{
    int a = A, b = B, r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    A /= a;
    B /= a;
    return a;
}

// 将一个分数转换为埃及分数表示
// 参数:
// A: 分子
// B: 分母
void EgyptFraction(int A, int B)
{
    // 存储单位分数的分母
    vector<int> denominators;

    // 打印原始分数
    cout << A << "/" << B << " = ";

    // 当分子不为0时继续分解
    while (A != 0)
    {
        // 计算当前最大单位分数的分母
        int unit_fraction = (B + A - 1) / A;
        denominators.push_back(unit_fraction);

        // 更新分子分母
        A = A * unit_fraction - B;
        B = B * unit_fraction;

        // 约分
        CommFactor(A, B);
    }

    // 打印结果
    for (size_t i = 0; i < denominators.size(); ++i)
    {
        cout << "1/" << denominators[i];
        if (i < denominators.size() - 1)
        {
            cout << " + ";
        }
    }
    cout << endl;
}

int main()
{
    int numerator, denominator;
    // 输入分子和分母
    cin >> numerator >> denominator;

    // 转换为埃及分数并输出
    EgyptFraction(numerator, denominator);

    return 0;
}