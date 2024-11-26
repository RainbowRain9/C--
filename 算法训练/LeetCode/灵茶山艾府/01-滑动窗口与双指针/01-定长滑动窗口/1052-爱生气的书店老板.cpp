// Source : https://leetcode.cn/problems/grumpy-bookstore-owner/
// Date   : 2024-11-10

/**************************************************
 * 有一个书店老板，他的书店每天的营业时间是 n 分钟。每分钟都有一些顾客进入书店，用数组 customers 表示，
 * 其中 customers[i] 是在第 i 分钟时进入书店的顾客数量。
 *
 * 书店老板知道一个秘密技巧，能在任意连续的 minutes 分钟内保持冷静，但只能使用一次。这意味着在这段时间内，
 * 即使书店老板原本会生气，他也能保持冷静。
 *
 * 书店老板的生气状态用数组 grumpy 表示，其中 grumpy[i] = 1 表示在第 i 分钟，他是生气的；
 * grumpy[i] = 0 表示在第 i 分钟，他是冷静的。
 *
 * 返回在这一天营业时间内，在老板使用该技巧的情况下，可以让顾客感到满意的最大数量。
 *
 * 示例 1：
 *   输入：customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
 *   输出：16
 *   解释：书店老板在最后 3 分钟保持冷静。
 *   感到满意的最大客户数量 = 1 + 1 + 1 + 1 + 7 + 5 = 16.
 *
 * 提示：
 *   - n == customers.length == grumpy.length
 *   - 1 <= minutes <= n <= 2 * 10^4
 *   - 0 <= customers[i] <= 2 * 10^3
 *   - grumpy[i] 为 0 或 1
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口法，维护一个长度为minutes的窗口
    2. 先统计所有老板不生气时的顾客总数(base)
    3. 然后用滑动窗口找出在minutes时间内，通过控制老板情绪可以额外获得的最大顾客数
       - 窗口内只统计原本老板生气时的顾客数(因为不生气时的已经在base中统计过)
    4. 最终结果 = base + 最大额外顾客数

    时间复杂度分析：
    - 需要遍历数组两次，时间复杂度为 O(n)
    - 只使用了常数个变量，空间复杂度为 O(1)
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = customers.size();
        // s[0]存储老板不生气时的顾客总数，s[1]存储当前窗口内老板生气时的顾客数
        int s[2]{}, max_s1 = 0;
        
        // 遍历每一分钟
        for (int i = 0; i < customers.size(); i++)
        {
            // 根据老板的情绪状态累加顾客数
            s[grumpy[i]] += customers[i];
            
            // 窗口未形成时继续
            if (i < minutes - 1)
            {
                continue;
            }
            
            // 更新窗口内最大的生气顾客数
            max_s1 = max(max_s1, s[1]);
            
            // 移出窗口左端的生气顾客数
            // 如果移出的时间点老板在生气，则减去对应的顾客数
            s[1] -= grumpy[i - minutes + 1] ? customers[i - minutes + 1] : 0;
        }
        
        // 返回所有不生气时的顾客数加上使用技巧可以挽回的最大顾客数
        return s[0] + max_s1;
    }
};

int main()
{
    Solution s;
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;
    cout << s.maxSatisfied(customers, grumpy, minutes) << endl; // 输出: 16
    return 0;
}
