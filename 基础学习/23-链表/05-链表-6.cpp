/*
描述
把多个学生的资料（包含学号、姓名和成绩）依次存到一个链表中，每个学生的节点均放置在当前链表的尾部，然后遍历访问并输出所有学生的资料。

接着把所有成绩小于60的学生从链表中删除，再次遍历访问并输出链表中剩下的学生资料。

输入
只有一组案例。

一个正整数n，表示学生的数量。

然后有n行数据，每行数据代表一个学生的资料。每行数据由两个字符串a、b和一个整数c组成，其中a表示学号，b表示姓名，c表示成绩。

输出
输出链表中所有学生的资料，每个学生的资料占一行，每行的输出格式是：学号 姓名 成绩，每两个值之间间隔一个空格。

然后输出一行由10个减号组成的字符：----------。

接着删掉所有成绩小于60的节点后，再次重复一次遍历输出过程，格式要求和上面一样。

最后一个学生资料输出完以后也要换行。

样例输入
3

S001 AAA 70

S002 BBB 40

S003 CCC 80

样例输出
S001 AAA 70

S002 BBB 40

S003 CCC 80

----------

S001 AAA 70

S003 CCC 80


提示说明
必须按要求用链表实现
*/

#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    string ID;
    string name;
    int score;

    Student *next;
    Student() : next(nullptr) {}
    Student(string id_, string name_, int score_) : ID(id_), name(name_), score(score_), next(nullptr) {}

    void display()
    {
        cout << ID << " " << name << " " << score << endl;
    }
};

class Link
{
public:
    Student *head;
    Link() : head(new Student()) {}

    void addNodeTail(Student a)
    {
        Student *p = head, *q = head->next;
        while (q != nullptr)
        {
            p = p->next;
            q = q->next;
        }
        p->next = new Student(a);
    }
    void deleteByMaxScore(int max)
    {
        Student *p = head, *q = head->next;
        while (q != nullptr)
        {
            if (q->score < max)
            {
                p->next = q->next;
                delete q;
                q = p->next;
            }
            else
            {
                p = p->next;
                q = q->next;
            }
        }
    }
    void display()
    {
        Student *p = head->next;
        while (p != nullptr)
        {
            p->display();
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
        Student stu;
        cin >> stu.ID >> stu.name >> stu.score;
        link.addNodeTail(stu);
    }
    link.display();
    link.deleteByMaxScore(60);
    cout << "----------" << endl;
    link.display();
    return 0;   
}   