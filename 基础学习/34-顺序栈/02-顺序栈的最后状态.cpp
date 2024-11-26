/*
问题描述：
限用顺序栈。每一个数据元素只含一个 int 类型的 data; 栈最多不超过100个数据元素。
输入的数据可以假设都是合理及正确的。
最后输出只有一行：一个数字，或"ERROR: POP EMPTY STACK"，或"ERROR: PUSH FULL STACK"，之后换行。

输入描述：
N+2行数据；
第1行是1个正整数K，代表栈的长度；
第2行是1个正整数N，代表后面还有N行；
然后是N行，每一行若第1个数字是1表示入栈，则这行还有第2个数字是实际data；
若第1个数字是2，则表示出栈，这行就只有这1个数字。
（注意可能数据总共只有2行）
可以假设输入的格式及内容都是合理及正确的。

输出描述：
1个数字，表示栈中数据元素的数目；或
ERROR: POP EMPTY STACK 或
ERROR: PUSH FULL STACK

样例输入：
例1：
10
4
1 80
2
1 90
1 91

例2：
2
3
1 80
2
2

例3：
2
3
1 70
1 80
1 90

样例输出：
例1：栈中还有2个数据元素：
2

例2：栈已空时，又有POP指令。
ERROR: POP EMPTY STACK

例3：栈已满时，又有PUSH指令。
ERROR: PUSH FULL STACK
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
    int datasize;

    SeqStack();
    ~SeqStack();

    void Push(int x);
    void Pop();
    void PrintStack();
    bool Empty();
    bool Full();
    int Length();
};

SeqStack::SeqStack()
{
    top = -1;
}

SeqStack::~SeqStack() {}

void SeqStack::Push(int x)
{
    data[++top] = x;
}

void SeqStack::Pop()
{
    if (top == -1)
        throw "下溢";
    top--;
}

void SeqStack::PrintStack()
{
    while (top != -1)
    {
        cout << data[top--] << endl;
    }
}

bool SeqStack::Empty()
{
    return top == -1;
}

bool SeqStack::Full()
{
    return top == datasize - 1;
}

int SeqStack::Length()
{
    return top + 1;
}

int main()
{
    SeqStack se;
    int K, N, a, b;

    cin >> K >> N;
    se.datasize = K;

    while (N--)
    {
        cin >> a;
        if (a == 1)
        {
            if (se.Full())
            {
                cout << "ERROR: PUSH FULL STACK" << endl;
                return 0;
            }
            cin >> b;
            se.Push(b);
        }
        else if (a == 2)
        {
            if (se.Empty())
            {
                cout << "ERROR: POP EMPTY STACK" << endl;
                return 0;
            }
            se.Pop();
        }
        else
        {
            throw "输入错误";
        }
    }

    cout << se.Length() << endl;
    return 0;
}
