// Date : 2024-11-14
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=20003
 *
 * [1] 两数之和
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
class Solution
{
public:
    // 使用哈希表存储数组元素和对应的下标
    // 时间复杂度: O(n), 空间复杂度: O(n)
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 创建哈希表,key为数组元素,value为对应下标
        unordered_map<int, int> map;

        // 遍历数组
        for (int i = 0; i < nums.size(); i++)
        {
            // 计算当前元素需要配对的值
            int a = target - nums[i];

            // 在哈希表中查找是否存在配对的值
            if (map.count(a))
            {
                // 如果找到,返回两个数的下标
                return {map[a], i};
            }
            // 将当前元素和下标存入哈希表
            map[nums[i]] = i;
        }
        // 未找到符合条件的两个数,返回空数组
        return {};
    }
};


// @lc code=end

/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */
