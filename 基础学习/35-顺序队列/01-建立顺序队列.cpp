/*
问题描述
限用顺序，循环，有一个多余的空格的队列。

每一个数据元素只含一个 int 类型的 data; 队列最多不超过100个数据元素。

输入的数据可以假设都是合理及正确的。

最后，在输出队列中所有剩下的数据元素时，每个数据元素单独一行（ 每个之后都要换行）。第一行之前先输出一行 "*** BEGIN OF QUEUE ***"；最后一行之后再输出一行 "*** END OF QUEUE ***"，也要换行。




输入描述
N+2行数据；第1行是1个正整数K，代表队列的长度；第2行是1个正整数N，代表后面还有N行；然后是N行，每一行若第1个数字是1表示入队，则这行还有第2个数字是实际data；若第1个数字是2，则表示出队，这行就只有这1个数字。（注意可能数据总共只有2行）

可以假设输入的格式及内容都是合理及正确的。


输出描述
*** BEGIN OF QUEUE ***

〈中间是0或多行数据，每个数据自成一行〉

*** END OF QUEUE ***



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
例1：队列中还有2个数字：90及91，输出时是先进的先出。

*** BEGIN OF QUEUE ***

90

91

*** END OF QUEUE ***

例2：最后队列中是空的。

*** BEGIN OF QUEUE ***

*** END OF QUEUE ***
*/

#include <iostream>
using namespace std;

const int QueueSize = 100;

template <typename DataType>

class CirQueue

{

private:
    DataType data[QueueSize];

    int front, rear;

public:
    CirQueue()

    {
        front = rear = 0;
    }

    ~CirQueue() {}

    void EnQueue(DataType x)

    {
        if ((rear + 1) % QueueSize == front)
        {
            throw "Queue is full";
        }
        data[rear] = x;
        rear = (rear + 1) % QueueSize;
    }

    DataType DeQueue()

    {
        if (front == rear)
        {
            throw "Queue is empty";
        }
        DataType temp = data[front];
        front = (front + 1) % QueueSize;
        return temp;
    }

    void display()

    {
        int i = front;
        while (i != rear)
        {
            cout << data[i] << endl;
            i = (i + 1) % QueueSize;
        }
    }
};

int main()

{

    CirQueue<int> q;

    int m,
        n;

    cin >> m >> n;

    while (n--)

    {

        int a;

        cin >> a;

        if (a == 1)

        {

            int b;

            cin >> b;

            // 入队
            q.EnQueue(b);
        }

        else

        {

            // 出队
            q.DeQueue();
        }
    }

    cout << "*** BEGIN OF QUEUE ***\n";

    // 输出队列中的元素
    q.display();

    cout << "*** END OF QUEUE ***";

    return 0;
}