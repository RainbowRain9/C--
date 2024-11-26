/*
问题描述
反转链表，或者说是对链表的结点进行逆置。

给定一系列整数（例如：1, 2, 3, 4, 5），编写一个程序通过控制台输入这些整数，建立一个单链表，然后反转链表并输出反转后的结果。


输入描述
用户通过控制台输入整数个数n，然后再输入n个整数，以空格分隔。

输出描述
反转后的单链表，输出链表节点值，空格分隔。

样例输入
5 1 2 3 4 5

样例输出
5 4 3 2 1
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;

    Node *next;

    Node() : next(nullptr) {}

    Node(int data) : data(data), next(nullptr) {}
};

class Link
{
private:
    Node *head;

public:
    Link()
    {
        head = new Node();
    }

    void addnode(int data)
    {
        Node *node = new Node(data);

        Node *p = head;

        while (p->next != nullptr)
        {
            p = p->next;
        }

        p->next = node;
    }

    void traverse()
    {
        Node *p = head;

        while (p->next != nullptr)
        {
            if (p == head)
                cout << p->next->data;

            else
                cout << " " << p->next->data;

            p = p->next;
        }
    }

    // 反转链表
    void reverse()
    {
        Node *p = head->next;

        while (p != nullptr && p->next != nullptr)
        {
            Node *q = p->next;
            p->next = q->next;
            q->next = head->next;
            head->next = q;
            p = p->next;
        }
        
    }
};
int main()
{
    int n;
    cin >> n;
    Link link;
    while (n--)
    {
        int data;

        cin >> data;

        link.addnode(data);
    }
    link.reverse();

    link.traverse();

    return 0;
}