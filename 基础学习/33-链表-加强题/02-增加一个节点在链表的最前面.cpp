/*
问题描述
链表的定义及建立如同《链表（1）》第1题《建立链表》。

现在请增加一个 node 在链表的最前面。

输入描述
n+2行数据，如同第1题《建立链表》 --  第1~n行行都是两个数字，第一个是 id，第二个是 score；第n+1行只有一个数字，0；（n 可能是 0）；

第n+2行是要增加的一行（两个数字，new_id 及 new_score）。

可以假设输入的格式及内容都是合理及正确的（也就是，不需要检查 new_id 及 new_score 是否有错误）。

输出描述
先列出初建立好的链表；

*** LISTING ***

〈中间是初建立时的每一组数据，id 与 score 之间以 tab 隔开〉，最后换行；

*** END OF FILE ***

再列出增加一个节点后的链表；

*** NEW LISTING ***

〈中间是增加一个节点后的每一组数据，id 与 score 之间以 tab 隔开〉，最后换行；

*** END OF FILE ***

样例输入
11 80

212 90

0

10 95

样例输出
*** LISTING ***

11     80

212    90

*** END OF FILE ***

*** NEW LISTING ***

10     95

11     80

212    90

*** END OF FILE ***
*/

/*
问题描述
每一个 node 含一个 int 类型的 id，及一个 int 类型的 score;

从空白链表开始，先输入一个 id；若为0，则表示输入完毕，否则用 new() 建立一个新的 node，加在链表的最后，再读入一个 score，并把该 id 及 score 存储在这个 node 中；重复以上动作，直到输入完毕。（注意，可能一开始就输入0，这样表示链表是空的）。输入的 id 及 score 可以假设都是合理及正确的。

最后，从头开始 display 所有的 nodes; id 及 score 之间间隔一个 tab, 每个 node 之后都要换行。第一行之前先输出一行 "*** LISTING ***"；最后一行之后再输出一行 "*** END OF FILE ***"。



输入描述
若干行数据；每一行都是两个数字（除了最后一行）；第一个是 id；第二个是 score；

最后一行只有一个数字，0；（注意可能数据总共只有1行）

可以假设输入的格式及内容都是合理及正确的。



输出描述
*** LISTING ***

〈中间是每一组数据，id 与 score 之间以 tab 隔开〉，最后换行；

*** END OF FILE ***



样例输入
11 80

212 90

1234 91

0



样例输出
*** LISTING ***

11 80

212 90

1234 91

*** END OF FILE ***
*/

#include <iostream>
using namespace std;

class Node
{

public:
    Node *next;

    int id, score;

    Node() : next(nullptr) {};

    Node(int id, int score) : id(id), score(score), next(nullptr) {}
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

    void addnode(int id, int score)
    {

        Node *node = new Node(id, score);

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

            cout << p->next->id << '\t' << p->next->score << endl;

            p = p->next;
        }
    }

    void Delete()
    {

        // 补充代码，如何实现删除最后一个结点，核心还是要找到倒数第二个结点

        // while(p->next!=nullptr&&p->next->next!=nullptr)通过这个while语句是可以找到倒数第二个结点的。

        Node *p = head;

        while (p->next != nullptr && p->next->next != nullptr)
        {

            p = p->next;
        }

        delete p->next;

        p->next = nullptr;
    }

    void addheadnode(int id, int score)
    {

        // 补充代码，在头结点前面新增一个结点。

        // 这里是要new一个Node，然后给它的id和score赋值。

        // 同时把这个结点链接到head的前面

        Node *node = new Node(id, score);

        node->next = head->next;

        head->next = node;
    }

    // 增加一个节点在链表的最后面
    void addtailnode(int id, int score)
    {

        Node *node = new Node(id, score);

        Node *p = head;

        while (p->next != nullptr)
        {

            p = p->next;
        }

        p->next = node;
    }
};

int main()
{

    Link link;

    int id, score;

    while (true)
    {

        cin >> id;

        if (id == 0)
        {

            break;
        }

        cin >> score;

        link.addnode(id, score);
    }

    int new_id, new_score;

    cin >> new_id >> new_score;

    cout << "*** LISTING ***" << endl;

    link.traverse();

    cout << "*** END OF FILE ***" << endl;

    link.addtailnode(new_id, new_score);

    cout << "*** NEW LISTING ***" << endl;

    link.traverse();

    cout << "*** END OF FILE ***" << endl;

    return 0;
}