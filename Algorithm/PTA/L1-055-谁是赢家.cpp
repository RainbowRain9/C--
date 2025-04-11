/*
 * @Author: RainbowRain9
 * @Date: 2025-04-09 16:59:46
 * @LastEditTime: 2025-04-09 17:11:21
 * @FilePath: \C++\Algorithm\PTA\L1-055-谁是赢家.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 某电视台的娱乐节目有个表演评审环节，每次安排两位艺人表演，他们的胜负由观众投票和3名评委投票两部分共同决定。
 * 规则为：
 * 1. 如果一位艺人的观众票数高，且得到至少1名评委的认可，该艺人就胜出
 * 2. 或艺人的观众票数低，但得到全部评委的认可，也可以胜出
 * 节目保证投票的观众人数为奇数，所以不存在平票的情况。
 *
 * 示例 1：
 *   输入：
 *   327 129
 *   1 0 1
 *   输出：
 *   The winner is a: 327 + 1
 *   解释：
 *   a的观众票数(327) > b的观众票数(129)，且a得到1名评委认可，满足规则1
 *
 * 示例 2：
 *   输入：
 *   100 200
 *   1 1 1
 *   输出：
 *   The winner is b: 200 + 3
 *   解释：
 *   b的观众票数(200) > a的观众票数(100)，且b得到全部评委认可，满足规则1
 *
 * 提示：
 *   - 观众票数Pa和Pb不超过1000
 *   - 评委投票用0表示投给a，1表示投给b
 *   - 保证观众票数不相等
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
    int a, b;
    cin >> a >> b;
    vector<int> pw(3);
    int cnta = 0, cntb = 0;
    for (int i = 0; i < 3; i++) {
        cin >> pw[i];
        if (pw[i] == 0) {
            cnta++;
        } else {
            cntb++;
        }
    }
    if (cnta == 3 || a > b && cnta >= 1) {
        cout << "The winner is a: " << a << " + " << cnta;
    } else {
        cout << "The winner is b: " << b << " + " << cntb;
    }

    return 0;
}