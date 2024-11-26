/*
问题描述:
限用（单）链表实现一个带头结点的队列。

每个数据元素包含一个 int 类型的 data 成员。

输入数据保证合理且正确。

最后输出队列中剩余的所有数据元素,每个元素单独占一行。
输出格式:
- 第一行输出 "*** BEGIN OF QUEUE ***"
- 接着每行输出一个队列元素
- 最后一行输出 "*** END OF QUEUE ***"
每行末尾都需要换行。

输入格式:
第一行为一个正整数 N,表示后续操作数。
接下来 N 行,每行格式如下:
- "1 x": 将整数 x 入队
- "2": 执行出队操作
注意:输入可能只有一行,内容为 0。

输出格式:
*** BEGIN OF QUEUE ***
[队列元素,每个占一行]
*** END OF QUEUE ***

样例输入:
例 1:
4
1 80  // 入队 80
2     // 出队
1 90  // 入队 90
1 91  // 入队 91

例 2:
2
1 80  // 入队 80
2     // 出队
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

    Node *front, *rear;

public:
    LinkQueue();

    void EnQueue(int);

    void DeQueue();

    void PrintQueue();
};

LinkQueue::LinkQueue()

{

    // 使用带头结点的链队列设计
    // 头结点的好处:
    // 1. 统一了空队列和非空队列的操作
    // 2. 无需对第一个元素入队进行特殊处理
    // 3. 简化了出队操作的代码
    front = new Node();
    front->next = NULL;
    rear = front;
}

void LinkQueue::EnQueue(int x)

{

    // 链队列不需要判断队列满，因为可以动态分配内存
    // 头指针不需要改变，因为使用了头结点
    // 尾指针需要指向新节点
    Node *p = new Node();
    p->data = x;
    p->next = nullptr;
    rear->next = p;
    rear = p;
}

void LinkQueue::DeQueue()

{

    // 补充代码。提示：出队列需要判断队列是否为空吗？

    // 如果队列只剩最后一个结点，再出队，需要注意什么？
    if (front->next == nullptr)
    {
        return;
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

    // 补充代码
    cout << "*** BEGIN OF QUEUE ***" << endl;
    Node *p = front->next;
    while (p != nullptr)
    {
        cout << p->data << endl;
        p = p->next;
    }
    cout << "*** END OF QUEUE ***" << endl;
}

int main()

{

    LinkQueue l;

    int T;
    cin >> T;

    while (T--)

    {

        int a, b;

        cin >> a;

        if (a == 1)

        {

            cin >> b;

            // 入队列
            l.EnQueue(b);
        }

        else

        {

            // 出队列
            l.DeQueue();
        }
    }

    // 打印队列
    l.PrintQueue();
}
