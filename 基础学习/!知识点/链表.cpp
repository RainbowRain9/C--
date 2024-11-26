#include <iostream>
using namespace std;

class Node
{
public:
    string id;
    string name;
    int score;

    Node *next;

    Node() : next(nullptr) {}

    Node(string id_, string name_, int score_) : id(id_), name(name_), score(score_) {}

    Node(Node &n) : id(n.id), name(n.name), score(n.score), next(n.next) {}

    void display()
    {
        cout << "ID" << id << "\tName" << name;
    }
};

class Link
{
public:
    Link()
    {
        head = new Node();
    }

    ~Link()
    {
        Node *p = head;
        while (p != nullptr)
        {

            delete p;
            p = q;
        }
    }

    void addNodeHead(Node *n) // 添加节点到链表头部
    {
        Node *newNode = new Node(*n);
        // 创建一个新的Node对象，使用传入的Node对象n来初始化它
        newNode->next = head->next;
        // 将新结点的next指针指向原来链表的第一个数据结点（即头结点的下一个结点）
        head->next = newNode;
        // 将头结点的next指针指向新的结点，这样新结点就成为了链表的第一个数据结点
    }

    void addNodeTail(Node *n) // 链表的尾部添加一个新的结点
    {
        Node *p = head;            // 从链表的头结点开始遍历
        while (p->next != nullptr) // 遍历链表，直到p指向最后一个数据结点
        {
            p = p->next; // 将p指针移动到下一个结点
        }
        Node *newNode = new Node(*n);
        // 创建一个新的Node对象，使用传入的Node对象n来初始化它
        p->next = newNode;
        // 将p指向的最后一个数据结点的next指针指向新结点，将新结点添加到链表的末尾
    }

    void addNodeByID(Node *n) // 根据 id 添加节点到链表中合适的位置
    {
        Node *p = head;
        // 从链表的头结点开始遍历
        while (p->next != nullptr && p->next->id < n->id)
        // 当且仅当p的下一个结点存在且其ID小于新结点的ID时
        {
            p = p->next;
        }
        // 移动到下一个结点
        Node *newNode = new Node(*n);
        // 创建一个新的Node对象，使用传入的Node对象n来初始化它
        newNode->next = p->next;
        // 将新结点的next指针指向p指向结点的下一个结点
        p->next = newNode;
        // 将p指向结点的next指针指向新结点，从而将新结点插入链表
    }

    void deleteByID(string ID) // 删除链表中特定ID的节点
    {
        Node *p = head->next; // 初始化指针p，指向链表的第一个数据结点（跳过头结点）
        Node *q = head;       // 初始化指针q，指向链表的头结点

        while (p != nullptr) // 循环直到p指向nullptr，即链表末尾
        {
            if (p->ID == ID) // 检查当前p指向的结点的ID是否与要删除的ID相匹配
            {
                q->next = p->next; // 将q的next指针指向p的next指针，从而跳过p指向的结点
                delete (p);        // 释放p指向的结点的内存
                p = q->next;       // 移动p到q的下一个结点，继续遍历或退出循环
                break;             // 找到并删除结点后，退出循环
            }
            else // 如果当前结点的ID不匹配
            {
                p = p->next; // 移动p到下一个数据结点
                q = q->next; // 同时移动q到下一个结点，保持q始终指向p的前一个结点
            }
        }
    }

    // 定义一个名为deleteNode的函数，它接受一个字符串类型的参数Id
    void deleteNode(string Id)
    {
        // 声明一个指向Node类型的指针p，初始化为指向链表的第二个节点(head节点通常是一个哑节点)
        Node *p = head->next;
        // 声明一个指向Node类型的指针q，初始化为指向链表的头节点(head节点)
        Node *q = head;
        // 使用while循环遍历链表，直到p指针指向nullptr（即链表末尾）
        while (p != nullptr)
        {
            // 如果当前节点p的id与传入参数Id相等
            if (p->id == Id)
            {
                // 则删除节点p
                delete (p);
                // 退出循环
                break;
            }
            else
            {
                // 如果当前节点p的id与Id不相等，将p和q指针都向前移动到下一个节点
                p = p->next;
                q = q->next;
            }
        }
    }
    void traverse()
    {
        Node *p = head->next;
        while (p != nullptr)
        {
            p->display();
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{

    return 0;
}