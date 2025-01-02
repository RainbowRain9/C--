// Source : https://xujcoj.com/home/contest/2013/problem/3
// Date   : 2024-12-05

/**************************************************
 * 题目描述：
 * 使用冒泡排序对输入的整数序列进行从小到大排序
 *
 * 示例 1：
 *   输入：
 *   1
 *   4 1 2 3 4
 *   输出：
 *   1 2 3 4
 *   解释：
 *   第一行输入1表示有1组测试数据
 *   第二行输入4表示该组数据有4个整数，后面是这4个整数：1 2 3 4
 *   输出这4个整数从小到大排序的结果
 *
 * 提示：
 *   - 输入的第一行是测试案例数量n
 *   - 接下来n行，每行第一个数字是该行整数的个数m
 *   - 每行输出整数之间用空格分隔，最后一个整数后没有空格
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

void bubbleSort(vector<int> &data)
{
    int n = data.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (data[j + 1] < data[j])
                swap(data[j], data[j + 1]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        vector<int> data;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            data.push_back(x);
        }
        bubbleSort(data);
        for (int i = 0; i < m; i++)
        {
            if (i > 0)
                cout << " ";
            cout << data[i];
        }
        cout << endl;
    }
    return 0;
}