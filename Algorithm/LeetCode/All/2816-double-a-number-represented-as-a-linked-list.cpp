/*
 * @Author: RainbowRain9
 * @Date: 2025-03-22 21:31:35
 * @LastEditTime: 2025-03-22 21:36:44
 * @FilePath: \C++\Algorithm\LeetCode\All\2816-double-a-number-represented-as-a-linked-list.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=2816 lang=cpp
 * @lcpr version=30104
 *
 * [2816] 翻倍以链表形式表示的数字
 *
 * https://leetcode.cn/problems/double-a-number-represented-as-a-linked-list/description/
 *
 * algorithms
 * Medium (61.67%)
 * Likes:    33
 * Dislikes: 0
 * Total Accepted:    12.8K
 * Total Submissions: 20.2K
 * Testcase Example:  '[1,8,9]'
 *
 * 给你一个 非空 链表的头节点 head ，表示一个不含前导零的非负数整数。
 *
 * 将链表 翻倍 后，返回头节点 head 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,8,9]
 * 输出：[3,7,8]
 * 解释：上图中给出的链表，表示数字 189 。返回的链表表示数字 189 * 2 = 378 。
 *
 * 示例 2：
 *
 * 输入：head = [9,9,9]
 * 输出：[1,9,9,8]
 * 解释：上图中给出的链表，表示数字 999 。返回的链表表示数字 999 * 2 = 1998 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [1, 10^4] 内
 * 0 <= Node.val <= 9
 * 生成的输入满足：链表表示一个不含前导零的数字，除了数字 0 本身。
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        auto new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }

public:
    ListNode *doubleIt(ListNode *head)
    {
        ListNode *p = reverseList(head);
        ListNode *curr = p;
        int carry = 0;
        ListNode *prev = nullptr;

        while (curr)
        {
            int val = curr->val * 2 + carry;
            curr->val = val % 10;
            carry = val / 10;
            prev = curr;
            curr = curr->next;
        }

        if (carry)
        {
            prev->next = new ListNode(carry);
        }

        return reverseList(p);
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
// [1,8,9]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9]\n
// @lcpr case=end

 */
