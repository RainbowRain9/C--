/*
 * @Author: RainbowRain9
 * @Date: 2025-04-09 19:55:41
 * @LastEditTime: 2025-04-09 20:34:16
 * @FilePath: \C++\Algorithm\PTA\L1-058-6翻了.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 将句子中连续的6替换成更高级的表达:
 * - 3个以上连续的6替换成9
 * - 9个以上连续的6替换成27
 * - 其他内容保持不变
 *
 * 示例 1：
 *   输入：it is so 666 really 6666 what else can I say 6666666666
 *   输出：it is so 666 really 9 what else can I say 27
 *   解释：
 *   - "666" 不足4个6,保持原样
 *   - "6666" 超过3个6,替换成9
 *   - "6666666666" 超过9个6,替换成27
 *
 * 提示：
 *   - 输入为不超过1000个字符的字符串
 *   - 字符串只包含英文字母、数字和空格
 *   - 需要从左到右扫描处理连续的6
 **************************************************/

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    string s;
    // 直接读取整行输入
    getline(cin, s);

    // 遍历整个输入字符串
    for (int i = 0; i < s.length(); ++i) {
        // 检查当前字符是否为 '6'
        if (s[i] == '6') {
            int count = 0;
            int start_index = i; // 记录连续 '6' 的起始位置

            // 向后查找并统计连续 '6' 的数量
            while (i < s.length() && s[i] == '6') {
                count++;
                i++; // 移动索引到下一个字符
            }

            // 根据连续 '6' 的数量决定输出内容
            if (count > 9) {
                cout << "27";
            } else if (count > 3) {
                cout << "9";
            } else {
                // 如果数量不足以替换，则输出原始的 '6' 序列
                for (int j = 0; j < count; ++j) {
                    cout << '6';
                }
            }

            // 外层循环的 i 已经被内层 while 更新到连续 '6' 序列之后了
            // 但是 for 循环末尾还有一个 i++，所以需要将 i 减 1 来抵消
            // 这样下一轮循环开始时 i 会指向正确的位置（紧跟在 '6' 序列后的那个字符）
            i--;

        } else {
            // 如果当前字符不是 '6'，直接输出
            cout << s[i];
        }
    }

    // 通常竞技平台要求最后输出一个换行符
    cout << endl;

    return 0;
}