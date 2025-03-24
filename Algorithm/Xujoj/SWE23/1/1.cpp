/*
 * @Author: RainbowRain9
 * @Date: 2025-03-23 15:01:21
 * @LastEditTime: 2025-03-23 17:03:28
 * @FilePath: \C++\Algorithm\Xujoj\SWE23\1\1.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 一个由0到9构成的10位长整数，每个数字有且仅有使用一次，0不能作为最高位，
 * 相邻的数字不能出现在临近位置。例如1520873946是一个不满足条件的数字，
 * 因为7和8是相邻的数字，它们出现在了整数中临近的位置；
 * 1528073946是一个满足条件的数字。
 * 求满足条件的数字一共有多少个。
 *
 * 示例 1：
 *   输入：无
 *   输出：一个整数，表示满足条件的数字个数
 *   解释：需要统计所有满足条件的10位数的个数
 *
 * 提示：
 *   - 每个数字0-9只能使用一次
 *   - 0不能作为最高位
 *   - 相邻数字不能出现在相邻位置
 *   - 结果需要输出一个整数
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
    long long cnt = 0;
    for (long long i = 1023456789; i <= 9876543210; i++)
    {
        string s = to_string(i);
        vector<int> nums(10, 0);
        for (char c : s)
        {
            nums[c - '0']++;
        }
        bool a = true, b = true;
        for (int count : nums)
        {
            if (count > 1)
            {
                a = false;
                break;
            }
        }
        for (int j = 1; j < s.length(); j++)
        {
            if (s[j] == s[j - 1] + 1 || s[j] == s[j - 1] - 1)
            {
                b = false;
                break;
            }
        }

        if (a && b)
        {
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}