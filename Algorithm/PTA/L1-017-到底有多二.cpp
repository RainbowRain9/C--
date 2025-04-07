/*
 * @Author: RainbowRain9
 * @Date: 2025-04-02 20:46:19
 * @LastEditTime: 2025-04-02 22:02:32
 * @FilePath: \C++\Algorithm\PTA\L1-017-到底有多二.cpp
 * @Description: PTA L1-017 到底有多二 题目解答
 */
/**************************************************
 * 题目描述：
 * 计算一个整数"犯二的程度"，定义为该数字中包含2的个数与其位数的比值。
 * 如果是负数，则程度增加0.5倍；如果还是个偶数，则再增加1倍。
 * 最终结果以百分比形式输出，保留两位小数。
 *
 * 示例 1：
 *   输入：-13142223336
 *   输出：81.82%
 *   解释：这是一个11位数，有3个2，是负数且是偶数。
 *         计算过程：3/11 × 1.5 × 2 × 100% ≈ 81.82%
 *
 * 示例 2：
 *   输入：123456789
 *   输出：11.11%
 *   解释：这是一个9位数，有1个2，不是负数也不是偶数。
 *         计算过程：1/9 × 100% ≈ 11.11%
 *
 * 提示：
 *   - 输入整数不超过50位
 *   - 需要考虑负数和偶数的特殊情况
 *   - 结果保留两位小数，以百分比形式输出
 **************************************************/
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

/**
 * @brief 主函数，解决 PTA L1-017 问题
 * @details 读取一个字符串表示的整数，计算其"犯二程度"并按百分比输出。
 * @return int 程序退出码
 */
int main()
{
    string n;
    // 读取输入的数字字符串
    cin >> n;

    // 处理空输入或无效输入 "-"
    if (n.empty() || n == "-") {
        printf("0.00%%");
        return 0;
    }

    double count_of_2 = 0;      // 存储 '2' 的个数
    int total_digits = 0;       // 存储有效位数
    bool is_negative = false;   // 标记是否为负数

    // 判断是否为负数
    if (n[0] == '-') {
        is_negative = true;
        // 有效位数从索引 1 开始计算
        total_digits = n.length() - 1;
    } else {
        // 正数或 0，所有字符都是有效位
        total_digits = n.length();
    }

    // 统计 '2' 的个数
    for (char c : n) {
        if (c == '2') {
            count_of_2++;
        }
    }

    // 处理有效位数为 0 的情况 (理论上输入保证不为空，但健壮性考虑)
    // 例如 输入 "0"，total_digits 为 1
    if (total_digits == 0) {
         printf("0.00%%");
         return 0;
    }

    // 计算基础比率
    double degree = count_of_2 / total_digits;

    // 应用负数因子
    if (is_negative) {
        degree *= 1.5;
    }

    // 应用偶数因子
    // 获取最后一个字符（个位）并判断奇偶性
    char last_digit_char = n.back(); // 或者 n[n.length() - 1]
    // 将字符转换为整数
    int last_digit = last_digit_char - '0';
    if (last_digit % 2 == 0) {
        degree *= 2.0; // 使用 2.0 明确是 double 类型乘法
    }

    // 格式化输出结果
    printf("%.2f%%", degree * 100.0); // 使用 100.0 明确是 double 类型乘法

    return 0;
}