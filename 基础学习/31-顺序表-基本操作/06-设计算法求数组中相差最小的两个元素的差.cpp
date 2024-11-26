/*问题描述
.解题思路

排序求解，将数组中的元素进行排序，求解两个数之间的差值记录更新。

暴力求解 ，第一个元素和其他n-1个元素相比较，记录差值随时更新。第二个元素与其余n-2个算法比较，记录差值更新…显然最容易想到但是时间复杂度很高。

输入描述
第1行是一个正整数m，表示后面是m个整数。

输出描述
最小值是 ：

样例输入
4 1 3 5 6

样例输出
最小值是 ：1

提示说明
最后输出不用换行回车,冒号采中文输出。
*/

#include <iostream>
#include <cmath>
using namespace std;

// 将数组中的元素进行排序，求解两个数之间的差值记录更新。
void Sort(int arr[], int n)
{
    int num, temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                num = arr[i];
                arr[i] = arr[j];
                arr[j] = num;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            temp = arr[j] - arr[i];
            if (temp > arr[j] - arr[i])
            {
                temp = arr[j] - arr[i];
            }
        }
    }
    cout << "最小值是：" << temp;
}

int main()
{
    int m;
    cin >> m;
    int a[m + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    Sort(a, m);
}