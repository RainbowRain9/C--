/*
 * @Author: RainbowRain9
 * @Date: 2025-03-25 22:35:26
 * @LastEditTime: 2025-03-25 22:46:59
 * @FilePath: \C++\Algorithm\LeetCode\All\3217-delete-nodes-from-linked-list-present-in-array.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=3217 lang=cpp
 * @lcpr version=30104
 *
 * [3217] 从链表中移除在数组中存在的节点
 *
 * https://leetcode.cn/problems/delete-nodes-from-linked-list-present-in-array/description/
 *
 * algorithms
 * Medium (65.00%)
 * Likes:    11
 * Dislikes: 0
 * Total Accepted:    11.4K
 * Total Submissions: 18.1K
 * Testcase Example:  '[1,2,3]\n[1,2,3,4,5]'
 *
 * 给你一个整数数组 nums 和一个链表的头节点 head。从链表中移除所有存在于 nums 中的节点后，返回修改后的链表的头节点。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： nums = [1,2,3], head = [1,2,3,4,5]
 *
 * 输出： [4,5]
 *
 * 解释：
 *
 *
 *
 * 移除数值为 1, 2 和 3 的节点。
 *
 *
 * 示例 2：
 *
 *
 * 输入： nums = [1], head = [1,2,1,2,1,2]
 *
 * 输出： [2,2,2]
 *
 * 解释：
 *
 *
 *
 * 移除数值为 1 的节点。
 *
 *
 * 示例 3：
 *
 *
 * 输入： nums = [5], head = [1,2,3,4]
 *
 * 输出： [1,2,3,4]
 *
 * 解释：
 *
 *
 *
 * 链表中不存在值为 5 的节点。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * nums 中的所有元素都是唯一的。
 * 链表中的节点数在 [1, 10^5] 的范围内。
 * 1 <= Node.val <= 10^5
 * 输入保证链表中至少有一个值没有在 nums 中出现过。
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start

class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode dummy(0, head);
        ListNode *cur = &dummy;
        while (cur->next)
        {
            if (st.contains(cur->next->val))
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};
// @lc code=end

int main()
{
    Solution solution;

    // Test case 1
    ListNode *head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    vector<int> nums1 = {1, 2, 3};
    ListNode *result1 = solution.modifiedList(nums1, head1);

    // Test case 2
    ListNode *head2 = new ListNode(1, new ListNode(2, new ListNode(1, new ListNode(2, new ListNode(1, new ListNode(2))))));
    vector<int> nums2 = {1};
    ListNode *result2 = solution.modifiedList(nums2, head2);

    // Test case 3
    ListNode *head3 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    vector<int> nums3 = {5};
    ListNode *result3 = solution.modifiedList(nums3, head3);
}

/*
// @lcpr case=start
// [1,2,3]\n[1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[1,2,1,2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [5]\n[1,2,3,4]\n
// @lcpr case=end

 */
