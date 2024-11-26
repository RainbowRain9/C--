/*
问题描述：
使用链队列实现一个淘汰赛冠军问题。给定n个选手，通过两两比赛的方式决出最终冠军。

【算法实现】
设函数Comp模拟两位选手mem1和mem2的比赛，若mem1获胜则函数Comp返回1，否则返回0。
函数Comp可以在常数时间内完成执行。简单起见，用字符表示选手，设字符数组r[n]存储n个选手。

比较函数定义如下：
int Comp(char mem1, char mem2) {
    if (mem1 > mem2) return 1;
    else return 0;
}

输入描述：
第一行输入整数n，表示n个大写字母。
第二行输入n个大写字母，字母之间用空格分隔。

输出描述：
输出冠军选手的字母。

样例输入：
8
A B G C E F H D

样例输出：
H
*/

#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
};

class LinkQueue
{
private:
    Node *front;
    Node *rear;

public:
    LinkQueue();
    void EnQueue(char);
    char DeQueue();
    char GetFront();
    bool IsEmpty();
};

LinkQueue::LinkQueue()
{
    front = new Node();
    front->next = nullptr;
    rear = front;
}

void LinkQueue::EnQueue(char x)
{
    Node *p = new Node();
    p->data = x;
    p->next = nullptr;

    rear->next = p;
    rear = p;
}

char LinkQueue::DeQueue()
{
    if (front->next == nullptr)
    {
        cout << "ERROR: DEQUEUE EMPTY QUEUE" << endl;
        exit(0);
    }

    Node *p = front->next;
    char value = p->data;
    front->next = p->next;

    if (p == rear)
    {
        rear = front;
    }

    delete p;
    return value;
}

char LinkQueue::GetFront()
{
    if (front->next == nullptr)
    {
        cout << "ERROR: EMPTY QUEUE" << endl;
        exit(0);
    }
    return front->next->data;
}

bool LinkQueue::IsEmpty()
{
    return front->next == nullptr;
}

int Comp(char mem1, char mem2)
{
    if (mem1 > mem2)
        return 1;
    else
        return 0;
}

int main()
{
    LinkQueue queue;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char player;
        cin >> player;
        queue.EnQueue(player);
    }

    while (!queue.IsEmpty())
    {
        char player1 = queue.DeQueue();

        if (queue.IsEmpty())
        {
            cout << player1 << endl;
            break;
        }

        char player2 = queue.DeQueue();

        if (Comp(player1, player2))
        {
            queue.EnQueue(player1);
        }
        else
        {
            queue.EnQueue(player2);
        }
    }

    return 0;
}
