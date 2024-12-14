// Source : https://xujcoj.com/home/contest/2041/problem/1
// Date   : 2024-12-12

/**************************************************
 * 题目描述：
 * 给定一个长度为n的整数序列,请使用选择排序对其进行升序排序。
 * 选择排序的基本思想是:每一趟在待排序元素中选取关键字最小的元素加入有序子序列。
 * 
 * 示例 1：
 *   输入：5
 *        5 2 3 1 4
 *   输出：1 2 3 4 5
 *   解释：通过选择排序,将序列按升序排列
 * 
 * 示例 2：
 *   输入：3
 *        3 2 1
 *   输出：1 2 3
 *   解释：通过选择排序,将序列按升序排列
 * 
 * 提示：
 *   - 1 <= n <= 100
 *   - 序列中的元素取值范围为[-1000, 1000]
 *   - 序列中的元素各不相同
 **************************************************/

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int data[n];
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (data[j] < data[index])
            {
                index = j;
            }
        }
        if (index != i)
        {
            swap(data[i], data[index]);
        }
    }
    cout << data[0];
    for (int i = 1; i < n; i++)
    {
        cout << " " << data[i];
    }
    

    return 0;
}