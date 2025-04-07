/*
 * @Author: RainbowRain9
 * @Date: 2025-04-02 17:44:55
 * @LastEditTime: 2025-04-02 17:49:22
 * @FilePath: \C++\Algorithm\PTA\L1-010-比较大小.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 本题要求将输入的任意3个整数从小到大输出。
 *
 * 输入格式:
 * 输入在一行中给出3个整数，其间以空格分隔。
 *
 * 输出格式:
 * 在一行中将3个整数从小到大输出，其间以“->”相连。
 *
 * 示例 1：
 *   输入：4 2 8
 *   输出：2->4->8
 *   解释：将输入的数字按从小到大排序并用"->"连接
 *
 * 示例 2：
 *   输入：9 3 6
 *   输出：3->6->9
 *   解释：将输入的数字按从小到大排序并用"->"连接
 *
 * 提示：
 *   - 输入保证是3个整数
 *   - 输出格式必须严格使用"->"连接
 *   - 数字之间没有空格
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
    vector<int> a(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
            cout << a[i];
        else
        {
            cout << "->" << a[i];
        }
    }

    return 0;
}