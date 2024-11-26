// Source : https://leetcode.cn/problems/minimum-size-subarray-sum/
// Date   : 2024-11-11

/**************************************************
 * 题目描述：
 * 给定一个含有 n 个正整数的数组和一个正整数 target。
 * 找出该数组中满足其和 ≥ target 的长度最小的连续子数组，并返回其长度。
 * 如果不存在符合条件的子数组，返回 0。
 *
 * 示例 1：
 *   输入：target = 7, nums = [2,3,1,2,4,3]
 *   输出：2
 *   解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 *
 * 示例 2：
 *   输入：target = 4, nums = [1,4,4]
 *   输出：1
 *
 * 示例 3：
 *   输入：target = 11, nums = [1,1,1,1,1,1,1,1]
 *   输出：0
 *
 * 提示：
 *   - 1 <= target <= 109
 *   - 1 <= nums.length <= 105
 *   - 1 <= nums[i] <= 105
 **************************************************/

/*
    解题思路：
    使用滑动窗口解决此问题。维护一个窗口，使窗口内元素和大于等于target。
    - 右指针不断向右移动，将元素加入窗口
    - 当窗口内元素和大于等于target时，记录当前窗口长度，并尝试缩小窗口
    - 左指针向右移动，从窗口中减去元素，直到和小于target
    - 重复上述过程，找到最小窗口长度

    时间复杂度分析：O(n)，其中n为数组长度
*/

#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // ans初始化为数组长度+1,作为无效值标记
        // sum用于记录当前窗口内的元素和
        int ans = nums.size() + 1, sum = 0;
        
        // left指针表示窗口的左边界
        int left = 0;
        
        // right指针遍历数组,表示窗口的右边界
        for (int right = 0; right < nums.size(); right++)
        {
            // 将当前元素加入窗口
            sum += nums[right];
            
            // 当窗口内元素和大于等于target时
            // 尝试通过移动left指针来缩小窗口
            while (sum >= target)
            {
                // 更新最小窗口长度
                ans = min(ans, right - left + 1);
                // 从窗口中移除最左边的元素
                sum -= nums[left++];
            }
        }
        
        // 如果ans仍然大于数组长度,说明没有找到符合条件的窗口,返回0
        // 否则返回找到的最小窗口长度
        return ans <= nums.size() ? ans : 0;
    }
};

int main()
{
    // 创建Solution对象
    Solution solution;

    // 测试用例
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    // 输出测试用例
    cout << "Input: target = " << target << ", nums = [";
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i];
        if (i < nums.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;

    // 调用minSubArrayLen方法获取结果
    int result = solution.minSubArrayLen(target, nums);

    // 输出结果
    cout << "Output: " << result << endl;

    // 输出解释
    cout << "Explanation: 子数组 [4,3] 是该条件下的长度最小的子数组。" << endl;

    return 0;
}