/*
 * @Author: RainbowRain9
 * @Date: 2025-03-25 23:07:41
 * @LastEditTime: 2025-03-25 23:24:29
 * @FilePath: \C++\Algorithm\LeetCode\All\2487-remove-nodes-from-linked-list.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 * @lcpr version=30104
 *
 * [2487] 从链表中移除节点
 *
 * https://leetcode.cn/problems/remove-nodes-from-linked-list/description/
 *
 * algorithms
 * Medium (75.93%)
 * Likes:    125
 * Dislikes: 0
 * Total Accepted:    40.1K
 * Total Submissions: 52.9K
 * Testcase Example:  '[5,2,13,3,8]'
 *
 * 给你一个链表的头节点 head 。
 *
 * 移除每个右侧有一个更大数值的节点。
 *
 * 返回修改后链表的头节点 head 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：head = [5,2,13,3,8]
 * 输出：[13,8]
 * 解释：需要移除的节点是 5 ，2 和 3 。
 * - 节点 13 在节点 5 右侧。
 * - 节点 13 在节点 2 右侧。
 * - 节点 8 在节点 3 右侧。
 *
 *
 * 示例 2：
 *
 * 输入：head = [1,1,1,1]
 * 输出：[1,1,1,1]
 * 解释：每个节点的值都是 1 ，所以没有需要移除的节点。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 给定列表中的节点数目在范围 [1, 10^5] 内
 * 1 <= Node.val <= 10^5
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
// TODO 2025-03-25: 
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr, *cur = head;
        while (cur)
        {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

    ListNode *removeNodes(ListNode *head)
    {
        head = reverseList(head);
        ListNode *cur = head;
        while (cur->next)
        {
            if (cur->val > cur->next->val)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return reverseList(head);
    }
};
// @lc code=end

int main()
{
    Solution solution;
    
    // Test case 1: [5,2,13,3,8] -> [13,8]
    ListNode* head1 = new ListNode(5, new ListNode(2, new ListNode(13, new ListNode(3, new ListNode(8)))));
    ListNode* result1 = solution.removeNodes(head1);
    while (result1) {
        cout << result1->val << " ";
        result1 = result1->next;
    }
    cout << endl;
    
    // Test case 2: [1,1,1,1] -> [1,1,1,1]
    ListNode* head2 = new ListNode(1, new ListNode(1, new ListNode(1, new ListNode(1))));
    ListNode* result2 = solution.removeNodes(head2);
    while (result2) {
        cout << result2->val << " ";
        result2 = result2->next;
    }
    cout << endl;
}

/*
// @lcpr case=start
// [5,2,13,3,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n
// @lcpr case=end

 */
