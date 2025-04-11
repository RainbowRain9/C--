/*
 * @Author: RainbowRain9
 * @Date: 2025-04-08 20:49:59
 * @LastEditTime: 2025-04-08 22:49:02
 * @FilePath: \C++\Algorithm\PTA\L1-046-整除光棍.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 *   给定一个不以5结尾的奇数x，找到最小的s和n，使得x乘以s等于一个由n个1组成的光棍数。
 *   输出s和n，用空格分隔。
 *
 * 示例 1：
 *   输入：31
 *   输出：3584229390681 15
 *   解释：31 * 3584229390681 = 111111111111111 (15个1)
 *
 * 示例 2：
 *   输入：3
 *   输出：37 3
 *   解释：3 * 37 = 111 (3个1)
 *
 * 提示：
 *   - x是一个不以5结尾的正奇数，且x < 1000
 *   - s可能是一个非常大的数，无法用常规整数类型存储
 *   - 需要找到最小的s和对应的n
 *   - 可以使用模拟除法的方法来逐步构建s
 **************************************************/

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    int cnt = 0;
    for (long long i = 1;; i = i * 10 + 1)
    {
        cnt++;
        if (i % n == 0)
        {
            cout << i / n << " " << cnt << endl;
            break;
        }
    }

    return 0;
}