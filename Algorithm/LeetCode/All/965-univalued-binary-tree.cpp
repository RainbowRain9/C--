/*
 * @Author: RainbowRain9
 * @Date: 2025-03-31 21:16:43
 * @LastEditTime: 2025-03-31 21:27:57
 * @FilePath: \C++\Algorithm\LeetCode\All\965-univalued-binary-tree.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=965 lang=cpp
 * @lcpr version=30104
 *
 * [965] 单值二叉树
 *
 * https://leetcode.cn/problems/univalued-binary-tree/description/
 *
 * algorithms
 * Easy (69.83%)
 * Likes:    210
 * Dislikes: 0
 * Total Accepted:    99.8K
 * Total Submissions: 142.6K
 * Testcase Example:  '[1,1,1,1,1,null,1]'
 *
 * 如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
 *
 * 只有给定的树是单值二叉树时，才返回 true；否则返回 false。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：[1,1,1,1,1,null,1]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：[2,2,2,5,2]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 给定树的节点数范围是 [1, 100]。
 * 每个节点的值都是整数，范围为 [0, 99] 。
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
// TODO 2025-03-31: 
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
    bool isUnivalTree(TreeNode *root)
    {
        if (!root)
            return true;
        int val = root->val;
        auto dfs = [&](this auto &&dfs, TreeNode *node) -> bool
        {
            if (!node)
                return true;
            if (node->val != val)
                return false;
            return dfs(node->left) && dfs(node->right);
        };
        return dfs(root);
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
// [1,1,1,1,1,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,5,2]\n
// @lcpr case=end

 */
