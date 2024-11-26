// Source : https://xujcoj.com/home/contest/1957/problem/1
// Date   : 2024-11-14

/**************************************************
 * 题目描述：
 * 实现一个链栈，包含以下操作：
 * 1. push x：将x压入栈中
 * 2. pop：输出栈顶元素，并将其弹出栈
 * 3. top：输出栈顶元素
 *
 * 示例 1：
 *   输入：
 *   push 5
 *   push 2
 *   pop
 *   push 4
 *   top
 *   输出：
 *   2
 *   4
 *
 * 提示：
 *   - 1 <= 操作次数 <= 100
 *   - 1 <= x <= 100
 **************************************************/

/*
    解题思路：
    1. 使用链表实现栈的基本操作
    2. 定义链表节点结构体，包含数据域和指针域
    3. 实现push、pop、top三个基本操作
    4. 注意处理栈空的情况

    时间复杂度分析：
    - push操作：O(1)
    - pop操作：O(1)
    - top操作：O(1)
*/

#include <iostream>
using namespace std;

class LinkedStack
{

private:
    struct Node
    {

        int data;

        Node *next;

        Node(int val) : data(val), next(nullptr) {}
    };

    Node *top; // 栈顶指针

    int count; // 栈中元素个数

public:
    LinkedStack() : top(nullptr), count(0) {}

    ~LinkedStack()
    {

        while (top != nullptr)
        {

            Node *temp = top;

            top = top->next;

            delete temp;
        }
    }

    // 入栈操作

    void push(int data)
    {
        Node *p = new Node(data);
        p->next = top;
        top = p;
        count++;
    }

    // 出栈操作

    bool pop()
    {

        if (isEmpty())
        {
            return false;
        }

        // 补充代码
        Node *p = top;
        top = top->next;
        delete p;
        count--;
        return true;
    }

    // 检查栈是否为空

    bool isEmpty()
    {
        return top == nullptr;
    }

    // 获取栈的大小

    int size()
    {
        return count;
    }

    void printLinkStack()
    {
        // 输出栈中元素，补充代码
        if (isEmpty()) {
            return;
        }
        
        Node *p = top;
        while (p != nullptr)
        {
            cout << p->data << endl;
            p = p->next;
        }
    }
};

int main()
{

    int K;

    cin >> K; // 读取操作数量

    LinkedStack stack; // 创建链栈对象

    // 读取操作并执行

    for (int i = 0; i < K; ++i)
    {

        int operation;

        cin >> operation;

        if (operation == 1)
        {

            int data;

            cin >> data; // 读取入栈的数据

            stack.push(data); // 执行入栈操作
        }

        else if (operation == 2)
        {

            stack.pop(); // 执行出栈操作
        }
    }

    // 输出栈的最终状态

    cout << "*** BEGIN OF QUEUE ***" << endl;

    stack.printLinkStack();

    cout << "*** END OF QUEUE ***" << endl;

    return 0;
}

