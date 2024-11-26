/*
问题描述
限用顺序栈。

每一个数据元素只含一个 int 类型的 data; 栈最多不超过100个数据元素。

输入的数据可以假设都是合理及正确的。

最后，在输出栈中所有剩下的数据元素时，每个数据元素单独一行（每个之后都要换行）。第一行之前先输出一行 "*** BEGIN OF STACK ***"；最后一行之后再输出一行 "*** END OF STACK ***"，也都要换行。

输入描述
N+1行数据；第1行是1个正整数N，代表后面还有N行；然后是N行，每一行若第1个数字是1表示入栈，则这行还有第2个数字是实际data；若第1个数字是2，则表示出栈，这行就只有这1个数字。

可以假设输入的格式及内容都是合理及正确的。

输出描述
*** BEGIN OF STACK ***

〈中间是0或多行数据，每个数据自成一行〉

*** END OF STACK ***

样例输入
例1：
4
1 80
2
1 90
1 91

例2：
2
1 80
2

样例输出
例1：栈中还有2个数据元素：90及91，输出时是后进的先出。
*** BEGIN OF STACK ***
91
90
*** END OF STACK ***

例2：最后栈中是空的。
*** BEGIN OF STACK ***
*** END OF STACK ***
*/

#include <iostream>
using namespace std;

const int MaxSize = 100;

class SeqStack

{

private:
    int top;

    int data[MaxSize];

public:
    SeqStack();

    ~SeqStack();

    void Push(int x);

    void Pop();

    void PrintStack();
};

SeqStack::SeqStack()

{
    top = -1; 
}

SeqStack::~SeqStack() {}

void SeqStack::Push(int x)
{
    if (top < MaxSize - 1)
    {
        data[++top] = x;
    }
    else
    {
        throw "栈已满，无法进栈";
    }
}

void SeqStack::Pop()
{
    if (top >= 0)
    {
        top--;
    }
    else
    {
        throw "栈为空，无法出栈";
    }
}

void SeqStack::PrintStack()
{
    cout << "*** BEGIN OF STACK ***" << endl;
    for (int i = top; i >= 0; i--)
    {
        cout << data[i] << endl;
    }
    cout << "*** END OF STACK ***" << endl;
}

int main()
{
    SeqStack se;
    int N, a, b;

    cin >> N;

    while (N--)
    {
        cin >> a;
        if (a == 1)
        {
            cin >> b;
            se.Push(b);
        }
        else if (a == 2)
        {
            se.Pop();
        }
        else
        {
            throw "输入错误";
        }
    }

    se.PrintStack();

    return 0;
}