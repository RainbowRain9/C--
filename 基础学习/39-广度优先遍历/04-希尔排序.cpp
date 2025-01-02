// Source : https://xujcoj.com/home/contest/2013/problem/4
// Date   : 2024-12-05

/**************************************************
 * 题目描述：
 * 从控制台输入一个数组，首先输入一个整数n表示数组的长度，然后输入n个整数，代表数组的n个元素。
 * 接着使用希尔排序法对数组进行排序,并输出排序后的数组。升序排序。
 *
 * 示例 1：
 *   输入：6 2 4 7 1 9 5
 *   输出：1 2 4 5 7 9
 *   解释：使用希尔排序对输入数组[2,4,7,1,9,5]进行升序排序,得到[1,2,4,5,7,9]
 *
 * 提示：
 *   - 输入的第一个数字为数组长度n
 *   - 接下来输入n个整数作为数组元素
 *   - 使用希尔排序算法对数组进行升序排序
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

// void shellSort(vector<int> &data)
// {
//     int n = data.size();
//     for (int gap = n / 2; gap > 0; gap /= 2)
//     {
//         for (int i = gap; i < n; i++)
//         {
//             int temp = data[i];
//             int j;
//             for (j = i; j >= gap && data[j - gap] > temp; j -= gap)
//             {
//                 data[j] = data[j - gap];
//             }
//             data[j] = temp;
//         }
//     }
// }

void shellSort(vector<int> &data)
{
    int n = data.size();
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = data[i];
            int j = i - gap;
            while (j >= 0 && data[j] > temp)
            {
                data[j + gap] = data[j];
                j -= gap;
            }
            data[j + gap] = temp;
        }
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
    shellSort(data);
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << " ";
        cout << data[i];
    }

    return 0;
}