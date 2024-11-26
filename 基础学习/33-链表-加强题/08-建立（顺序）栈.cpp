/*
问题描述
限用顺序栈。

每一个数据元素只含一个 int 类型的 data; 栈最多不超过100个数据元素。

输入的数据可以假设都是合理及正确的。

最后，在输出栈中所有剩下的数据元素时，每个数据元素单独一行（ 每个之后都要换行）。第一行之前先输出一行 "*** BEGIN OF STACK ***"；最后一行之后再输出一行 "*** END OF STACK ***"，也都要换行。




输入描述
N+2行数据；第1行是1个正整数K，代表栈的长度；第2行是1个正整数N，代表后面还有N行；然后是N行，每一行若第1个数字是1表示入栈，则这行还有第2个数字是实际data；若第1个数字是2，则表示出栈，这行就只有这1个数字。（注意可能数据总共只有2行）

可以假设输入的格式及内容都是合理及正确的。


输出描述
*** BEGIN OF STACK ***

〈中间是0或多行数据，每个数据自成一行〉

*** END OF STACK ***



样例输入
例1：

10

4

1 80

2

1 90

1 91

例2：

20

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


提示说明
这一题不会出现超出栈空或栈满的错误。
*/

#include <iostream>
using namespace std;

class Stack
{
private:
    int data[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool push(int x)
    {
        if (top == 99)
            return false;
        data[++top] = x;
        return true;
    }

    bool pop()
    {
        if (top == -1)
            return false;
        top--;
        return true;
    }

    int getTop()
    {
        return data[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    int n, m;
    cin >> n;
    Stack s;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int op, x;
        cin >> op;
        if (op == 1)
        {
            cin >> x;
            s.push(x);
        }
        else
        {
            s.pop();
        }
    }
    cout << "*** BEGIN OF STACK ***" << endl;
    while (!s.isEmpty())
    {
        cout << s.getTop() << endl;
        s.pop();
    }
    cout << "*** END OF STACK ***" << endl;
    
    return 0;
}