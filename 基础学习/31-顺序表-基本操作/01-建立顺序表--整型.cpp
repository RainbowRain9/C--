/*
问题描述
从控制台输入一组整型数据，并输出。

输入描述
输入一个自然数n，后面紧跟着n个整型数据。

输出描述
输出这个n个数字

样例输入
5 1 2 3 4 5

样例输出
1 2 3 4 5
*/

#include <iostream>

using namespace std;

const int Maxsize = 100;

class SeqList
{

public:
    SeqList()
    {
        length = 0;
    }

    SeqList(int a[], int n)
    {

        // 补充代码，参考课本p33页
        for (int i = 0; i < n; i++)
        {
            data[i] = a[i];
        }
        length = n;
        // 这个是有参数构造函数，外面传递一个数组，这里把这个数组赋值给线性表中的数组data[]
    }

    void PrintList()
    {

        // 补充代码
        // 这个输出有个细节，输出每个整型数值之间是有空格的，而最后一个数值之后是没有空格的。
        // 所以，当你用for循环输出数组中的元素时，只输出到倒数第二个
        // 最后一个元素单独输出，输出之后不能再有空格。
        for (int i = 0; i < length - 1; i++)
        {
            cout << data[i] << " ";
        }
        cout << data[length - 1] << endl;
    }

private:
    int length;

    int data[Maxsize];
};

int main()
{

    int a[100];

    // 补充输入数组个数n，数组a的代码。
    int n;
    // 其实就是cin>>n;加上for循环输入到a数组中。
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    SeqList list(a, n);

    list.PrintList();

    return 0;
}