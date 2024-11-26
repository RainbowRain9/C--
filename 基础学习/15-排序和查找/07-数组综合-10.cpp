/*
描述
本题请用顺序查找法实现。

确定一堆数字中有没有某些特定的值。

注意：数字只有固定的一堆，但是有很多key，每个key都要确定是否出现在这堆数字中。

输入
一个正整数n，表示这堆数字一共n个。然后是n个整数，表示这堆数字具体的值。

接下来是一个正整数m，然后是m个整数，表示需要判断的m个key值。

输出
针对每个key值，如果该key值出现在这n个整数中，则输出true，否则输出false。

每次输出完都要换行。（所以最后应该有m个true或者false）

样例输入
5 1 2 3 4 5

2 10 1

样例输出
false

true
*/
#include <iostream>
using namespace std;
template <typename T>
bool find(T a[], int n, T key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
            return true;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    int m, key;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    while (m--)
    {
        cin >> key;
        if (find(a, n, key))
        {
            cout << "true";
        }
        else
        {
            cout << "false";
        }
        cout << endl;
    }
    delete[] a;
    return 0;
}