/*
 * @Author: RainbowRain9
 * @Date: 2025-03-31 21:31:17
 * @LastEditTime: 2025-03-31 21:37:04
 * @FilePath: \C++\Algorithm\LeetCode\All\951-flip-equivalent-binary-trees.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=951 lang=cpp
 * @lcpr version=30104
 *
 * [951] 翻转等价二叉树
 *
 * https://leetcode.cn/problems/flip-equivalent-binary-trees/description/
 *
 * algorithms
 * Medium (67.53%)
 * Likes:    176
 * Dislikes: 0
 * Total Accepted:    23.3K
 * Total Submissions: 34.7K
 * Testcase Example:  '[1,2,3,4,5,6,null,null,null,7,8]\n[1,3,2,null,6,4,5,null,null,null,null,8,7]'
 *
 * 我们可以为二叉树 T 定义一个 翻转操作 ，如下所示：选择任意节点，然后交换它的左子树和右子树。
 *
 * 只要经过一定次数的翻转操作后，能使 X 等于 Y，我们就称二叉树 X 翻转 等价 于二叉树 Y。
 *
 * 这些树由根节点 root1 和 root2 给出。如果两个二叉树是否是翻转 等价 的函数，则返回 true ，否则返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 =
 * [1,3,2,null,6,4,5,null,null,null,null,8,7]
 * 输出：true
 * 解释：我们翻转值为 1，3 以及 5 的三个节点。
 *
 *
 * 示例 2:
 *
 * 输入: root1 = [], root2 = []
 * 输出: true
 *
 *
 * 示例 3:
 *
 * 输入: root1 = [], root2 = [1]
 * 输出: false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 每棵树节点数在 [0, 100] 范围内
 * 每棵树中的每个值都是唯一的、在 [0, 99] 范围内的整数
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start

class Solution
{
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return true;
        if (!root1 || !root2)
            return false;
        auto dfs = [&](this auto &&dfs, TreeNode *node1, TreeNode *node2) -> bool
        {
            if (!node1 && !node2)
                return true;
            if (!node1 || !node2)
                return false;
            if (node1->val != node2->val)
                return false;
            return dfs(node1->left, node2->left) && dfs(node1->right, node2->right) || dfs(node1->left, node2->right) && dfs(node1->right, node2->left);
        };
        return dfs(root1, root2);
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
// [1,2,3,4,5,6,null,null,null,7,8]\n[1,3,2,null,6,4,5,null,null,null,null,8,7]\n
// @lcpr case=end

// @lcpr case=start
// []\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[1]\n
// @lcpr case=end

 */
