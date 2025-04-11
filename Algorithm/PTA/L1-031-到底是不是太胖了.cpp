/*
 * @Author: RainbowRain9
 * @Date: 2025-04-07 21:19:57
 * @LastEditTime: 2025-04-07 21:37:38
 * @FilePath: \C++\Algorithm\PTA\L1-031-到底是不是太胖了.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 计算一个人的标准体重（身高-100）*0.9，判断真实体重与标准体重的误差是否在10%以内。
 * 已知1公斤=2市斤，根据输入的身高和体重（市斤），判断是否太胖或太瘦。
 *
 * 输入格式：
 * 第一行正整数N（≤20），随后N行每行两个整数：身高H（120<H<200）和体重W（50<W≤300）
 *
 * 输出格式：
 * 对每个人输出一行结论：
 * 完美身材：You are wan mei!
 * 太胖：You are tai pang le!
 * 太瘦：You are tai shou le!
 *
 * 示例 1：
 *   输入：
 *   3
 *   169 136
 *   150 81
 *   178 155
 *   输出：
 *   You are wan mei!
 *   You are tai shou le!
 *   You are tai pang le!
 *   解释：
 *   169cm标准体重62.1kg（124.2市斤），136市斤在误差范围内
 *   150cm标准体重45kg（90市斤），81市斤低于标准
 *   178cm标准体重70.2kg（140.4市斤），155市斤高于标准
 *
 * 提示：
 *   - 注意单位转换：1公斤=2市斤
 *   - 标准体重公式：(身高-100)*0.9
 *   - 误差范围：|真实体重-标准体重| < 标准体重*10%
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
    int n;
    cin >> n;
    while (n--) {
        double h, r;
        cin >> h >> r;
        double w = (h - 100) * 0.9 * 2;
        if (abs(w - r) < w * 0.1) {
            cout << "You are wan mei!" << endl;
        } else {
            if (r < w) {
                cout << "You are tai shou le!" << endl;
            } else {
                cout << "You are tai pang le!" << endl;
            }
        }
    }
    return 0;
}