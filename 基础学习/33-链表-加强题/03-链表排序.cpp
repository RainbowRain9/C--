/*
问题描述
编写一个程序来创建一个单链表，并对该链表进行排序。要求使用C++语言实现链表的排序，排序方式为升序排列。

输入描述
第一行输入一个整数 n，表示链表中元素的个数。

接下来一行输入 n 个整数，表示链表中的元素。

输出描述
输出排序后的链表元素，每个元素之间用空格隔开。

样例输入
5

4 2 1 3 5



样例输出
1 2 3 4 5



提示说明
使用单链表的数据结构来存储元素。

使用任意排序算法对链表进行排序（如冒泡排序、选择排序、插入排序或归并排序）。
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
            {
                cout << p->next->data;
            }

            else
                cout << " " << p->next->data;
        

            p = p->next;
        }
    }

    // 升序排序
    void sort()
    {
        Node *p = head->next;

        Node *q = nullptr;

        while (p != nullptr)
        {
            q = p->next;

            while (q != nullptr)
            {
                if (p->data > q->data)
                {
                    int temp = p->data;

                    p->data = q->data;

                    q->data = temp;
                }

                q = q->next;
            }

            p = p->next;
        }
    }
};

int main()
{
    Link link;

    int data, n;

    cin >> n;

    while (n--)
    {
        cin >> data;

        link.addnode(data);
    }

    link.sort();

    link.traverse();

    return 0;
}