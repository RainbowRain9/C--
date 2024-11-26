// Source : https://xujcoj.com/home/contest/1977/problem/1
// Date   : 2024-01-01

/**************************************************
 * 题目描述：
 * 给定一个二叉树，按照前序遍历的顺序输出所有节点的值。
 *
 * 示例 1：
 *   输入：5
 *        1 2 3 4 5
 *   输出：1 2 4 5 3
 *   解释：构建的二叉树为:
 *         1
 *       /   \
 *      2     3
 *     / \
 *    4   5
 *
 * 提示：
 *   - 1 <= n <= 100
 *   - 节点值为整数
 **************************************************/

/*
    解题思路：
    1. 首先读入节点总数n和各节点值
    2. 创建根节点并初始化
    3. 依次插入剩余节点构建二叉树
    4. 最后进行前序遍历输出

    时间复杂度分析：
    - 构建树的时间复杂度为O(nlogn)
    - 遍历的时间复杂度为O(n)
    - 总体时间复杂度为O(nlogn)
*/

#include <iostream>
#include <queue>
using namespace std;

int cnt; // 记录总结点数

struct BTNode
{
    int data;
    BTNode *lchild;
    BTNode *rchild;
};

// 前序遍历
void preorder(BTNode *p)
{
    if (p != NULL)
    {
        if (cnt == 1)
        {
            cout << p->data;
        }
        else
        {
            cout << p->data << " "; // 先访问根节点
        }
        preorder(p->lchild);    // 再遍历左子树
        cnt--;
        preorder(p->rchild);    // 最后遍历右子树
    }
}

// 插入节点
void insert(BTNode *&root, int val)
{
    if (root == NULL)
    {
        root = new BTNode;
        root->data = val;
        root->lchild = NULL;
        root->rchild = NULL;
        return;
    }
    
    if (val < root->data)
    {
        insert(root->lchild, val);
    }
    else
    {
        insert(root->rchild, val);
    }
}

int main()
{
    int n;
    cin >> n;
    cnt = n; // 先输入总共有几个结点，cnt记住总共的点数

    BTNode *rootnode = NULL; // 创建根结点

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insert(rootnode, val);
    }

    preorder(rootnode);
    cout << endl;

    return 0;
}
