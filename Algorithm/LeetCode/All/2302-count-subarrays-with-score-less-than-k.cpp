// Source : https://leetcode.cn/problems/count-subarrays-with-score-less-than-k/
// Date   : 2024-11-13

/**************************************************
 * 题目描述：
 * 一个数组的 分数 定义为数组之和 乘以 数组的长度。
 * - 比方说，[1, 2, 3, 4, 5] 的分数为 (1 + 2 + 3 + 4 + 5) * 5 = 75 。
 * 给你一个正整数数组 nums 和一个整数 k ，请你返回 nums 中分数 严格小于 k 的 非空整数子数组的数目。
 * 子数组 是数组中的一个连续元素序列。
 *
 * 示例 1：
 *   输入：nums = [2,1,4,3,5], k = 10
 *   输出：6
 *   解释：严格小于 10 的子数组分数如下：
 *   - [2] 分数为 2 * 1 = 2
 *   - [1] 分数为 1 * 1 = 1
 *   - [4] 分数为 4 * 1 = 4
 *   - [3] 分数为 3 * 1 = 3 
 *   - [5] 分数为 5 * 1 = 5
 *   - [2,1] 分数为 (2 + 1) * 2 = 6
 *   总共有 6 个子数组。
 *
 * 示例 2：
 *   输入：nums = [1,1,1], k = 5
 *   输出：5
 *   解释：除了 [1,1,1] 以外的所有子数组分数都小于 5 。
 *   [1,1,1] 分数为 (1 + 1 + 1) * 3 = 9 。
 *
 * 提示：
 *   - 1 <= nums.length <= 105
 *   - 1 <= nums[i] <= 105
 *   - 1 <= k <= 1015
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口法，维护一个窗口使其分数小于k
    2. 对于每个右端点，找到最大的左端点使得窗口分数小于k
    3. 以右端点结尾的所有合法子数组数目为left个
    4. 累加所有右端点对应的合法子数组数目

    时间复杂度分析：O(n)，其中n为数组长度
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution 
{
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long sum = 0;
        int left = 0;
        
        for(int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while(sum * (right - left + 1) >= k)
            {
                sum -= nums[left++];
            }
            ans += right - left + 1;
        }
        
        return ans;
    }
};

int main()
{
    Solution s;
    
    // 测试用例1
    vector<int> nums1 = {2,1,4,3,5};
    cout << s.countSubarrays(nums1, 10) << endl; // 输出: 6
    
    // 测试用例2  
    vector<int> nums2 = {1,1,1};
    cout << s.countSubarrays(nums2, 5) << endl; // 输出: 5
    
    return 0;
}