// Source : https://xujcoj.com/home/contest/2100/problem/2
// Date   : 2025-01-28

/**************************************************
 * 题目描述：
 * 定义一个非负整数的中间数字:
 * - 若该整数由奇数位数字组成，则表示处于正中间的那位数字，例如13524的中间数字是5
 * - 若该整数由偶数位数字组成，则表示处于正中间的两位数字，例如135246的中间数字是52
 * 现在需要求某个整数的平方的中间数字。
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
        long long a;
        cin >> a;
        long long b = a * a;
        string c = to_string(b);
        int len = c.length();
        if (len % 2 == 0)
        {
            cout << c[len / 2 - 1] << c[len / 2] << endl;
        }
        else
        {
            cout << c[len / 2] << endl;
        }
    }

    return 0;
}