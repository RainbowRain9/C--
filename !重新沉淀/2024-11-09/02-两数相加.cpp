// Source : https://leetcode.cn/problems/add-two-numbers/
// Date : 2024-11-07

/************************************
    给定两个非空的链表,表示两个非负的整数。其中,它们各自的位数是按照逆序的方式存储的,
    并且它们的每个节点只能存储一位数字。
    请你将两个数相加,并以相同形式返回一个表示和的链表。
    你可以假设除了数字 0 之外,这两个数都不会以 0 开头。

    示例 1：
        输入：l1 = [2,4,3], l2 = [5,6,4]
        输出：[7,0,8]
        解释：342 + 465 = 807

    示例 2：
        输入：l1 = [0], l2 = [0]
        输出：[0]

    示例 3：
        输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
        输出：[8,9,9,9,0,0,0,1]

    提示：
        - 每个链表中的节点数在范围 [1, 100] 内
        - 0 <= Node.val <= 9
        - 题目数据保证列表表示的数字不含前导零
************************************/

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

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *current = head;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;

            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        if (carry > 0)
        {
            current->next = new ListNode(carry);
        }
        return head->next;
    }
};

int main()
{
    // 创建Solution对象
    Solution solution;

    // 创建测试用例1: l1 = [2,4,3], l2 = [5,6,4]
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // 输出测试用例
    cout << "Input: l1 = [2,4,3], l2 = [5,6,4]" << endl;

    // 调用addTwoNumbers方法获取结果
    ListNode *result = solution.addTwoNumbers(l1, l2);

    // 输出结果
    cout << "Output: [";
    while (result != nullptr)
    {
        cout << result->val;
        if (result->next != nullptr)
        {
            cout << ",";
        }
        result = result->next;
    }
    cout << "]" << endl;

    // 输出解释
    cout << "Explanation: 342 + 465 = 807" << endl;

    // 释放内存
    while (l1 != nullptr)
    {
        ListNode *temp = l1;
        l1 = l1->next;
        delete temp;
    }
    while (l2 != nullptr)
    {
        ListNode *temp = l2;
        l2 = l2->next;
        delete temp;
    }

    return 0;
}
