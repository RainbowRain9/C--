/*
 * @Author: RainbowRain9
 * @Date: 2025-04-08 09:16:58
 * @LastEditTime: 2025-04-08 09:17:03
 * @FilePath: \C++\Algorithm\PTA\L1-040-最佳情侣身高差.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 专家通过多组情侣研究数据发现，最佳的情侣身高差遵循着一个公式：
 * （女方的身高）×1.09 =（男方的身高）。如果符合，你俩的身高差不管是
 * 牵手、拥抱、接吻，都是最和谐的差度。请为任意一位用户计算他/她的
 * 情侣的最佳身高。
 *
 * 输入格式：
 * 第一行给出正整数N（≤10），为前来查询的用户数。随后N行，每行按照
 * "性别 身高"的格式给出前来查询的用户的性别和身高，其中"性别"为
 * "F"表示女性、"M"表示男性；"身高"为区间 [1.0, 3.0] 之间的实数。
 *
 * 输出格式：
 * 对每一个查询，在一行中为该用户计算出其情侣的最佳身高，保留小数点后2位。
 *
 * 示例 1：
 *   输入：
 *   2
 *   M 1.75
 *   F 1.8
 *   输出：
 *   1.61
 *   1.96
 *   解释：
 *   第一个查询是男性，最佳情侣身高 = 1.75 / 1.09 = 1.61
 *   第二个查询是女性，最佳情侣身高 = 1.8 * 1.09 = 1.96
 *
 * 提示：
 *   - 注意性别不同时计算公式不同
 *   - 输出需要保留两位小数
 *   - 输入的身高范围在[1.0, 3.0]之间
 **************************************************/

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
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
        char sex;
        double h, ans;
        cin >> sex >> h;
        if (sex == 'M') {
            ans = h / 1.09;
        } else {
            ans = h * 1.09;
        }
        cout << fixed << setprecision(2) << ans << endl;
    }

    return 0;
}