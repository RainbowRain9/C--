
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

// 层序遍历
void preorder(BTNode *p)
{
    if (p == NULL)
    {
        return;
    }
    queue<BTNode *> q;
    q.push(p);
    while (!q.empty())
    {
        BTNode *node = q.front();
        q.pop();
        if (cnt == 1)
        {
            cout << node->data;
        }
        else
        {
            cout << node->data << " ";
        }
        cnt--;
        if (node->lchild)
        {
            q.push(node->lchild);
        }
        if (node->rchild)
        {
            q.push(node->rchild);
        }
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
