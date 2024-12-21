// Source : https://xujcoj.com/home/contest/2070/problem/6
// Date   : 2024-12-21

/**************************************************
 * 题目描述：
 * 计算a到b（a<=b）之间所有的整数相乘的结果（即a*(a+1)*(a+2)*...*b），
 * 其尾数中有几个连续的0。例如102000的尾数有3个0，100004的尾数有0个0，
 * 0的尾数有1个0。
 *
 * 示例 1：
 *   输入：
 *   2
 *   5 6
 *   100 110
 *   输出：
 *   1
 *   4
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
        long long a, b;
        cin >> a >> b;
        long long cnt2 = 0, cnt5 = 0;
        for (long long i = a; i <= b; i++)
        {
            long long num = i;
            while (num % 2 == 0)
            {
                cnt2++;
                num /= 2;
            }
            num = i;
            while (num % 5 == 0)
            {
                cnt5++;
                num /= 5;
            }
        }
        cout << min(cnt2, cnt5) << endl;
    }
    return 0;
}