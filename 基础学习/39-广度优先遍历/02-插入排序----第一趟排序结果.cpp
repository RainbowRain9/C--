// Source : https://xujcoj.com/home/contest/2013/problem/2
// Date   : 2024-12-05

/**************************************************
 * 题目描述：
 * 从控制台输入一个数组，首先输入一个整数n表示数组的长度，然后输入n个整数，代表数组的n个元素。
 * 接着使用插入排序法对数组进行第一趟排序（即处理第一个元素和第二个元素，插入第二个元素到正确的位置），
 * 并输出这一趟排序后的数组。升序排序。
 *
 * 示例 1：
 *   输入：5 8 3 2 9 4
 *   输出：3 8 2 9 4
 *   解释：第一趟排序只处理前两个元素8和3,将3插入到8前面,其他元素保持不变
 *
 * 提示：
 *   - 输入第一个整数n表示数组长度
 *   - 接着输入n个整数表示数组元素
 *   - 输出最后一个元素后没有空格
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
    vector<int> data(n);
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    int i, j, temp;
    for (int i = 0; i <= 1; i++)
    {
        j = i - 1;
        temp = data[i];
        while (j >= 0 && temp < data[j])
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            cout << data[i];
        else
            cout << " " << data[i];
    }

    return 0;
}