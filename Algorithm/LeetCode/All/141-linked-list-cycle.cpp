/*
 * @Author: RainbowRain9
 * @Date: 2025-03-22 22:05:25
 * @LastEditTime: 2025-03-22 22:05:30
 * @FilePath: \C++\Algorithm\LeetCode\All\141-linked-list-cycle.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=141 lang=cpp
 * @lcpr version=30104
 *
 * [141] 环形链表
 *
 * https://leetcode.cn/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (52.95%)
 * Likes:    2297
 * Dislikes: 0
 * Total Accepted:    1.5M
 * Total Submissions: 2.8M
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * 给你一个链表的头节点 head ，判断链表中是否有环。
 *
 * 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos
 * 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
 *
 * 如果链表中存在环 ，则返回 true 。 否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：head = [3,2,0,-4], pos = 1
 * 输出：true
 * 解释：链表中有一个环，其尾部连接到第二个节点。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：head = [1,2], pos = 0
 * 输出：true
 * 解释：链表中有一个环，其尾部连接到第一个节点。
 *
 *
 * 示例 3：
 *
 *
 *
 * 输入：head = [1], pos = -1
 * 输出：false
 * 解释：链表中没有环。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目范围是 [0, 10^4]
 * -10^5 <= Node.val <= 10^5
 * pos 为 -1 或者链表中的一个 有效索引 。
 *
 *
 *
 *
 * 进阶：你能用 O(1)（即，常量）内存解决此问题吗？
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
    ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    
    // Test case 1: Cycle at position 1
    ListNode* head1 = new ListNode(3);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(-4);
    head1->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1; // Creates cycle
    cout << "Test 1: " << solution.hasCycle(head1) << endl;

    // Test case 2: Cycle at position 0
    ListNode* head2 = new ListNode(1);
    ListNode* node4 = new ListNode(2);
    head2->next = node4;
    node4->next = head2; // Creates cycle
    cout << "Test 2: " << solution.hasCycle(head2) << endl;

    // Test case 3: No cycle
    ListNode* head3 = new ListNode(1);
    cout << "Test 3: " << solution.hasCycle(head3) << endl;
}

/*
// @lcpr case=start
// [3,2,0,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n-1\n
// @lcpr case=end

 */
