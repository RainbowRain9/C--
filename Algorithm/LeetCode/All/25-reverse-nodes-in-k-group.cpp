/*
 * @Author: RainbowRain9
 * @Date: 2025-03-21 16:53:24
 * @LastEditTime: 2025-03-21 23:14:57
 * @FilePath: \C++\Algorithm\LeetCode\All\25-reverse-nodes-in-k-group.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=25 lang=cpp
 * @lcpr version=30104
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode.cn/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (68.75%)
 * Likes:    2511
 * Dislikes: 0
 * Total Accepted:    758.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
 *
 * k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 *
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[2,1,4,3,5]
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：head = [1,2,3,4,5], k = 3
 * 输出：[3,2,1,4,5]
 *
 *
 *
 * 提示：
 *
 *
 * 链表中的节点数目为 n
 * 1 <= k <= n <= 5000
 * 0 <= Node.val <= 1000
 *
 *
 *
 *
 * 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？
 *
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
// TODO 2025-03-21:
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

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 计算链表长度
        int n = 0;
        for (ListNode* cur = head; cur; cur = cur->next) {
            n++;
        }
        
        // 创建虚拟头节点
        ListNode dummy(0, head);
        ListNode* p0 = &dummy;
        ListNode* pre = NULL;
        ListNode* cur = head;
        
        // 每次处理k个节点
        for (; n >= k; n -= k) {
            // 翻转k个节点
            for (int i = 0; i < k; i++) {
                ListNode* nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            
            // 连接翻转后的组
            ListNode* nxt = p0->next;
            p0->next->next = cur;
            p0->next = pre;
            p0 = nxt;
        }
        return dummy.next;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *result = solution.reverseKGroup(head, 2);

    // Print result
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
}

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */
