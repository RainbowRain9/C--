// Source : https://xujcoj.com/home/contest/2041/problem/2
// Date   : 2024-12-12

/**************************************************
 * 题目描述：
 * 给定一个长度为n的整数序列，请你输出第一趟选择排序的结果。
 * 选择排序的每一趟会选出序列中最小的数，将其与序列的第一个数交换。
 *
 * 示例 1：
 *   输入：5
 *        3 1 2 5 4
 *   输出：1 3 2 5 4
 *   解释：第一趟选择排序会找出最小值1，将其与第一个数3交换位置
 *
 * 示例 2：
 *   输入：4
 *        2 1 4 3
 *   输出：1 2 4 3
 *   解释：第一趟选择排序会找出最小值1，将其与第一个数2交换位置
 *
 * 提示：
 *   - 1 <= n <= 100
 *   - 序列中的数字各不相同且都是正整数
 *   - 序列中的数字不超过1000
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
    int i = 0;

    int index = i;
    for (int j = i + 1; j < n; j++)
    {
        if (data[index] > data[j])
        {
            index = j;
        }
    }
    if (index != i)
    {
        swap(data[index], data[i]);
    }

    cout << data[0];
    for (int i = 1; i < n; i++)
    {
        cout << " " << data[i];
    }

    return 0;
}