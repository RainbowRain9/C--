/*
问题描述：
使用链表实现一个栈，每个数据元素包含一个 int 类型的 data 成员。栈的最大容量为 100 个元素。

输入数据保证合理且正确。

最后输出栈中剩余的所有数据元素，每个元素单独占一行。
输出格式：
- 第一行输出 "*** BEGIN OF STACK ***"
- 接着每行输出一个栈元素（后进先出顺序）
- 最后一行输出 "*** END OF STACK ***"
每行末尾都需要换行。

输入格式：
第一行为一个正整数 K，表示栈的最大容量。
第二行为一个正整数 N，表示后续操作数。
接下来 N 行，每行格式如下：
- "1 x": 将整数 x 入栈
- "2": 执行出栈操作
注意：输入可能只有两行，即 N=0 的情况。

输出格式：
*** BEGIN OF STACK ***
[栈元素，每个占一行，后进先出顺序]
*** END OF STACK ***

样例输入：
例 1:
10    // 栈容量为 10
4     // 4 个操作
1 80  // 入栈 80
2     // 出栈
1 90  // 入栈 90
1 91  // 入栈 91

例 2:
20    // 栈容量为 20
2     // 2 个操作
1 80  // 入栈 80
2     // 出栈

样例输出：
例 1:
*** BEGIN OF STACK ***
91
90
*** END OF STACK ***

例 2:
*** BEGIN OF STACK ***
*** END OF STACK ***
*/
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkStack
{
private:
    Node *top;
    int size;
    int capacity;

public:
    LinkStack(int maxSize);
    void Push(int);
    void Pop();
    void PrintStack();
};

LinkStack::LinkStack(int maxSize)
{
    top = nullptr;
    size = 0;
    capacity = maxSize;
}

void LinkStack::Push(int x)
{
    if (size >= capacity)
    {
        return;
    }
    Node *p = new Node();
    p->data = x;
    p->next = top;
    top = p;
    size++;
}

void LinkStack::Pop()
{
    if (top == nullptr)
    {
        return;
    }
    Node *p = top;
    top = top->next;
    delete p;
    size--;
}

void LinkStack::PrintStack()
{
    cout << "*** BEGIN OF STACK ***" << endl;
    Node *p = top;
    while (p != nullptr)
    {
        cout << p->data << endl;
        p = p->next;
    }
    cout << "*** END OF STACK ***" << endl;
}

int main()
{
    int num;
    cin >> num;
    LinkStack stack(num);
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        if (m == 1)
        {
            int s;
            cin >> s;
            stack.Push(s);
        }
        else
        {
            stack.Pop();
        }
    }
    stack.PrintStack();
    return 0;
}