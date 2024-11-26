// Source : https://leetcode.cn/problems/fruit-into-baskets/
// Date   : 2024-11-14

/**************************************************
 * 题目描述：
 * 你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组 fruits 表示，其中 fruits[i] 是第 i 棵树上的水果 种类 。
 * 你想要尽可能多地收集水果。然而，农场的主人设定了一些规则：
 * - 你只有 两个 篮子，并且每个篮子只能装 单一类型 的水果。每个篮子能够装的水果总量没有限制。
 * - 你可以选择任意一棵树开始采摘，你必须从 每棵 树（包括开始采摘的树）上 恰好摘一个水果 。采摘的水果应当符合篮子中的水果类型。
 * - 每采摘一次，你将会向右移动到下一棵树，并继续采摘。
 * - 一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。
 * 给你一个整数数组 fruits ，返回你可以收集的水果的 最大 数目。
 *
 * 示例 1：
 *   输入：fruits = [1,2,1]
 *   输出：3
 *   解释：可以采摘全部 3 棵树。
 *
 * 示例 2：
 *   输入：fruits = [0,1,2,2]
 *   输出：3
 *   解释：可以采摘 [1,2,2] 这三棵树。如果从第一棵树开始采摘，则只能采摘 [0,1] 这两棵树。
 *
 * 示例 3：
 *   输入：fruits = [1,2,3,2,2]
 *   输出：4
 *   解释：可以采摘 [2,3,2,2] 这四棵树。如果从第一棵树开始采摘，则只能采摘 [1,2] 这两棵树。
 *
 * 提示：
 *   - 1 <= fruits.length <= 105
 *   - 0 <= fruits[i] < fruits.length
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口法，维护一个可变长度的窗口
    2. 窗口内最多只能包含两种不同的水果
    3. 当窗口内水果种类超过2种时，左指针右移直到窗口合法
    4. 记录过程中的最大窗口长度

    时间复杂度分析：
    - 只需要遍历一次数组，时间复杂度为O(n)
    - 使用哈希表存储水果种类，空间复杂度为O(1)，因为最多只存储2种水果
*/

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> type;
        int n = fruits.size();
        int ans = 0, left = 0;
        for (int right = 0; right < n; right++)
        {
            type[fruits[right]]++;
            while (type.size() > 2)
            {
                type[fruits[left]]--;
                if (type[fruits[left]] == 0)
                {
                    type.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main()
{
    Solution s;

    // 测试用例1
    vector<int> fruits1 = {1, 2, 1};
    cout << s.totalFruit(fruits1) << endl; // 输出: 3

    // 测试用例2
    vector<int> fruits2 = {0, 1, 2, 2};
    cout << s.totalFruit(fruits2) << endl; // 输出: 3

    // 测试用例3
    vector<int> fruits3 = {1, 2, 3, 2, 2};
    cout << s.totalFruit(fruits3) << endl; // 输出: 4

    return 0;
}