// Source : https://leetcode.cn/problems/swap-nodes-in-pairs/description/
// Date   : 2024-11-27
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=20003
 *
 * [24] 两两交换链表中的节点
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode dummy(0, head);
        ListNode *p = &dummy;
        ListNode *p1 = head;

        while (p1 & p1->next)
        {
            ListNode p2 = p1->next;
            ListNode p3 = p2->next;

            p->next = p2;
            p1->next = p3;
            p2->next = p1;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
