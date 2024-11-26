// Source : https://leetcode.cn/problems/maximum-average-subarray-i/
// Date   : 2024-11-10

/**************************************************
 * 给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。
 *
 * 请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。
 *
 * 任何计算误差小于 10^-5 的答案都将被视为正确答案。
 *
 * 示例 1：
 *   输入：nums = [1,12,-5,-6,50,3], k = 4
 *   输出：12.75
 *   解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
 *
 * 示例 2：
 *   输入：nums = [5], k = 1
 *   输出：5.00000
 *
 * 提示：
 *   - n == nums.length
 *   - 1 <= k <= n <= 10^5
 *   - -10^4 <= nums[i] <= 10^4
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口法，维护一个长度为k的窗口
    2. 计算第一个窗口的和
    3. 窗口向右滑动时:
       - 减去左边移出的元素
       - 加上右边移入的元素
    4. 记录过程中的最大和
    5. 最后除以k得到最大平均数

    时间复杂度分析：
    - 只需要遍历数组一次，时间复杂度为 O(n)
    - 只使用了常数个变量，空间复杂度为 O(1)
*/

#include <climits>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int n = nums.size();
        // ans记录最大平均值,初始化为最小值
        double ans = INT_MIN;
        // sum记录当前窗口内元素和
        double sum = 0;
        
        // 遍历数组,right表示窗口右边界
        for (int right = 0; right < n; right++)
        {
            // 将新元素加入窗口
            sum += nums[right];
            
            // 窗口未形成时继续
            if (right < k - 1)
                continue;
                
            // 更新最大平均值
            ans = max(ans, sum / k);
            
            // 移除窗口最左边的元素
            sum -= nums[right - k + 1];
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    cout << s.findMaxAverage(nums, k) << endl; // 输出: 12.75

    nums = {5};
    k = 1;
    cout << s.findMaxAverage(nums, k) << endl; // 输出: 5.00000

    return 0;
}
