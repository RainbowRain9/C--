/*问题描述
线性表表的定义及建立如同第1题《建立顺序(线性)表》。

然后输入一个数字 tid，查找在该顺序表中是否有一个node的 id 与它相同。

输入描述
n+2行数据，其中前n+1行如同第1题《建立顺序(线性)表》--  第1~n行行都是两个数字，第一个是 id，第二个是 score；第n+1行只有一个数字，0；（n 可能是 0）；

第n+2行也只有一个数字，tid；

可以假设输入的格式及内容都是合理及正确的。

输出描述
若 tid 与某一个 node 的 id 相同，则输出该 id 及相对的 score，两个数字之间以空格间隔，然后换行；

若 tid 不同于所有 node 的 id，则输出 "NOT FOUND"，然后换行。

样例输入
11 80

212 90

1234 91

0

212

样例输出
212 90
*/

#include <iostream>

using namespace std;

const int Maxsize = 100;

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

    int Locate(int id);

    ~SeqList();
};

SeqList::SeqList(Student a[], int n)

{

    if (n > 100)

        throw "非参数法";

    for (int i = 0; i < n; i++)

        data[i] = a[i];

    length = n;
}

int SeqList::Locate(int id)
{

    // 补充代码

    // 这里根据id去查询data中是否某个student的id和外面输入的id相等，相等就是找到了，然后输出。

    // 否则输出 cout << "NOT FOUND" << endl;

    for (int i = 0; i < length; i++)
    {
        if (data[i].id == id)
        {
            cout << data[i].id << " " << data[i].score << endl;
            return 1;
        }
    }
    cout << "NOT FOUND" << endl;

    return 0;
}

SeqList::~SeqList()

{
}

int main()
{

    Student a[100];

    int n = 0, ID, tid;

    while (cin >> ID && ID != 0)

    {

        a[n].id = ID;

        cin >> a[n++].score;
    }
        
    cin >> tid;

    SeqList sqList(a, n);

    sqList.Locate(tid);

    return 0;
}