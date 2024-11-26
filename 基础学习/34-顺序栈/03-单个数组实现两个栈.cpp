/*
问题描述
使用一个固定大小的数组来实现两个栈。数组的前半部分用于一个栈（栈A），后半部分用于另一个栈（栈B）。两个栈的底部分别在数组的两端。请实现以下功能：

1. 初始化两个栈。
2. 入栈操作（push），可以指定入栈到哪个栈。
3. 出栈操作（pop），可以指定从哪个栈出栈。
4. 判断栈是否为空（isEmpty）。
5. 获取栈顶元素（top），可以指定获取哪个栈的栈顶元素。
6. 获取两个栈的大小（sizeA和sizeB）。

数组的大小默认为100

输入描述
N+1行数据；
第1行是1个正整数N，代表后面还有N行；
然后是N行，每一行的格式如下：
- 若第1个数字是1，表示对栈A进行操作
- 若第1个数字是2，表示对栈B进行操作
- 第2个数字如果是1表示入栈，如果是2表示出栈
- 如果是入栈操作，则这行还有第3个数字表示实际入栈的数据

可以假设输入的格式及内容都是合理及正确的。

输出描述
*** BEGIN OF STACK A ***
〈中间是0或多行数据，每个数据自成一行〉
*** END OF STACK A ***

*** BEGIN OF STACK B ***
〈中间是0或多行数据，每个数据自成一行〉
*** END OF STACK B ***

样例输入
6
1 1 80
1 1 85
2 1 902
2 1 904
1 2
2 2

样例输出
*** BEGIN OF STACK A ***
80
*** END OF STACK A ***

*** BEGIN OF STACK B ***
902
*** END OF STACK B ***
*/

#include <iostream>
using namespace std;

const int MaxSize = 100;

class TwoStacks
{
private:
    int data[MaxSize];
    int topA;
    int topB;

public:
    TwoStacks();
    ~TwoStacks();
    void pushA(int x);
    void pushB(int x);
    void popA();
    void popB();
    bool isEmptyA();
    bool isEmptyB();
    int topElementA();
    int topElementB();
    int sizeA();
    int sizeB();
    void printStackA();
    void printStackB();
};

TwoStacks::TwoStacks()
{
    topA = -1;
    topB = MaxSize;
}

TwoStacks::~TwoStacks() {}

void TwoStacks::pushA(int x)
{
    data[++topA] = x;
}

void TwoStacks::pushB(int x)
{
    data[--topB] = x;
}

void TwoStacks::popA()
{
    topA--;
}

void TwoStacks::popB()
{
    topB++;
}

bool TwoStacks::isEmptyA()
{
    return topA == -1;
}

bool TwoStacks::isEmptyB()
{
    return topB == MaxSize;
}

int TwoStacks::topElementA()
{
    return data[topA];
}

int TwoStacks::topElementB()
{
    return data[topB];
}

int TwoStacks::sizeA()
{
    return topA + 1;
}

int TwoStacks::sizeB()
{
    return MaxSize - topB;
}

void TwoStacks::printStackA()
{
    cout << "*** BEGIN OF STACK A ***" << endl;
    for (int i = 0; i <= topA; i++)
        cout << data[i] << endl;
    cout << "*** END OF STACK A ***" << endl;
}

void TwoStacks::printStackB()
{
    cout << "*** BEGIN OF STACK B ***" << endl;
    for (int i = MaxSize - 1; i >= topB; i--)
        cout << data[i] << endl;
    cout << "*** END OF STACK B ***" << endl;
}

int main()
{
    TwoStacks stacks;
    int N, stack, operation, value;

    cin >> N;

    while (N--)
    {
        cin >> stack >> operation;
        if (operation == 1)
        {
            cin >> value;
            if (stack == 1)
                stacks.pushA(value);
            else
                stacks.pushB(value);
        }
        else if (operation == 2)
        {
            if (stack == 1)
                stacks.popA();
            else
                stacks.popB();
        }
    }

    stacks.printStackA();
    stacks.printStackB();

    return 0;
}
