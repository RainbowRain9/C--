/*
 * @Author: RainbowRain9
 * @Date: 2025-03-17 15:30:47
 * @LastEditTime: 2025-03-17 15:50:36
 * @FilePath: \C++\Algorithm\Xujoj\SWE23\week4\02-integer-sort.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 设有n个正整数，将他们连接成一排，组成一个最大的多位整数，整数不能拆分。
 *
 * 示例 1：
 *   输入：3
 *        12 345 678
 *   输出：67834512
 *   解释：将678、345、12按此顺序连接可以得到最大的整数67834512
 *
 * 示例 2：
 *   输入：4
 *        3 32 321 3214
 *   输出：3432132132
 *   解释：将3、32、321、3214按此顺序连接可以得到最大的整数3432132132
 *
 * 提示：
 *   - 2 <= n <= 10
 *   - 每个整数介于1和32767之间
 *   - 整数不能拆分，必须完整使用
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
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    auto cmp = [](string &a, string &b) {
        return a + b > b + a;
    };

    sort(nums.begin(), nums.end(), cmp);

    string result;
    for (string &num : nums) {
        result += num;
    }

    cout << result << endl;

    return 0;
}