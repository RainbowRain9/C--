#include <iostream>

#include <algorithm>

using namespace std;

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

    int depth(BiNode *bt)
    {
        // 补充代码
        if (bt == nullptr)
            return 0;
        int leftDepth = depth(bt->lchild);
        int rightDepth = depth(bt->rchild);
        return max(leftDepth, rightDepth) + 1;
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

    cout << b.depth(b.root) << endl;

    return 0;
}