#include <iostream>
using namespace std;

// 二叉树节点结构体
struct TreeNode
{
    char data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x) : data(x), left(NULL), right(NULL) {}
};

// 根据前序扩展序列创建二叉树
TreeNode *createTree()
{
    char ch;
    cin >> ch;
    if (ch == '#')
        return NULL;

    TreeNode *root = new TreeNode(ch);
    root->left = createTree();
    root->right = createTree();
    return root;
}

// 中序遍历二叉树
void inorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->data;
    inorderTraversal(root->right);
}

int main()
{
    TreeNode *root = createTree();
    inorderTraversal(root);
    cout << endl;
    return 0;
}
