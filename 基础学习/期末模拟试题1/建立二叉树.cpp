#include <iostream>
#include <queue>
using namespace std;
int cnt;
struct BiNode
{
    int data;
    BiNode *lchild, *rchild;
};

class BiTree
{
public:
    BiTree()
    {
        root = nullptr;
    }

    ~BiTree() {}

public:
    BiNode *root;

    void Creat(BiTree *tree, int x)
    {
        BiNode *bt = new BiNode;

        bt->data = x;

        bt->lchild = nullptr;

        bt->rchild = nullptr;

        if (tree->root == nullptr) // 空树
            tree->root = bt;

        else // 不是空树
        {
            BiNode *bn = tree->root;

            while (bn != nullptr)
            {
                if (x < bn->data) // 左子树
                {
                    if (bn->lchild == nullptr)
                    {
                        bn->lchild = bt;

                        return;
                    }
                    else
                        bn = bn->lchild;
                }

                else // 右子树
                {
                    if (bn->rchild == nullptr)
                    {
                        bn->rchild = bt;

                        return;
                    }
                    else
                        bn = bn->rchild;
                }
            }
        }
        return;
    }

    void LayerOrder(BiNode *bt)
    {
        if (bt == nullptr)
        {
            return;
        }

        queue<BiNode *> q;
        q.push(bt);
        bool x = true;

        while (!q.empty())
        {
            BiNode *bn = q.front();
            q.pop();
            if (x)
            {
                cout << bn->data;
                x = false;
            }
            else
                cout << " " << bn->data;
            if (bn->lchild != nullptr)
                q.push(bn->lchild);
            if (bn->rchild != nullptr)
                q.push(bn->rchild);
        }
    }
};

int main()

{
    BiTree b;

    int n;

    cin >> n;

    while (n--)

    {

        int x;

        cin >> x;

        b.Creat(&b, x);
    }

    b.LayerOrder(b.root);

    cout << endl;

    return 0;
}