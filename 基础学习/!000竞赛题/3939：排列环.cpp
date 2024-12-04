// Source : https://www.xujcoj.com/home/problem/detail/3939
// Date   : 2024-12-03

/**************************************************
 * 题目描述：
 * 给出一个 1 ~ n 的排列（每个数字出现且仅出现一次的序列）然后把它首尾相连形成一个环。
 * 对于每个数字，请你输出它的前一个数字和后一个数字。
 *
 * 示例 1：
 *   输入：
 *   5
 *   3 5 4 2 1
 *   输出：
 *   2 3
 *   4 1
 *   1 5
 *   5 2
 *   3 4
 *   解释：
 *   第一行输出【2 3】意为：1 的前一个数字是 2，后一个数字是首尾相连后的 3。
 *   第二行输出【4 1】意为：2 的前一个数字是 4，后一个数字 1。
 *
 * 提示：
 *   - 对于 50% 的用例，n 不大于 10
 *   - 对于 100% 的用例，n 不大于 200000
 *   - n > 2
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
    int arr[n];
    int pos[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int j = pos[i];
        cout << arr[(j - 1 + n) % n] << " " << arr[(j + 1) % n] << endl;
    }
}