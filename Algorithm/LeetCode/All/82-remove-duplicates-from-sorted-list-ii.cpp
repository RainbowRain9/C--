/*
 * @Author: RainbowRain9
 * @Date: 2025-03-25 22:16:40
 * @LastEditTime: 2025-03-25 22:28:14
 * @FilePath: \C++\Algorithm\LeetCode\All\82-remove-duplicates-from-sorted-list-ii.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=82 lang=cpp
 * @lcpr version=30104
 *
 * [82] 删除排序链表中的重复元素 II
 *
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (54.70%)
 * Likes:    1346
 * Dislikes: 0
 * Total Accepted:    517K
 * Total Submissions: 941.6K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * 给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,2,3,3,4,4,5]
 * 输出：[1,2,5]
 *
 *
 * 示例 2：
 *
 * 输入：head = [1,1,1,2,3]
 * 输出：[2,3]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数目在范围 [0, 300] 内
 * -100 <= Node.val <= 100
 * 题目数据保证链表已经按升序 排列
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode dummy(0, head);
        ListNode *cur = &dummy;
        while (cur->next && cur->next->next)
        {
            int val = cur->next->val;
            if (cur->next->next->val == val)
            {
                while (cur->next && cur->next->val == val)
                {
                    cur->next = cur->next->next;
                }
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};
// @lc code=end

int main()
{
    Solution solution;

    // Test case 1: [1,2,3,3,4,4,5]
    ListNode *node7 = new ListNode(5);
    ListNode *node6 = new ListNode(4, node7);
    ListNode *node5 = new ListNode(4, node6);
    ListNode *node4 = new ListNode(3, node5);
    ListNode *node3 = new ListNode(3, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *node1 = new ListNode(1, node2);

    ListNode *result1 = solution.deleteDuplicates(node1);
    while (result1)
    {
        cout << result1->val << " ";
        result1 = result1->next;
    }
    cout << endl;

    // Test case 2: [1,1,1,2,3]
    ListNode *node12 = new ListNode(3);
    ListNode *node11 = new ListNode(2, node12);
    ListNode *node10 = new ListNode(1, node11);
    ListNode *node9 = new ListNode(1, node10);
    ListNode *node8 = new ListNode(1, node9);

    ListNode *result2 = solution.deleteDuplicates(node8);
    while (result2)
    {
        cout << result2->val << " ";
        result2 = result2->next;
    }
    cout << endl;
}

/*
// @lcpr case=start
// [1,2,3,3,4,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2,3]\n
// @lcpr case=end

 */
