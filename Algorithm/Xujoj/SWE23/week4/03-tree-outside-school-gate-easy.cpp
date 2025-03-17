/*
 * @Author: RainbowRain9
 * @Date: 2025-03-17 15:55:56
 * @LastEditTime: 2025-03-17 15:56:11
 * @FilePath: \C++\Algorithm\Xujoj\SWE23\week4\03-tree-outside-school-gate-easy.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 嘉庚学院大门外长度为L的马路上有一排树，每两棵相邻的树之间的间隔都是1米。数轴上的每个整数点（0，1，2，……，L）都种有一棵树。现在有一些区域要用来建地铁，这些区域用它们在数轴上的起始点和终止点表示。需要把这些区域中的树（包括区域端点处的两棵树）移走。计算将这些树都移走后，马路上还有多少棵树。
 *
 * 示例 1：
 *   输入：
 *   5 2
 *   0 2
 *   1 3
 *   输出：
 *   2
 *   解释：
 *   把0~2、1~3上的树移开后还剩下4和5这两棵树
 *
 * 提示：
 *   - 0 <= L <= 10000
 *   - 1 <= M <= 100
 *   - 0 <= a < b <= L
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
    int l, m;
    cin >> l >> m;
    vector<bool> trees(l + 1, true);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        for (int i = a; i <= b; i++)
        {
            trees[i] = false;
        }
    }
    int count = 0;
    for (int i = 0; i < l + 1; i++)
    {
        if (trees[i])
        {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}