// Source : https://leetcode.cn/problems/subarray-product-less-than-k/
// Date   : 2024-11-11

/**************************************************
 * 题目描述：
 * 给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
 *
 * 示例 1：
 *   输入：nums = [10,5,2,6], k = 100
 *   输出：8
 *   解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2]、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
 *   需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。
 *
 * 示例 2：
 *   输入：nums = [1,2,3], k = 0
 *   输出：0
 *
 * 提示：
 *   - 1 <= nums.length <= 3 * 104
 *   - 1 <= nums[i] <= 1000
 *   - 0 <= k <= 106
 **************************************************/

/*
    解题思路：
    使用滑动窗口解决此问题。维护一个窗口，使窗口内元素乘积小于k。
    - 右指针不断向右移动，将元素乘入窗口
    - 当窗口内元素乘积大于等于k时，左指针向右移动，从窗口中除去元素
    - 对于每个右指针位置，计算以右指针结尾的所有符合条件的子数组个数
    - 重复上述过程，累加所有符合条件的子数组个数

    时间复杂度分析：O(n)，其中n为数组长度
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1) return 0;
        int ans = 0, prod = 1, left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            prod *= nums[right];
            while (prod >= k)
            {
                prod /= nums[left++];
            }
            ans += right - left + 1;
        }
        return ans;
    }
};

int main()
{
    // 创建Solution对象
    Solution solution;

    // 测试用例
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;

    // 输出测试用例
    cout << "Input: nums = [";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if (i < nums.size() - 1)
            cout << ",";
    }
    cout << "], k = " << k << endl;

    // 调用方法获取结果
    int result = solution.numSubarrayProductLessThanK(nums, k);

    // 输出结果
    cout << "Output: " << result << endl;

    // 输出解释
    cout << "Explanation: 8个乘积小于100的子数组分别为：[10]、[5]、[2]、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。" << endl;

    return 0;
}