/*
描述
定义一个结点类Node和一个链表类Link，以实现如下的输出。其中结点类Node的成员包含一个整数、一个指向结点类的指针以及必要的构造函数。链表类Link中需要实现的方法包括：(1) insert：使用参数值动态创建一个Node类的对象，加入到链表中的尾端；(2) traverse：遍历链表中的结点，按链表中的顺序输出结点中保存的整数。

#include<iostream>
using namespace std;
//①这里应该是Node类的定义
//②这里应该是Link类的定义
int main()
{
 Link link; //此时link中只有一个空的头结点
 link.insert(7); //存放数字7的结点连在头结点后面
 link.insert(2); //存放数字2的结点连在数字7的结点后面
 link.traverse(); //输出7 2，两个数字之间有一个空格，最后一个数字后面没有空格，要换行
 link.insert(3); //存放数字3的结点连在数字2的结点后面
 link.traverse(); //输出7 2 3，两个数字之间有一个空格，最后一个数字后面没有空格，要换行
 return 0;
}


输入
无

输出
7 2

7 2 3

样例输入


样例输出
7 2

7 2 3
*/

#include <iostream>
using namespace std;

// ① Node类的定义
// Node类代表链表中的一个结点，包含一个整数值x和一个指向下一个结点的指针next。
class Node
{
public:
    int x;      // 结点存储的整数值
    Node *next; // 指向链表中下一个结点的指针

    // Node类的构造函数
    Node() : next(nullptr) {}                // 默认构造函数，初始化next为nullptr
    Node(int x) : x(x), next(nullptr) {}     // 带参数的构造函数，用于创建带有特定整数值的结点
    Node(Node &n) : x(n.x), next(nullptr) {} // 拷贝构造函数，用于复制一个结点

    // display方法用于输出结点中的整数值
    void display()
    {
        cout << x;
    }
};

// ② Link类的定义
// Link类代表整个链表，包含一个指向头结点的指针head。
class Link
{
private:
    Node *head; // 指向链表头结点的指针

public:
    // Link类的构造函数
    Link()
    {
        head = new Node(); // 创建一个新的空头结点并初始化head
    }

    // Link类的析构函数
    ~Link()
    {
        Node *p = head; // 从head开始遍历链表
        while (p != nullptr)
        {
            Node *q = p->next; // 保存下一个结点的地址
            delete p;          // 释放当前结点的内存
            p = q;             // 移动到下一个结点
        }
    }

    // traverse方法用于遍历链表并输出所有结点中的整数值
    void traverse()
    {
        Node *p = head->next; // p指向第一个数据结点
        while (p != nullptr)
        {
            p->display(); // 调用display方法输出结点的值

            p = p->next; // 移动到下一个结点
            if (p != nullptr)
            {
                cout << " "; // 如果下一个结点存在，输出一个空格
            }
        }
        cout << endl; // 遍历结束后输出换行符
    }

    // insert方法用于在链表尾部插入一个新的结点
    void insert(int x)
    {
        Node *p = head; // 从头结点开始
        while (p->next != nullptr)
        {
            p = p->next; // 移动到下一个结点，直到到达链表的末尾
        }
        Node *newNode = new Node(x); // 创建一个新的结点
        p->next = newNode;           // 将新结点链接到链表末尾
    }
};

int main()
{
    Link link;       // 创建一个空的链表对象，初始只有一个头结点
    link.insert(7);  // 在链表尾部插入结点7
    link.insert(2);  // 在结点7之后插入结点2
    link.traverse(); // 遍历链表并输出7 2

    link.insert(3);  // 在结点2之后插入结点3
    link.traverse(); // 再次遍历链表并输出7 2 3

    return 0;
}