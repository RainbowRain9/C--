/*
 * @Author: RainbowRain9
 * @Date: 2025-03-10 23:23:08
 * @LastEditTime: 2025-03-25 22:13:50
 * @FilePath: \C++\Algorithm\LeetCode\All\83-remove-duplicates-from-sorted-list.cpp
 * @Description:
 */

/*
 * @lc app=leetcode.cn id=83 lang=cpp
 * @lcpr version=30100
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (54.20%)
 * Likes:    1190
 * Dislikes: 0
 * Total Accepted:    762.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,1,2]
 * 输出：[1,2]
 *
 *
 * 示例 2：
 *
 * 输入：head = [1,1,2,3,3]
 * 输出：[1,2,3]
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
        if (!head)
            return head;
        ListNode *cur = head;
        while (cur->next)
        {
            if (cur->next->val == cur->val)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    
    // Test case 1: [1,1,2]
    ListNode* node1 = new ListNode(1);
    node1->next = new ListNode(1);
    node1->next->next = new ListNode(2);
    ListNode* result1 = solution.deleteDuplicates(node1);
    while (result1) {
        cout << result1->val << " ";
        result1 = result1->next;
    }
    cout << endl;
    
    // Test case 2: [1,1,2,3,3]
    ListNode* node2 = new ListNode(1);
    node2->next = new ListNode(1);
    node2->next->next = new ListNode(2);
    node2->next->next->next = new ListNode(3);
    node2->next->next->next->next = new ListNode(3);
    ListNode* result2 = solution.deleteDuplicates(node2);
    while (result2) {
        cout << result2->val << " ";
        result2 = result2->next;
    }
    cout << endl;
}

/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3,3]\n
// @lcpr case=end

 */
