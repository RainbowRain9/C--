/*
 * @Author: RainbowRain9
 * @Date: 2025-04-09 13:40:43
 * @LastEditTime: 2025-04-09 13:58:44
 * @FilePath: \C++\Algorithm\PTA\L1-050-倒数第N个字符串.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 给定一个由小写字母组成的字符串序列，每个字符串长度固定为L，
 * 从L个'a'开始，每次递增1（按字母顺序），直到L个'z'。
 * 要求输出这个序列的倒数第N个字符串。
 *
 * 示例 1：
 *   输入：3 27
 *   输出：zyz
 *   解释：3位字符串序列的倒数第27个是zyz
 *
 * 示例 2：
 *   输入：3 7417
 *   输出：pat
 *   解释：3位字符串序列的倒数第7417个是pat
 *
 * 提示：
 *   - 字符串长度L满足2 ≤ L ≤ 6
 *   - N不超过10^5
 *   - 可以看作26进制数计算问题
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
    int l, n;
    cin >> l >> n;
    long long total = 1;
    int temp_l = l;
    while (temp_l--) {
        total *= 26;
    }
    long long pos = total - n;
    string result;
    for (int i = 0; i < l; i++) {
        int digit = pos % 26;
        result.push_back('a' + digit);
        pos /= 26;
    }
    reverse(result.begin(), result.end());
    cout << result << endl;

    return 0;
}