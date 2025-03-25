/*
 * @Author: RainbowRain9
 * @Date: 2025-03-24 13:34:08
 * @LastEditTime: 2025-03-24 13:53:39
 * @FilePath: \C++\Algorithm\LeetCode\All\2130-maximum-twin-sum-of-a-linked-list.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=2130 lang=cpp
 * @lcpr version=30104
 *
 * [2130] 链表最大孪生和
 *
 * https://leetcode.cn/problems/maximum-twin-sum-of-a-linked-list/description/
 *
 * algorithms
 * Medium (78.60%)
 * Likes:    76
 * Dislikes: 0
 * Total Accepted:    31.8K
 * Total Submissions: 40.2K
 * Testcase Example:  '[5,4,2,1]'
 *
 * 在一个大小为 n 且 n 为 偶数 的链表中，对于 0 <= i <= (n / 2) - 1 的 i ，第 i 个节点（下标从 0
 * 开始）的孪生节点为第 (n-1-i) 个节点 。
 *
 *
 * 比方说，n = 4 那么节点 0 是节点 3 的孪生节点，节点 1 是节点 2 的孪生节点。这是长度为 n = 4 的链表中所有的孪生节点。
 *
 *
 * 孪生和 定义为一个节点和它孪生节点两者值之和。
 *
 * 给你一个长度为偶数的链表的头节点 head ，请你返回链表的 最大孪生和 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：head = [5,4,2,1]
 * 输出：6
 * 解释：
 * 节点 0 和节点 1 分别是节点 3 和 2 的孪生节点。孪生和都为 6 。
 * 链表中没有其他孪生节点。
 * 所以，链表的最大孪生和是 6 。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：head = [4,2,2,3]
 * 输出：7
 * 解释：
 * 链表中的孪生节点为：
 * - 节点 0 是节点 3 的孪生节点，孪生和为 4 + 3 = 7 。
 * - 节点 1 是节点 2 的孪生节点，孪生和为 2 + 2 = 4 。
 * 所以，最大孪生和为 max(7, 4) = 7 。
 *
 *
 * 示例 3：
 *
 *
 *
 * 输入：head = [1,100000]
 * 输出：100001
 * 解释：
 * 链表中只有一对孪生节点，孪生和为 1 + 100000 = 100001 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表的节点数目是 [2, 10^5] 中的 偶数 。
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
    int pairSum(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *pre = nullptr, *cur = slow;
        while (cur) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        ListNode *p1 = head, *p2 = pre;
        int mx = 0;
        while (p2) {
            mx = max(mx, p1->val + p2->val);
            p1 = p1->next;
            p2 = p2->next;
        }
        return mx;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    ListNode* head1 = new ListNode(5, new ListNode(4, new ListNode(2, new ListNode(1))));
    cout << "Test case 1: " << solution.pairSum(head1) << endl;  // Expected output: 6

    ListNode* head2 = new ListNode(4, new ListNode(2, new ListNode(2, new ListNode(3))));
    cout << "Test case 2: " << solution.pairSum(head2) << endl;  // Expected output: 7

    ListNode* head3 = new ListNode(1, new ListNode(100000));
    cout << "Test case 3: " << solution.pairSum(head3) << endl;  // Expected output: 100001
}

/*
// @lcpr case=start
// [5,4,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,100000]\n
// @lcpr case=end

 */
