// Source : https://xujcoj.com/home/contest/2041/problem/4
// Date   : 2024-12-12

/**************************************************
 * 题目描述：
 * 给定一个长度为n的整数序列,请你使用快速排序对这个序列进行排序。
 *
 * 示例 1：
 *   输入：5
 *        3 1 2 4 5
 *   输出：1 2 3 4 5
 *   解释：对序列[3,1,2,4,5]进行快速排序,得到有序序列[1,2,3,4,5]
 *
 * 示例 2：
 *   输入：4
 *        4 3 2 1
 *   输出：1 2 3 4
 *   解释：对序列[4,3,2,1]进行快速排序,得到有序序列[1,2,3,4]
 *
 * 提示：
 *   - 1 <= n <= 100000
 *   - 序列中的数字均为不超过10^9的整数
 *   - 序列中可能包含重复数字
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
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());

        cout << nums[0];
        for (int i = 1; i < n; i++)
        {
            cout << " " << nums[i];
        }
        cout << endl;
    }
    return 0;
}