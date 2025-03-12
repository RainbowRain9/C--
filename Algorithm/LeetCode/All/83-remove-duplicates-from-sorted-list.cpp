/*
 * @Author: RainbowRain9
 * @Date: 2025-03-10 23:23:08
 * @LastEditTime: 2025-03-12 13:33:31
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
// TODO 2025-03-11: 83.删除排序链表中的重复元素
using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *cur = head;
        while (cur && cur->next)
        {
            if (cur->val == cur->next->val)
            {
                ListNode *temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
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
    // your test code here
}

/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3,3]\n
// @lcpr case=end

 */
