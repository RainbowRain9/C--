// Source :
// Date   :

/*********************************************************
题目:烤蛋糕
时间限制：1000ms  内存限制：65536kb
总通过人数: 1  总提交人数: 1

题目描述
涂涂准备烤n个蛋糕，但由于烤箱容量有限，每次只能同时烤k个。
烤箱每次启动固定工作s分钟，在这期间无法放置和取出蛋糕。
为了尽快把这些蛋糕烤好，涂涂打算再买一个一模一样的烤箱。
从下单新烤箱，到新烤箱被送至涂涂家并开始工作需要花费x分钟。
（在这期间并不会影响原烤箱正常连续工作）
你可以帮涂涂计算一下，若购买新烤箱可以比不购买更早把这些蛋糕烤完吗？

输入
第一行是一个正整数T表示测试案例的数量。(1≤T≤10000)
每组案例包含四个正整数n,s,k,x含义见描述。(1≤n,s,k,x≤10^9)

输出
针对每组案例，若购买新烤箱能提前烤完输出YES，否则输出NO。

样例输入
4
8 6 4 5
8 6 4 6
10 3 11 4
4 2 1 4

样例输出
YES
NO
NO
YES

思路:
1. 计算单个烤箱需要的总时间t1
2. 计算两个烤箱并行工作的总时间t2
3. 比较t1和t2的大小

*********************************************************/

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
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long n, s, k, x;
        cin >> n >> s >> k >> x;

        long long t1 = (n + k - 1) / k * s;

        long long a = (x / s) * k;
        long long b = n - a;
        if (b <= 0)
        {
            cout << "NO" << endl;
            continue;
        }

        long long t2 = x + ((b + 2 * k - 1) / (2 * k)) * s;

        if (t2 < t1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
