// Source : https://leetcode.cn/problems/two-sum/
// Date : 2024-11-07

/************************************
    给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值 target 的那两个整数，并返回它们的数组下标。
    你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
    你可以按任意顺序返回答案。

    示例 1：
        输入：nums = [2,7,11,15], target = 9
        输出：[0,1]
        解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

    示例 2：
        输入：nums = [3,2,4], target = 6
        输出：[1,2]

    示例 3：
        输入：nums = [3,3], target = 6
        输出：[0,1]

    提示：
        - 2 <= nums.length <= 104
        - -109 <= nums[i] <= 109
        - -109 <= target <= 109
        - 只会存在一个有效答案
************************************/

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (hash.count(complement))
            {
                return {hash[complement], i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    // 创建Solution对象
    Solution solution;

    // 测试用例
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // 调用twoSum方法获取结果
    vector<int> result = solution.twoSum(nums, target);

    // 输出测试用例
    cout << "Input: nums = [2,7,11,15], target = 9" << endl;

    // 输出结果
    cout << "Output: [" << result[0] << "," << result[1] << "]" << endl;

    // 输出解释
    cout << "Explanation: Because nums[" << result[0] << "] + nums[" << result[1]
         << "] == " << target << ", we return [" << result[0] << "," << result[1] << "]" << endl;

    return 0;
}
