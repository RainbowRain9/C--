/*
 * @Author: RainbowRain9
 * @Date: 2025-03-21 16:20:05
 * @LastEditTime: 2025-03-21 16:27:50
 * @FilePath: \C++\Algorithm\LeetCode\All\206-reverse-linked-list.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=206 lang=cpp
 * @lcpr version=30104
 *
 * [206] 反转链表
 *
 * https://leetcode.cn/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (75.19%)
 * Likes:    3837
 * Dislikes: 0
 * Total Accepted:    2.3M
 * Total Submissions: 3M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 *
 *
 * 示例 2：
 *
 * 输入：head = [1,2]
 * 输出：[2,1]
 *
 *
 * 示例 3：
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目范围是 [0, 5000]
 * -5000 <= Node.val <= 5000
 *
 *
 *
 *
 * 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
 *
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *pre = NULL;
        while (cur)
        {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    
    // Test case 1: [1,2,3,4,5]
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3); 
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    
    ListNode* result1 = solution.reverseList(head1);
    while(result1) {
        cout << result1->val << " ";
        result1 = result1->next;
    }
    cout << endl;

    // Test case 2: [1,2]
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    
    ListNode* result2 = solution.reverseList(head2);
    while(result2) {
        cout << result2->val << " ";
        result2 = result2->next;
    }
    cout << endl;

    // Test case 3: []
    ListNode* head3 = nullptr;
    ListNode* result3 = solution.reverseList(head3);
    if(!result3) {
        cout << "Empty list" << endl;
    }
}

/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
