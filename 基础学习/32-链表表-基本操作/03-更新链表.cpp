/*
问题描述
链表的定义及建立如同第1题《建立链表》。

然后输入一行新的 id 及 score，把原来链表中那个与这个新的 id 相同的 node 的 score 更新成新的 score。

若没有相同的，则什么都不要动。

输入描述
n+2行数据，其中前n+1行如同第1题《建立链表》 --  第1~n行行都是两个数字，第一个是 id，第二个是 score；第n+1行只有一个数字，0；（n 可能是 0）；

第n+2行有2个数字，new_id 及 new_score；

可以假设输入的格式及内容都是合理及正确的。

输出描述
*** LISTING ***

〈中间是原来的每一组数据，id 与 score 之间以 tab 隔开〉，最后换行；

*** END OF FILE ***

*** NEW LISTING ***

〈中间是更新后的每一组数据，id 与 score 之间以 tab 隔开〉，最后换行；

*** END OF FILE ***

样例输入
案例1：

11 80

212 90

1234 91

0

212 100

案例2：

11 80

212 90

1234 91

0

222 100

样例输出
案例1：

*** LISTING ***

11     80

212    90

1234   91

*** END OF FILE ***

*** NEW LISTING ***

11     80

212    100

1234   91

*** END OF FILE ***

案例2：

*** LISTING ***

11     80

212    90

1234   91

*** END OF FILE ***

*** NEW LISTING ***

11     80

212    90

1234   91

*** END OF FILE ***

提示说明
案例1中，node 212 的那一行已被更新；

案例2中，node 222 没有找到，所以数据没有更动。
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

    // 更新链表
    void update(int id, int score)
    {

        // 补充代码
        // 找到链表中与new_id相同的结点，用while语句去找就行。
        // 把new_score赋值给该结点的score。

        student *p = head;
        while (p != nullptr)
        {
            if (p->id == id)
            {
                p->score = score;
                break;
            }
            else
            {
                p = p->next;
            }
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

    int new_id, new_score;
    cin >> new_id >> new_score;
    cout << "*** LISTING ***" << endl;
    temp.traverse();
    cout << "*** NEW LISTING ***" << endl;
    temp.update(new_id, new_score);
    temp.traverse();
}
