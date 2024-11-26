/*问题描述
顺序表的定义及建立如同第1题《建立顺序(线性)表》。

然后输入一行新的 id 及 score，把原来顺序表中那个与这个新的 id 相同的 node 的 score 更新成新的 score。

若没有相同的，则什么都不要动。

输入描述
n+2行数据，其中前n+1行如同第2题《建立顺序(线性)表》--  第1~n行行都是两个数字，第一个是 id，第二个是 score；第n+1行只有一个数字，0；（n 可能是 0）；

第n+2行有2个数字，new_id 及 new_score；

可以假设输入的格式及内容都是合理及正确的。

输出描述
*** LISTING ***

〈中间是原来的每一组数据，id 与 score 之间以空格隔开〉，最后换行；

*** END OF FILE ***

*** NEW LISTING ***

〈中间是更新后的每一组数据，id 与 score 之间以空格隔开〉，最后换行；

*** END OF FILE ***

样例输入
11 80

212 90

1234 91

0

212 100



样例输出
*** LISTING ***

11 80

212 90

1234 91

*** END OF FILE ***

*** NEW LISTING ***

11 80

212 100

1234 91


*** END OF FILE ***
*/

#include <iostream>
using namespace std;

class Student
{
public:
    int id, score;
};

class SeqList

{

    Student data[100];

    int length;

public:
    SeqList();

    SeqList(Student a[], int n);

    void display()
    {
        cout << "*** LISTING ***\n";
        for (int i = 0; i < length; i++)
            cout << data[i].id << " " << data[i].score << endl;
        cout << "*** END OF FILE ***\n";
    }

    void Update(int nodeid, int nodescore);

    void newdisplay()
    {
        cout << "*** NEW LISTING ***\n";
        for (int i = 0; i < length; i++)
            cout << data[i].id << " " << data[i].score << endl;
        cout << "*** END OF FILE ***\n";
    }

    ~SeqList();
};

SeqList::SeqList()

{
    length = 0;
}

SeqList::SeqList(Student a[], int n)
{

    if (n > 100)

        throw "参数非法";

    for (int i = 0; i < n; i++)

        data[i] = a[i];

    length = n;
}

void SeqList::Update(int nodeid, int nodescore)
{

    // for循环根据id去查找，并更新score
    for (int i = 0; i < length; i++)
    {
        if (data[i].id == nodeid)
        {
            data[i].score = nodescore;
        }
    }
}

SeqList::~SeqList() {}

int main()

{

    Student a[100];

    // 补充代码
    int n = 0, ID, new_id, new_score;
    while (cin >> ID && ID != 0)
    {
        a[n].id = ID;
        cin >> a[n++].score;
    }
    cin >> new_id >> new_score;

    SeqList sqList(a, n);

    // 补充代码
    sqList.display();

    sqList.Update(new_id, new_score);

    // 补充代码
    sqList.newdisplay();

    return 0;
}
