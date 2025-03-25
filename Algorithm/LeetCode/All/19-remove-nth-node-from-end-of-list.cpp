/*
 * @Author: RainbowRain9
 * @Date: 2025-03-25 22:00:50
 * @LastEditTime: 2025-03-25 22:08:18
 * @FilePath: \C++\Algorithm\LeetCode\All\19-remove-nth-node-from-end-of-list.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30104
 *
 * [19] 删除链表的倒数第 N 个结点
 *
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (49.69%)
 * Likes:    3075
 * Dislikes: 0
 * Total Accepted:    1.7M
 * Total Submissions: 3.4M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 *
 *
 * 示例 2：
 *
 * 输入：head = [1], n = 1
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：head = [1,2], n = 1
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中结点的数目为 sz
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 *
 *
 *
 *
 * 进阶：你能尝试使用一趟扫描实现吗？
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(0, head);
        ListNode *right = &dummy;
        while (n--)
        {
            right = right->next;
        }
        ListNode *left = &dummy;
        while (right->next)
        {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return dummy.next;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    
    // Test case 1: [1,2,3,4,5], n=2
    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* result1 = solution.removeNthFromEnd(head1, 2);
    
    // Test case 2: [1], n=1
    ListNode* head2 = new ListNode(1);
    ListNode* result2 = solution.removeNthFromEnd(head2, 1);
    
    // Test case 3: [1,2], n=1
    ListNode* head3 = new ListNode(1, new ListNode(2));
    ListNode* result3 = solution.removeNthFromEnd(head3, 1);
}

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */
