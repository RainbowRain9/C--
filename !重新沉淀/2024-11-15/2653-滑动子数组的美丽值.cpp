// Source : https://leetcode.cn/problems/sliding-subarray-beauty/
// Date   : 2024-11-14

/**************************************************
 * 题目描述：
 * 给你一个长度为 n 的整数数组 nums，和一个整数 k 。
 * 对于每个长度为 k 的窗口，你需要找出其中第 x 小的数字。
 * 窗口的美丽值定义为第 x 小的数字，如果不存在第 x 小的数字，则美丽值为 0。
 * 返回一个长度为 n - k + 1 的数组，包含每个窗口的美丽值。
 *
 * 示例 1：
 *   输入：nums = [1,-1,-3,-2,3], k = 3, x = 2
 *   输出：[-1,-2,-2]
 *   解释：滑动窗口的位置和第2小的数字如下：
 *   - [1,-1,-3],-2,3 => 第2小的数字是 -1
 *   - 1,[-1,-3,-2],3 => 第2小的数字是 -2
 *   - 1,-1,[-3,-2,3] => 第2小的数字是 -2
 *
 * 示例 2：
 *   输入：nums = [-1,-2,-3,-4,-5], k = 2, x = 2
 *   输出：[-2,-3,-4,-5]
 *   解释：滑动窗口的位置和第2小的数字如下：
 *   - [-1,-2],-3,-4,-5 => 第2小的数字是 -2
 *   - -1,[-2,-3],-4,-5 => 第2小的数字是 -3
 *   - -1,-2,[-3,-4],-5 => 第2小的数字是 -4
 *   - -1,-2,-3,[-4,-5] => 第2小的数字是 -5
 *
 * 提示：
 *   - n == nums.length
 *   - 1 <= n <= 10^5
 *   - 1 <= k <= n
 *   - 1 <= x <= k
 *   - -50 <= nums[i] <= 50
 **************************************************/

/*
    解题思路：
    1. 使用定长滑动窗口法，维护一个长度为k的窗口
    2. 对于每个窗口，需要找到第x小的数字
    3. 由于数据范围较小(-50到50)，可以使用计数数组统计每个数字出现的次数
    4. 对于每个窗口，通过计数数组找到第x小的数字

    时间复杂度分析：
    - 遍历数组一次，每次窗口移动时需要O(1)时间更新计数
    - 查找第x小的数字需要O(101)时间
    - 总时间复杂度为O(n * 101) = O(n)
    - 空间复杂度为O(101) = O(1)
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
    {
        const int BIAS = 50;
        int cnt[BIAS * 2 + 1]{};

        for (int i = 0; i < k - 1; i++)
        {
            cnt[nums[i] + BIAS]++;
        }

        int n = nums.size();
        vector<int> ans(n - k + 1);

        for (int i = k - 1; i < n; i++)
        {
            cnt[nums[i] + BIAS]++;

            int left = x;
            for (int j = 0; j < BIAS; j++)
            {
                left -= cnt[j];
                if (left <= 0)
                {
                    ans[i - k + 1] = j - BIAS;
                    break;
                }
            }

            cnt[nums[i - k + 1] + BIAS]--;
        }
        return ans;
    }
};

int main()
{
    Solution s;

    // 测试用例1
    vector<int> nums1 = {1, -1, -3, -2, 3};
    vector<int> res1 = s.getSubarrayBeauty(nums1, 3, 2);
    for (int x : res1)
        cout << x << " "; // 输出: -1 -2 -2
    cout << endl;

    // 测试用例2
    vector<int> nums2 = {-1, -2, -3, -4, -5};
    vector<int> res2 = s.getSubarrayBeauty(nums2, 2, 2);
    for (int x : res2)
        cout << x << " "; // 输出: -2 -3 -4 -5
    cout << endl;

    return 0;
}