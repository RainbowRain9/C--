/*
 * @Author: RainbowRain9
 * @Date: 2025-03-21 23:17:57
 * @LastEditTime: 2025-03-22 19:12:15
 * @FilePath: \C++\Algorithm\LeetCode\All\24-swap-nodes-in-pairs.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=30104
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode.cn/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (73.30%)
 * Likes:    2315
 * Dislikes: 0
 * Total Accepted:    980.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,2,3,4]
 * 输出：[2,1,4,3]
 *
 *
 * 示例 2：
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：head = [1]
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [0, 100] 内
 * 0 <= Node.val <= 100
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
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;

        while (p->next && p->next->next)
        {
            ListNode *p1 = p->next;
            ListNode *p2 = p1->next;
            ListNode *p3 = p2->next;

            p1->next = p3;
            p2->next = p1;
            p->next = p2;

            p = p1;
        }

        return dummy.next;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
