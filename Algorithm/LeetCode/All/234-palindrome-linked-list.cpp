/*
 * @Author: RainbowRain9
 * @Date: 2025-03-24 13:05:38
 * @LastEditTime: 2025-03-24 13:15:07
 * @FilePath: \C++\Algorithm\LeetCode\All\234-palindrome-linked-list.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=234 lang=cpp
 * @lcpr version=30104
 *
 * [234] 回文链表
 *
 * https://leetcode.cn/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (55.56%)
 * Likes:    2038
 * Dislikes: 0
 * Total Accepted:    924.3K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,2,1]'
 *
 * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,2,2,1]
 * 输出：true
 *
 *
 * 示例 2：
 *
 * 输入：head = [1,2]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数目在范围[1, 10^5] 内
 * 0 <= Node.val <= 9
 *
 *
 *
 *
 * 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;

        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = nullptr;
        ListNode *curr = slow;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode *first = head, *second = prev;
        while (second)
        {
            if (first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};
// @lc code=end

int main()
{
    Solution solution;

    // Test case 1: Palindrome list
    ListNode *node4 = new ListNode(1);
    ListNode *node3 = new ListNode(2, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *node1 = new ListNode(1, node2);
    cout << "Test case 1: " << (solution.isPalindrome(node1) ? "true" : "false") << endl; // Expected: true

    // Test case 2: Not a palindrome
    ListNode *node6 = new ListNode(2);
    ListNode *node5 = new ListNode(1, node6);
    cout << "Test case 2: " << (solution.isPalindrome(node5) ? "true" : "false") << endl; // Expected: false

    // Test case 3: Single node
    ListNode *node7 = new ListNode(1);
    cout << "Test case 3: " << (solution.isPalindrome(node7) ? "true" : "false") << endl; // Expected: true

    // Test case 4: Empty list
    cout << "Test case 4: " << (solution.isPalindrome(nullptr) ? "true" : "false") << endl; // Expected: true
}

/*
// @lcpr case=start
// [1,2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */
