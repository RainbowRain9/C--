// Source : https://xujcoj.com/home/contest/2013/problem/1
// Date   : 2024-12-05

/**************************************************
 * 题目描述：
 * 从控制台输入一个数组，首先输入一个整数n表示数组的长度，然后输入n个整数，代表数组的n个元素。
 * 接着使用插入排序法将数组按升序排列，并输出排序后的数组。
 *
 * 示例 1：
 *   输入：5 2 4 7 1 9
 *   输出：1 2 4 7 9
 *   解释：使用插入排序将数组[2,4,7,1,9]按升序排列得到[1,2,4,7,9]
 *
 * 提示：
 *   - 输入的第一个数字为数组长度n
 *   - 接下来输入n个整数作为数组元素
 *   - 输出时最后一个元素后面不要加空格
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

void InsertSort(vector<int>& data)
{
    int n = data.size();
    for (int i = 1; i < n; i++)
    {
        int temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > temp)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    InsertSort(data);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            cout << data[i];
        else
            cout << " " << data[i];
    }

    return 0;
}