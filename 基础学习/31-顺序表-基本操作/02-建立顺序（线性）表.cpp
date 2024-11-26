/*
问题描述
定义一个Student类包含两个属性：一个 int 类型的 id，及一个 int 类型的 score; 每个Student实例相当于一个数据元素，顺序表不超过100个数据元素。

输入的 id 及 score 可以假设都是合理及正确的。

最后，从头开始 display 所有的数据元素; id 及 score 之间间隔一个空格, 每个数据元素之后都要换行。第一行之前先输出一行 "*** LISTING ***"；最后一行之后再输出一行 "*** END OF FILE ***"。



输入描述
若干行数据；每一行都是两个数字（除了最后一行）；第一个是 id；第二个是 score；

最后一行只有一个数字，0；（注意可能数据总共只有1行）

可以假设输入的格式及内容都是合理及正确的。

输出描述
*** LISTING ***

〈中间是每一组数据，id 与 score 之间以空格隔开〉，最后换行；

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
提示说明
最后一行 “*** END OF FILE ***” 后，也要换行。
}
*/

#include <iostream>
using namespace std;

const int Maxsize = 100;

class Student
{
public:
    int id;
    int score;
};

class SeqList
{
public:
    SeqList()
    {
        length = 0;
    }
    SeqList(Student a[], int n)
    {

        // 未完成函数
        // 这里是用数组a来给数组data进行赋值。
        for (int i = 0; i < n; i++)
        {
            data[i] = a[i];
        }
        length = n;
    }

    void PrintList()
    {

        // 未完成函数
        // 这里是输出数组里的每个元素，但每个元素保护id和score，所以，还需要用data[i].id 和data[i].score的方式来输出。
        cout << "*** LISTING ***" << endl;
        for (int i = 0; i < length; i++)
        {
            cout << data[i].id << " " << data[i].score << endl;
        }
        cout << "*** END OF FILE ***" << endl;
    }

private:
    int length;

    Student data[Maxsize];
};

int main()
{

    Student a[100];

    // 未完成函数
    // 这个是输入数组a，而数组a什么时候结束，是根据输入的id是否等于0来进行判断
    // 当id不等于0的时候，才进行score的输入。如果id等于0，就不进行score的输入。

    int n = 0;
    while (cin >> a[n].id)
    {
        if (a[n].id == 0)
        {
            break;
        }
        cin >> a[n].score;
        n++;
    }

    SeqList list(a, n);

    list.PrintList();

    return 0;
}
