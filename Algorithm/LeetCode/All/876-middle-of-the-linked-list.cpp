/*
 * @Author: RainbowRain9
 * @Date: 2025-03-22 22:00:09
 * @LastEditTime: 2025-03-22 22:02:36
 * @FilePath: \C++\Algorithm\LeetCode\All\876-middle-of-the-linked-list.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=876 lang=cpp
 * @lcpr version=30104
 *
 * [876] 链表的中间结点
 *
 * https://leetcode.cn/problems/middle-of-the-linked-list/description/
 *
 * algorithms
 * Easy (71.54%)
 * Likes:    1051
 * Dislikes: 0
 * Total Accepted:    501.1K
 * Total Submissions: 696.6K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你单链表的头结点 head ，请你找出并返回链表的中间结点。
 *
 * 如果有两个中间结点，则返回第二个中间结点。
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,2,3,4,5]
 * 输出：[3,4,5]
 * 解释：链表只有一个中间结点，值为 3 。
 *
 *
 * 示例 2：
 *
 * 输入：head = [1,2,3,4,5,6]
 * 输出：[4,5,6]
 * 解释：该链表有两个中间结点，值分别为 3 和 4 ，返回第二个结点。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表的结点数范围是 [1, 100]
 * 1 <= Node.val <= 100
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

// Definition for singly-linked list.
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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    ListNode* result = solution.middleNode(head);
    cout << result->val << endl;
}

/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

 */
