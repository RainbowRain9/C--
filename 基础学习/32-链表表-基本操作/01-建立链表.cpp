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

class student
{

public:
    int id;

    int score;

    student *next;

    student()
    {

        next = nullptr; // 这条语句确保新创建的结点的指针域都为空。
    }

    void display()
    {

        cout << id << "\t" << score << endl;
    }
};

class Link
{

private:
    student *head;

public:
    Link()
    {
        head = new student();
    }

    void insert(int id, int score)
    {

        // 补充代码
        // 这里需要创建新结点
        // 新结点student类型，有两个成员，id和score都需要赋值。
        // 定义工作指针p，
        // 找到现有链表的最后一个结点，用while语句去找就行。
        // 把新结点链接到p指针的后面。

        student *newnode = new student();
        newnode->id = id;
        newnode->score = score;
        newnode->next = nullptr;
        student *p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = newnode;
    }

    void traverse()

    {
        // B
        // 定义工作指针，所有结点输出一次，每个结点包含id和score都需要输出

        student *p = head->next;
        
        cout << "*** LISTING ***" << endl;
        while (p != nullptr)
        {

            cout << p->id << "\t" << p->score << endl;

            p = p->next;
        }
        cout << "*** END OF FILE ***";
    }
};

int main()
{

    int id, score;

    Link temp;

    while (1)
    {

        cin >> id;

        if (id == 0)
        {
            break;
        }

        else
        {
            cin >> score;
            
            temp.insert(id, score);
            
        }
    }

    temp.traverse();
}
