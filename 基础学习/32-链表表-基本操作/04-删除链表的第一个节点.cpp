/*
问题描述
链表的定义及建立如同第1题《建立链表》。

然后删除这个链表中的第一个 node。若原来的就是空链表，则仍然是空链表。

输入描述
n+1行数据，如同第1题《建立链表》 --  第1~n行行都是两个数字，第一个是 id，第二个是 score；第n+1行只有一个数字，0；（n 可能是 0）；

可以假设输入的格式及内容都是合理及正确的。

输出描述
先列出初建立好的链表；

*** LISTING ***

〈中间是初建立时的每一组数据，id 与 score 之间以 tab 隔开〉，最后换行；

*** END OF FILE ***

再列出删除第一个节点后的链表；若原来的就是空链表，则仍然是空链表；

*** NEW LISTING ***

〈中间是删除第一行后的每一组数据，id 与 score 之间以 tab 隔开〉，最后换行；

*** END OF FILE ***

样例输入
11 80

212 90

1234 91

0

样例输出
*** LISTING ***

11    80

212   90

1234  91

*** END OF FILE ***

*** NEW LISTING ***

212   90

1234  91

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

    // 删除链表
    void detele()
    {
        if (head->next != nullptr)
        { // 检查链表是否为空
            student *temp = head->next;
            head->next = temp->next; // 移除第一个节点
            delete temp;             // 释放内存
        }
    }
    void traverse()

    {
        // B
        // 定义工作指针，所有结点输出一次，每个结点包含id和score都需要输出

        student *p = head->next;
        while (p != nullptr)
        {

            p->display();

            p = p->next;
        }
        cout << "*** END OF FILE ***" << endl;
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

    cout << "*** LISTING ***" << endl;
    temp.traverse();
    cout << "*** NEW LISTING ***" << endl;
    temp.detele();
    temp.traverse();
}
