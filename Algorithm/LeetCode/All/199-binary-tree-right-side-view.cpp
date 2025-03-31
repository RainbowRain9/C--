/*
 * @Author: RainbowRain9
 * @Date: 2025-03-31 20:56:57
 * @LastEditTime: 2025-03-31 21:06:08
 * @FilePath: \C++\Algorithm\LeetCode\All\199-binary-tree-right-side-view.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=199 lang=cpp
 * @lcpr version=30104
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode.cn/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (68.27%)
 * Likes:    1187
 * Dislikes: 0
 * Total Accepted:    580.7K
 * Total Submissions: 828.4K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3,null,5,null,4]
 *
 * 输出：[1,3,4]
 *
 * 解释：
 *
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,3,4,null,null,null,5]
 *
 * 输出：[1,3,4,5]
 *
 * 解释：
 *
 *
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1,null,3]
 *
 * 输出：[1,3]
 *
 *
 * 示例 4：
 *
 *
 * 输入：root = []
 *
 * 输出：[]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 二叉树的节点个数的范围是 [0,100]
 * -100 <= Node.val <= 100 
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        auto dfs = [&](this auto &&dfs, TreeNode *node, int depth) -> void
        {
            if (!node)
                return;
            if (depth == ans.size())
            {
                ans.push_back(node->val);
            }
            dfs(node->right, depth + 1);
            dfs(node->left, depth + 1);
        };
        dfs(root, 0);
        return ans;
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
// [1,2,3,null,5,null,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,null,null,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
