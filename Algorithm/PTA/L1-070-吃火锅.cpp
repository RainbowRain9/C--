
/**************************************************
 * 题目描述：
 * 检查朋友发来的信息中是否包含"chi1 huo3 guo1"关键词。
 *
 * 示例 1：
 *   输入：
 *   Hello!
 *   are you there?
 *   wantta chi1 huo3 guo1?
 *   that's so li hai le
 *   our story begins from chi1 huo3 guo1 le
 *   .
 *   输出：
 *   5
 *   3 2
 *   解释：
 *   总共5条信息，第3条和第5条包含关键词，所以输出"3 2"
 *
 * 示例 2：
 *   输入：
 *   Hello!
 *   are you there?
 *   wantta qi huo3 guo1 chi1huo3guo1?
 *   that's so li hai le
 *   our story begins from ci1 huo4 guo2 le
 *   .
 *   输出：
 *   5
 *   -_-#
 *   解释：
 *   总共5条信息，没有包含完整的"chi1 huo3 guo1"关键词
 *
 * 提示：
 *   - 每行信息不超过80个字符
 *   - 信息仅包含字母、数字、空格和可见的半角标点符号
 *   - 输入以单个点号"."结束
 *   - 所有输出数字不超过100
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
    string s;
    int cnt1 = 0, cnt2 = 0, first;
    bool i = true;
    while (getline(cin, s)) {
        if (s == ".") {
            break;
        }
        cnt1++;
        if (s.find("chi1 huo3 guo1") != string::npos) {
            if (i) {
                first = cnt1;
                i = false;
            }
            cnt2++;
        }
    }
    cout << cnt1 << endl;
    if (cnt2 > 0) {
        cout << first << " " << cnt2;
    } else {
        cout << "-_-#";
    }
    return 0;
}