/*
问题描述
链表的定义及建立如同第1题《建立链表》。

然后输入一个数字 tid，查找在这个链表中是否有一个 node 的 id 与它相同。

输入描述
n+2行数据，其中前n+1行如同第1题《建立链表》 --  第1~n行行都是两个数字，第一个是 id，第二个是 score；第n+1行只有一个数字，0；（n 可能是 0）；

第n+2行也只有一个数字，tid；

可以假设输入的格式及内容都是合理及正确的。

输出描述
若 tid 与某一个 node 的 id 相同，则输出该 id 及相对的 score，两个数字之间以 tab 间隔，然后换行；

若 tid 不同于所有 node 的 id，则输出 "NOT FOUND"，然后换行。

样例输入
案例1：

11 80

212 90

1234 91

0

212

案例2：

11 80

212 90

1234 91

0

222

样例输出
案例1：

212    90

案例1：

NOT FOUND
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

    void Locate(int x)
    {
        student *p = head->next;
        while (p != nullptr)
        {
            if (p->id == x)
            {
                cout << p->id << "\t" << p->score << endl;
                return;
            }
            p = p->next;
        }
        cout << "NOT FOUND" << endl;
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

    int x;
    cin >> x;

    temp.Locate(x);
}
