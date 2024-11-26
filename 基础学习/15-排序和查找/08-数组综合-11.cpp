/*
描述
本题请用二分查找法实现。

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
bool binaryfind(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == a[mid])
            return true;
        else if (key > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int m, key;
    cin >> m;
    while (m--)
    {
        cin >> key;
        if (binaryfind(a, n, key))
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