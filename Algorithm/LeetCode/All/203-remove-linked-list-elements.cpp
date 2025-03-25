/*
 * @Author: RainbowRain9
 * @Date: 2025-03-25 22:32:04
 * @LastEditTime: 2025-03-25 22:32:08
 * @FilePath: \C++\Algorithm\LeetCode\All\203-remove-linked-list-elements.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=203 lang=cpp
 * @lcpr version=30104
 *
 * [203] 移除链表元素
 *
 * https://leetcode.cn/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (57.91%)
 * Likes:    1519
 * Dislikes: 0
 * Total Accepted:    870.4K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,2,6,3,4,5,6], val = 6
 * 输出：[1,2,3,4,5]
 *
 *
 * 示例 2：
 *
 * 输入：head = [], val = 1
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：head = [7,7,7,7], val = 7
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 列表中的节点数目在范围 [0, 10^4] 内
 * 1 <= Node.val <= 50
 * 0 <= val <= 50
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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode dummy(0, head);
        ListNode *cur = &dummy;
        while (cur->next)
        {
            if (cur->next->val == val)
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
    
    // Test case 1: Remove 6 from [1,2,6,3,4,5,6]
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(6, 
                        new ListNode(3, new ListNode(4, 
                        new ListNode(5, new ListNode(6)))))));
    ListNode* result1 = solution.removeElements(list1, 6);
    
    // Test case 2: Remove 1 from empty list
    ListNode* list2 = nullptr;
    ListNode* result2 = solution.removeElements(list2, 1);
    
    // Test case 3: Remove 7 from [7,7,7,7]
    ListNode* list3 = new ListNode(7, new ListNode(7, 
                        new ListNode(7, new ListNode(7))));
    ListNode* result3 = solution.removeElements(list3, 7);
}

/*
// @lcpr case=start
// [1,2,6,3,4,5,6]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n1\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7]\n7\n
// @lcpr case=end

 */
