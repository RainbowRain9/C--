/*
 * @Author: RainbowRain9
 * @Date: 2025-03-22 19:15:49
 * @LastEditTime: 2025-03-22 19:32:21
 * @FilePath: \C++\Algorithm\LeetCode\All\445-add-two-numbers-ii.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=445 lang=cpp
 * @lcpr version=30104
 *
 * [445] 两数相加 II
 *
 * https://leetcode.cn/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (61.24%)
 * Likes:    757
 * Dislikes: 0
 * Total Accepted:    169.6K
 * Total Submissions: 275.9K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
 *
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 *
 *
 *
 * 示例1：
 *
 *
 *
 * 输入：l1 = [7,2,4,3], l2 = [5,6,4]
 * 输出：[7,8,0,7]
 *
 *
 * 示例2：
 *
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[8,0,7]
 *
 *
 * 示例3：
 *
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表的长度范围为 [1, 100]
 * 0 <= node.val <= 9
 * 输入数据保证链表代表的数字无前导 0
 *
 *
 *
 *
 * 进阶：如果输入链表不能翻转该如何解决？
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
// TODO 2025-03-22: 
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

    ListNode *addTwo(ListNode *l1, ListNode *l2, int carry = 0)
    {
        if (l1 == nullptr && l2 == nullptr)
        {
            return carry ? new ListNode(carry) : nullptr;
        }

        if (l1 == nullptr)
        {
            swap(l1, l2);
        }
        carry += l1->val + (l2 ? l2->val : 0);
        l1->val = carry % 10;
        l1->next = addTwo(l1->next, (l2 ? l2->next : nullptr), carry / 10);
        return l1;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        auto l3 = addTwo(l1, l2);
        return reverseList(l3);
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
// [7,2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

 */
