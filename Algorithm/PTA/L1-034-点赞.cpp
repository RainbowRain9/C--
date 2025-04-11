/*
 * @Author: RainbowRain9
 * @Date: 2025-04-07 22:55:46
 * @LastEditTime: 2025-04-07 23:10:34
 * @FilePath: \C++\Algorithm\PTA\L1-034-点赞.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 微博点赞功能可以反映用户特性。给定用户点赞的博文及其特性标签，
 * 统计最常出现的特性标签及其出现次数。如果出现次数相同，则输出编号最大的标签。
 *
 * 示例 1：
 *   输入：
 *   4
 *   3 889 233 2
 *   5 100 3 233 2 73
 *   4 3 73 889 2
 *   2 233 123
 *   输出：
 *   233 3
 *   解释：标签233出现次数最多，共出现3次
 *
 * 示例 2：
 *   输入：
 *   3
 *   2 1 2
 *   2 2 3
 *   2 3 1
 *   输出：
 *   3 2
 *   解释：标签1、2、3都出现2次，输出编号最大的3
 *
 * 提示：
 *   - 特性标签编号范围1-1000
 *   - 每篇博文特性标签数量1-10
 *   - 用户点赞博文数量≤1000
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
    array<int, 1001> cnt = { 0 };
    while (n--) {
        int m;
        cin >> m;
        while (m--) {
            int k;
            cin >> k;
            cnt[k]++;
        }
    }
    int max_tag = 0;
    int max_count = 0;
    for (int tag = 1; tag < 1001; tag++) {
        max_count = max(max_count, cnt[tag]);
        if (tag > max_tag && max_count == cnt[tag]) {
            max_tag = tag;
        }
    }
    cout << max_tag << " " << max_count << endl;

    return 0;
}