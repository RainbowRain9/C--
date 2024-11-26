/*
描述
定义一个结点类Node和一个链表类Link，以实现如下的输出。其中结点类Node的成员包含一个整数、一个指向结点类的指针以及必要的构造函数。链表类Link中需要实现的方法包括：(1) insert：使用参数值动态创建一个Node类的对象，加入到链表中的首部（头结点后面）；(2) traverse：遍历链表中的结点，按链表中的顺序输出结点中保存的整数。

#include<iostream>
using namespace std;
//①这里应该是Node类的定义
//②这里应该是Link类的定义
int main()
{
 Link link; //此时link中只有一个空的头结点
 link.insert(7); //存放数字7的结点连在头结点后面
 link.insert(2); //存放数字2的结点连在头结点后面，数字7的结点前面
 link.traverse(); //输出2 7，两个数字之间有一个空格，最后一个数字后面没有空格，要换行
 link.insert(3); //存放数字3的结点连在头结点后面，数字2的结点前面
 link.traverse(); //输出3 2 7，两个数字之间有一个空格，最后一个数字后面没有空格，要换行
 return 0;
}

输入
无

输出
2 7

3 2 7

样例输入


样例输出
2 7

3 2 7
*/

#include <iostream>
using namespace std;
// ①这里应该是Node类的定义
class Node
{
public:
    int x;
    Node *next;

    Node() : next(nullptr) {}
    Node(int x_) : x(x_), next(nullptr) {}
    Node(Node &n) : x(n.x), next(nullptr) {}

    void display()
    {
        cout << x;
    }
};  
// ②这里应该是Link类的定义
class Link
{
private:
    Node *head;

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
            Node *q = p->next;
            delete p;
            p = q;
        }
    }
    void insert(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = head->next;
        head->next = newNode;
    }
    void traverse()
    {
        Node *p = head->next;
        while (p != nullptr)
        {
            p->display();

            p = p->next;
            if (p != nullptr)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
};
int main()
{
    Link link;       // 此时link中只有一个空的头结点
    link.insert(7);  // 存放数字7的结点连在头结点后面
    link.insert(2);  // 存放数字2的结点连在头结点后面，数字7的结点前面
    link.traverse(); // 输出2 7，两个数字之间有一个空格，最后一个数字后面没有空格，要换行
    link.insert(3);  // 存放数字3的结点连在头结点后面，数字2的结点前面
    link.traverse(); // 输出3 2 7，两个数字之间有一个空格，最后一个数字后面没有空格，要换行
    return 0;
}
