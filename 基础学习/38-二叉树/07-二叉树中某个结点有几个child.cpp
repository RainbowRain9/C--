// Source : https://xujcoj.com/home/contest/1992/problem/2
// Date   : 2024-11-28

/**************************************************
 * 题目描述：
 * 给定N个数字，按照数字大小建立二叉树，求某个节点有几个child
 *
 * 示例：
 *   输入：
 *   4 3 2 1 5
 *   2
 *   输出：1
 *   解释：
 *   二叉树结构如下：
 *        3
 *       / \
 *      2   5
 *     /
 *    1
 *   节点2有1个child(节点1)
 *
 * 规则：
 *   - 第一个数字作为根节点
 *   - 较小的数字放在左子树，较大的数字放在右子树
 *   - 如果查找的数字不在树中，返回-1
 *   - 输入的第一行包含N+1个数字，第一个数字N表示后面有N个数据
 *   - 第二行输入一个数字K，查找data为K的节点有几个child
 **************************************************/

/*
    解题思路：
    1. 使用前序遍历序列构建二叉树
    2. 在二叉树中查找目标节点
    3. 统计该节点的子节点个数

    时间复杂度：O(n)，其中n为二叉树节点个数
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

TreeNode *insert(TreeNode *root, int val)
{
    if (!root)
        return new TreeNode(val);

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

TreeNode *createTree()
{
    int n;
    cin >> n;
    if (n <= 0)
        return NULL;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    TreeNode *root = new TreeNode(nums[0]);
    for (int i = 1; i < n; i++)
    {
        insert(root, nums[i]);
    }
    return root;
}

// 查找目标节点并返回其子节点个数
int countChildren(TreeNode *root, int target)
{
    if (!root)
        return -1;

    if (root->data == target)
    {
        int count = 0;
        if (root->left)
            count++;
        if (root->right)
            count++;
        return count;
    }

    if (target < root->data)
    {
        return countChildren(root->left, target);
    }
    else
    {
        return countChildren(root->right, target);
    }
}   

int main()
{
    TreeNode *root = createTree();
    int target;
    cin >> target;

    cout << countChildren(root, target) << endl;

    return 0;
}