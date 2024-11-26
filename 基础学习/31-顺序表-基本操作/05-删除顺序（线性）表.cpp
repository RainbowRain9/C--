/*问题描述
顺序表的定义及建立如同第1题《建立顺序(线性)表》。

然后删除这个顺序表中的某一个数据元素。若原来的就是空顺序表，则仍然是空顺序表。

输入描述
n+2行数据，其中前n+1行如同第2题《建立顺序(线性)表》--  第1~n行行都是两个数字，第一个是 id，第二个是 score；第n+1行只有一个数字，0；（n 可能是 0）；

第n+2行有1个数字，new_id；

可以假设输入的格式及内容都是合理及正确的。

输出描述
*** LISTING ***

〈中间是原来的每个数据元素，id 与 score 之间以空格隔开〉，最后换行；

*** END OF FILE ***

*** NEW LISTING ***

〈中间是删除 new_id 那个数据元素后的每个数据元素，id 与 score 之间以空格隔开；若 new_id 不存在，则不做任何删除〉，最后换行；

*** END OF FILE ***

样例输入
11 80

212 90

1234 91

0

212


样例输出
*** LISTING ***

11 80

212 90

1234 91

*** END OF FILE ***

*** NEW LISTING ***

11 80

1234 91

*** END OF FILE ***



提示说明
212 90 的那一行被删除了。

若要删除的数据元素不存在，则无删除可作，也就是 NEW LISTING 就会跟原来的一样。
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

    void Detele(int did);

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

void SeqList::Detele(int did)
{

    // for循环根据id去查找，并删除score
    for (int i = 0; i < length; i++)
    {
        if (data[i].id == did)
        {
            data[i] = data[i + 1];
            length--;
        }
    }
}

SeqList::~SeqList() {}

int main()

{

    Student a[100];

    // 补充代码
    int n = 0, ID, new_id;
    while (cin >> ID && ID != 0)
    {
        a[n].id = ID;
        cin >> a[n++].score;
    }
    cin >> new_id;

    SeqList sqList(a, n);

    // 补充代码
    sqList.display();

    sqList.Detele(new_id);

    // 补充代码
    sqList.newdisplay();

    return 0;
}
