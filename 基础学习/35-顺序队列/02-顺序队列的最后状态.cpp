/*
问题描述
限用顺序，循环，有一个多余的空格的队列。

每一个数据元素只含一个 int 类型的 data; 栈最多不超过100个数据元素。

输入的数据可以假设都是合理及正确的。

最后输出只有一行：一个数字，或"ERROR: DEQUEUE EMPTY QUEUE"，或"ERROR: ENQUEUE FULL QUEUE"，之后换行。

输入描述
N+2行数据；第1行是1个正整数K，代表队列的长度；第2行是1个正整数N，代表后面还有N行；然后是N行，每一行若第1个数字是1表示入队，则这行还有第2个数字是实际data；若第1个数字是2，则表示出队，这行就只有这1个数字。（注意可能数据总共只有2行）

可以假设输入的格式及内容都是合理及正确的。

输出描述
1个数字，表示队列中数据元素的数目；或
ERROR: DEQUEUE EMPTY QUEUE 或
ERROR: ENQUEUE FULL QUEUE

样例输入
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

样例输出
例1：队列中还有2个数字：
2

例2：队列已空时，又有出队指令。
ERROR: DEQUEUE EMPTY QUEUE

例3：队列已满时，又有入队指令。
ERROR: ENQUEUE FULL QUEUE
*/

#include <iostream>
using namespace std;

const int MaxSize = 100;

class CirQueue
{
private:
    int data[MaxSize];
    int front;
    int rear;
    int count;
    int capacity;

public:
    CirQueue(int size) : front(0), rear(0), count(0), capacity(size) {}

    bool EnQueue(int x)
    {
        if (count == capacity)
        {
            return false;
        }
        data[rear] = x;
        rear = (rear + 1) % capacity;
        count++;
        return true;
    }

    bool DeQueue()
    {
        if (count == 0)
        {
            return false;
        }
        front = (front + 1) % capacity;
        count--;
        return true;
    }

    int size() const
    {
        return count;
    }
};

int main()
{
    int K, N;
    cin >> K >> N;

    CirQueue queue(K);

    while (N--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int val;
            cin >> val;
            if (!queue.EnQueue(val))
            {
                cout << "ERROR: ENQUEUE FULL QUEUE" << endl;
                return 0;
            }
        }
        else
        {
            if (!queue.DeQueue())
            {
                cout << "ERROR: DEQUEUE EMPTY QUEUE" << endl;
                return 0;
            }
        }
    }

    cout << queue.size() << endl;
    return 0;
}