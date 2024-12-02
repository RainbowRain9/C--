// Source : https://www.xujcoj.com/home/problem/detail/4387
// Date   : 2024-12-02

/**************************************************
 * 题目描述：
 * 小蓝有一个仓库用于存取货物。现在定义两种操作：
 * 1. 1 x date 表示存货，小蓝向仓库中存放x个保质期为date的货物
 * 2. 2 x 表示取货，小蓝按保质期从前到后的顺序从仓库中取出x件货物，若库存不足x则全部取出
 * 已知初始时仓库为空，在n次操作后，请按照保质期从前到后的顺序依次输出剩余库存。
 *
 * 示例 1：
 *   输入：
 *   5
 *   1 5 2023-10-24
 *   1 3 2022-10-24
 *   2 4
 *   1 2 2021-10-24
 *   1 1 2023-10-24
 *   输出：
 *   2021-10-24 2
 *   2023-10-24 5
 *   解释：
 *   第1次操作:存入5个保质期为2023-10-24的货物
 *   第2次操作:存入3个保质期为2022-10-24的货物
 *   第3次操作:取出4个货物(3个2022-10-24和1个2023-10-24)
 *   第4次操作:存入2个保质期为2021-10-24的货物
 *   第5次操作:存入1个保质期为2023-10-24的货物
 *
 * 提示：
 *   - 1 ≤ n ≤ 100000
 *   - 1 ≤ x ≤ 10^9
 *   - date为形如yyyy-mm-dd的合法日期字符串
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
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, long long> warehouse; // 使用map按日期排序存储货物

    while (n--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            long long x;
            string date;
            cin >> x >> date;
            warehouse[date] += x;
        }
        else if (op == 2)
        {
            long long x;
            cin >> x;
            for (auto it = warehouse.begin(); it != warehouse.end() && x > 0;)
            {
                if (it->second <= x)
                {
                    x -= it->second;
                    it = warehouse.erase(it);
                }
                else
                {
                    it->second -= x;
                    x = 0;
                }
            }
        }
    }

    // 输出剩余库存
    for (const auto &[date, count] : warehouse)
    {
        if (count > 0)
        {
            cout << date << " " << count << endl;
        }
    }

    return 0;
}