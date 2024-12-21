// Source : https://xujcoj.com/home/contest/2070/problem/2
// Date   : 2024-12-21

/**************************************************
 * 题目描述：
 * 计算m个整数之和。如果有数字重复，则只加一次。
 *
 * 示例 1：
 *   输入：
 *   2
 *   5
 *   1 2 3 4 5
 *   6
 *   2 2 5 5 4 5
 *   输出：
 *   15
 *   11
 *   解释：
 *   第一组案例中,1+2+3+4+5=15
 *   第二组案例中,2只加一次,5只加一次,2+5+4=11
 *
 * 提示：
 *   - 这是一道多组案例的题目
 *   - n表示案例数量,n<=100
 *   - m表示每组案例的整数数量,m<=1000
 *   - 所有整数的绝对值均不大于10亿
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
    while (n--)
    {
        int m;
        cin >> m;
        unordered_set<int> nums;
        long long num;
        long long sum = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> num;
            if (nums.count(num) == 0)
            {
                nums.insert(num);
                sum += num;
            }
        }
        cout << sum << endl;
    }

    return 0;
}