// Source : https://leetcode.cn/problems/merge-two-sorted-lists/description/
// Date   : 2025-03-05
/*
 * @lc app=leetcode.cn id=21 lang=cpp
 * @lcpr version=20003
 *
 * [21] 合并两个有序链表
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummy(-1), *p = &dummy;
        ListNode *p1 = list1, *p2 = list2;
        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1->val > p2->val)
            {
                p->next = p1;
                p1 = p1->next;
            }
            if (p2->val > p1->val)
            {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if (p1 != nullptr)
        {
            p->next = p1;
        }
        if (p2 != nullptr)
        {
            p->next = p2;
        }

        return dummy.next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,4]\n[1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[0]\n
// @lcpr case=end

 */
