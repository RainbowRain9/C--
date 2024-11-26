/*
问题描述：
限用（单）链表实现一个带头结点的队列。每个数据元素包含一个 int 类型的 data 成员。
输入数据保证合理且正确。
最后输出队列中剩余元素个数，或空队列出队错误信息。

输入格式：
第一行为一个正整数 N，表示后续操作数。
接下来 N 行，每行格式如下：
- "1 x": 将整数 x 入队
- "2": 执行出队操作
注意：输入可能只有一行，内容为 0。

输出格式：
- 若操作成功：输出队列中剩余元素个数，末尾换行
- 若空队列出队：输出"ERROR: DEQUEUE EMPTY QUEUE"，末尾换行

样例输入：
例 1:
4
1 80  // 入队 80
2     // 出队
1 90  // 入队 90
1 91  // 入队 91

例 2:
3
1 80  // 入队 80
2     // 出队
2     // 出队空队列，错误

样例输出：
例 1:
2

例 2:
ERROR: DEQUEUE EMPTY QUEUE

提示：
出现错误时立即输出错误信息并终止程序。
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkQueue
{
private:
    Node *front;
    Node *rear;

public:
    LinkQueue();
    void EnQueue(int);
    void DeQueue();
    void PrintQueue();
};

LinkQueue::LinkQueue()
{
    front = new Node();
    front->next = nullptr;
    rear = front;
}

void LinkQueue::EnQueue(int x)
{
    Node *p = new Node();
    p->data = x;
    p->next = nullptr;

    rear->next = p;
    rear = p;
}

void LinkQueue::DeQueue()
{
    if (front->next == nullptr)
    {
        cout << "ERROR: DEQUEUE EMPTY QUEUE" << endl;
        exit(0);
    }

    Node *p = front->next;
    front->next = p->next;

    if (p == rear)
    {
        rear = front;
    }

    delete p;
}

void LinkQueue::PrintQueue()
{
    int count = 0;
    Node *p = front->next;
    while (p != nullptr)
    {
        count++;
        p = p->next;
    }
    cout << count << endl;
}

int main()
{
    LinkQueue queue;
    int n;
    cin >> n;

    while (n--)
    {
        int op, x;
        cin >> op;

        if (op == 1)
        {
            cin >> x;
            queue.EnQueue(x);
        }
        else
        {
            queue.DeQueue();
        }
    }

    queue.PrintQueue();
    return 0;
}
