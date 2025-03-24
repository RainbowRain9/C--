/*
 * @Author: RainbowRain9
 * @Date: 2025-03-21 16:34:11
 * @LastEditTime: 2025-03-21 16:34:18
 * @FilePath: \C++\Algorithm\LeetCode\All\92-reverse-linked-list-ii.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=92 lang=cpp
 * @lcpr version=30104
 *
 * [92] 反转链表 II
 *
 * https://leetcode.cn/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (56.89%)
 * Likes:    1939
 * Dislikes: 0
 * Total Accepted:    611K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right
 * 的链表节点，返回 反转后的链表 。
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,2,3,4,5], left = 2, right = 4
 * 输出：[1,4,3,2,5]
 *
 *
 * 示例 2：
 *
 * 输入：head = [5], left = 1, right = 1
 * 输出：[5]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数目为 n
 * 1 <= n <= 500
 * -500 <= Node.val <= 500
 * 1 <= left <= right <= n
 *
 *
 *
 *
 * 进阶： 你可以使用一趟扫描完成反转吗？
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *p0 = dummy;
        for (int i = 0; i < left - 1; i++)
        {
            p0 = p0->next;
        }

        ListNode *cur = p0->next;
        ListNode *pre = NULL;
        for (int i = 0; i < right - left + 1; i++)
        {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        p0->next->next = cur;
        p0->next = pre;
        return dummy->next;
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
// [1,2,3,4,5]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n1\n
// @lcpr case=end

 */
