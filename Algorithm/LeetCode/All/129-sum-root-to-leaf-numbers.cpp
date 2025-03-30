/*
 * @Author: RainbowRain9
 * @Date: 2025-03-26 16:36:31
 * @LastEditTime: 2025-03-26 16:44:30
 * @FilePath: \C++\Algorithm\LeetCode\All\129-sum-root-to-leaf-numbers.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=129 lang=cpp
 * @lcpr version=30104
 *
 * [129] 求根节点到叶节点数字之和
 *
 * https://leetcode.cn/problems/sum-root-to-leaf-numbers/description/
 *
 * algorithms
 * Medium (71.11%)
 * Likes:    802
 * Dislikes: 0
 * Total Accepted:    322.5K
 * Total Submissions: 451.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
 *
 *
 * 每条从根节点到叶节点的路径都代表一个数字：
 *
 *
 * 例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
 *
 *
 * 计算从根节点到叶节点生成的 所有数字之和 。
 *
 * 叶节点 是指没有子节点的节点。
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [1,2,3]
 * 输出：25
 * 解释：
 * 从根到叶子节点路径 1->2 代表数字 12
 * 从根到叶子节点路径 1->3 代表数字 13
 * 因此，数字总和 = 12 + 13 = 25
 *
 * 示例 2：
 *
 * 输入：root = [4,9,0,5,1]
 * 输出：1026
 * 解释：
 * 从根到叶子节点路径 4->9->5 代表数字 495
 * 从根到叶子节点路径 4->9->1 代表数字 491
 * 从根到叶子节点路径 4->0 代表数字 40
 * 因此，数字总和 = 495 + 491 + 40 = 1026
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [1, 1000] 内
 * 0 <= Node.val <= 9
 * 树的深度不超过 10
 *
 *
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
// Solution1: 使用深度优先搜索（DFS）遍历二叉树，计算所有根到叶子节点路径组成的数字之和
class Solution1
{
public:
    int ans = 0; // 用于存储最终结果

    // 递归遍历二叉树的辅助函数
    void dfs(TreeNode *node, int sum)
    {
        if (!node) // 如果当前节点为空，直接返回
            return;
        sum = sum * 10 + node->val; // 更新当前路径的数字值

        // 如果当前节点是叶子节点（左右子节点都为空）
        if (node->left == node->right)
        {
            ans += sum; // 将当前路径的数字值加到结果中
            return;
        }

        // 递归遍历左子树和右子树
        dfs(node->left, sum);
        dfs(node->right, sum);
    }

    // 主函数，计算所有根到叶子节点路径组成的数字之和
    int sumNumbers(TreeNode *root)
    {
        if (!root) // 如果根节点为空，返回0
            return 0;
        dfs(root, 0); // 从根节点开始DFS遍历
        return ans;   // 返回最终结果
    }
};

// Solution: 更简洁的递归实现，直接返回结果
class Solution
{
public:
    // 递归计算所有根到叶子节点路径组成的数字之和
    int sumNumbers(TreeNode *root, int x = 0)
    {
        if (root == nullptr)
        { // 如果当前节点为空，返回0
            return 0;
        }
        x = x * 10 + root->val; // 更新当前路径的数字值

        // 如果当前节点是叶子节点，返回当前路径的数字值
        if (root->left == root->right)
        {
            return x;
        }

        // 返回左子树和右子树的结果之和
        return sumNumbers(root->left, x) + sumNumbers(root->right, x);
    }
};
// @lc code=end

int main()
{
    Solution solution;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << "Test Case 1: " << solution.sumNumbers(root) << endl; // Expected output: 25

    TreeNode *root2 = new TreeNode(4);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(0);
    root2->left->left = new TreeNode(5);
    root2->left->right = new TreeNode(1);
    cout << "Test Case 2: " << solution.sumNumbers(root2) << endl; // Expected output: 1026
}

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,9,0,5,1]\n
// @lcpr case=end

 */
