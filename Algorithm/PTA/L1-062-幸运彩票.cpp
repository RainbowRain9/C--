/*
 * @Author: RainbowRain9
 * @Date: 2025-04-09 22:01:40
 * @LastEditTime: 2025-04-09 22:04:07
 * @FilePath: \C++\Algorithm\PTA\L1-062-幸运彩票.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 判断彩票号码是否幸运。彩票号码为6位数字，如果前3位数字之和等于后3位数字之和，
 * 则称这张彩票是幸运的。
 *
 * 示例 1：
 *   输入：233008
 *   输出：You are lucky!
 *   解释：2+3+3 = 8, 0+0+8 = 8，前后和相等
 *
 * 示例 2：
 *   输入：123456
 *   输出：Wish you good luck.
 *   解释：1+2+3 = 6, 4+5+6 = 15，前后和不相等
 *
 * 提示：
 *   - 输入第一行是测试用例数量N (≤100)
 *   - 每个测试用例是一个6位数字
 *   - 需要分别计算前3位和后3位的数字之和
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
    int n;
    cin >> n;
    while (n--) {
        string m;
        cin >> m;
        int a = m[0] - '0' + m[1] - '0' + m[2] - '0';
        int b = m[3] - '0' + m[4] - '0' + m[5] - '0';
        if (a == b)
            cout << "You are lucky!" << endl;
        else
            cout << "Wish you good luck." << endl;
    }

    return 0;
}