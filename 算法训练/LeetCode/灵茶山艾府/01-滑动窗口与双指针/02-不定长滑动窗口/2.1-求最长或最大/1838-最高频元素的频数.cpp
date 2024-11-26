// Source : https://leetcode.cn/problems/frequency-of-the-most-frequent-element/description/
// Date   : 2024-11-15

/**************************************************
 * 题目描述：
 * 元素的 频数 是该元素在一个数组中出现的次数。
 * 给你一个整数数组 nums 和一个整数 k 。在一步操作中，你可以选择 nums 的一个下标，并将该下标对应元素的值增加 1 。
 * 执行最多 k 次操作后，返回数组中最高频元素的 最大可能频数 。
 *
 * 示例 1：
 *   输入：nums = [1,2,4], k = 5
 *   输出：3
 *   解释：对第一个元素执行 3 次递增操作，对第二个元素执 2 次递增操作，此时 nums = [4,4,4] 。
 *   4 是最高频元素，频数是 3 。
 *
 * 示例 2：
 *   输入：nums = [1,4,8,13], k = 5
 *   输出：2
 *   解释：存在多种最优解决方案：
 *   - 对第一个元素执行 4 次递增操作，此时 nums = [5,4,8,13] 。5 是最高频元素，频数是 2 。
 *   - 对第二个元素执行 5 次递增操作，此时 nums = [1,9,8,13] 。9 是最高频元素，频数是 2 。
 *
 * 提示：
 *   - 1 <= nums.length <= 10^5
 *   - 1 <= nums[i] <= 10^5
 *   - 1 <= k <= 10^5
 **************************************************/

/*
    解题思路：
    使用滑动窗口解决此问题。
    1. 首先对数组排序，这样可以保证窗口内的元素是连续的
    2. 维护一个窗口，使窗口内所有元素通过k次操作可以变成窗口右端点的值
    3. 右指针不断向右移动，计算将窗口内所有元素变成右端点值所需的操作次数
    4. 当所需操作次数超过k时，左指针右移缩小窗口
    5. 维护最大窗口长度，即为答案

    时间复杂度分析：O(nlogn)，其中n为数组长度，主要是排序的时间复杂度
*/
/*
 * @lc app=leetcode.cn id=1838 lang=cpp
 * @lcpr version=20003
 *
 * [1838] 最高频元素的频数
 */


// @lcpr-template-start
using namespace std;
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
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long total = 0;
        int left = 0, ans = 1;
        for (int right = 1; right < n; right++)
        {
            total += (long long)(nums[right] - nums[right - 1]) * (right - left);
            while (total > k)
            {
                total -= nums[right] - nums[left];
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,4,8,13]\n5\n
// @lcpr case=end

// @lcpr case=start
// [3,9,6]\n2\n
// @lcpr case=end

 */

