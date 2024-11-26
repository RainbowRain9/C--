
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

// 中序遍历
void preorder(BTNode *p)
{
    if (p != NULL)
    {
        preorder(p->lchild);    // 先访问左子树
        if (cnt == 1)
        {
            cout << p->data;
        }
        else
        {
            cout << p->data << " "; // 再遍历根节点
        }
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
