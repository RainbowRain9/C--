/*
 * @Author: RainbowRain9
 * @Date: 2025-03-26 14:03:53
 * @LastEditTime: 2025-03-26 15:50:02
 * @FilePath: \C++\Algorithm\LeetCode\All\112-path-sum.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=112 lang=cpp
 * @lcpr version=30104
 *
 * [112] 路径总和
 *
 * https://leetcode.cn/problems/path-sum/description/
 *
 * algorithms
 * Easy (54.83%)
 * Likes:    1401
 * Dislikes: 0
 * Total Accepted:    748.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点
 * 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。
 *
 * 叶子节点 是指没有子节点的节点。
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
 * 输出：true
 * 解释：等于目标和的根节点到叶节点路径如上图所示。
 *
 *
 * 示例 2：
 *
 * 输入：root = [1,2,3], targetSum = 5
 * 输出：false
 * 解释：树中存在两条根节点到叶子节点的路径：
 * (1 --> 2): 和为 3
 * (1 --> 3): 和为 4
 * 不存在 sum = 5 的根节点到叶子节点的路径。
 *
 * 示例 3：
 *
 * 输入：root = [], targetSum = 0
 * 输出：false
 * 解释：由于树是空的，所以不存在根节点到叶子节点的路径。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [0, 5000] 内
 * -1000 <= Node.val <= 1000
 * -1000 <= targetSum <= 1000
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution1 // 深度优先遍历
{
public:
    bool dfs(TreeNode *node, int currentSum, int targetSum)
    {
        if (!node)
            return false;

        currentSum += node->val;

        if (node->left == node->right)
        {
            return currentSum == targetSum;
        }

        return dfs(node->left, currentSum, targetSum) ||
               dfs(node->right, currentSum, targetSum);
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        return dfs(root, 0, targetSum);
    }
};

class Solution // 递归解法，通过递减targetSum来判断路径和
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        // 如果当前节点为空，返回false
        if (!root)
        {
            return false;
        }
        
        // 从targetSum中减去当前节点的值
        targetSum -= root->val;
        
        // 如果当前节点是叶子节点（左右子节点都为空）
        if (root->left == root->right)
        {
            // 检查targetSum是否减到0
            return targetSum == 0;
        }
        
        // 递归检查左子树或右子树是否存在满足条件的路径
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
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
// [5,4,8,11,null,13,4,7,2,null,null,null,1]\n22\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */
