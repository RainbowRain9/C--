#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *data; // 存储队列数据的数组

    int frontIndex; // 指向队头元素的位置

    int rearIndex; // 指向队尾元素的下一个位置

    int capacity; // 队列的容量

    int size; // 当前队列中的元素个数

public:
    // 构造函数：初始化队列

    CircularQueue(int maxCapacity)
    {

        capacity = maxCapacity;

        data = new int[capacity];

        frontIndex = 0;

        rearIndex = 0;

        size = 0;
    }

    // 析构函数：释放动态分配的内存

    ~CircularQueue()
    {

        delete[] data;
    }

    // 进队列

    bool enqueue(int value)
    {

        if (isFull())
        {
            return false; // 队列满时返回false
        }

        data[rearIndex] = value;

        rearIndex = (rearIndex + 1) % capacity; // 循环移动

        size++;

        return true;
    }

    // 获取队头元素

    int front()
    {

        if (isEmpty())
        {

            cout << "Queue is empty" << endl;

            return 0;
        }

        return data[frontIndex];
    }

    // 判断队列是否为空

    bool isEmpty()
    {

        return size == 0;
    }

    // 判断队列是否已满

    bool isFull()
    {

        // 补充代码
        return size == capacity;
    }

    // 出队列

    bool dequeue()
    {
        if (isEmpty())
        {
            return false;
        }

        frontIndex = (frontIndex + 1) % capacity;

        size--;

        return true;
    }
};

int main()
{

    int n, operation, value;

    cin >> n;

    CircularQueue queue(5); // 队列容量固定为5

    for (int i = 0; i < n; i++)
    {

        cin >> operation;

        if (operation == 1)
        { // 进队列

            cin >> value;

            if (queue.isFull())
            {

                cout << "Queue is full" << endl;
            }

            else
            {

                queue.enqueue(value);

                cout << "Enqueued " << value << endl;
            }
        }

        else if (operation == 2)
        { // 出队列

            if (queue.isEmpty())
            {

                cout << "Queue is empty" << endl;
            }

            else
            {

                cout << "Dequeued " << queue.front() << endl;

                queue.dequeue();
            }
        }
    }

    return 0;
}