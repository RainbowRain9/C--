/*
 * @Author: RainbowRain9
 * @Date: 2025-04-02 17:50:15
 * @LastEditTime: 2025-04-02 17:54:07
 * @FilePath: \C++\Algorithm\PTA\L1-011-A-B.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 本题要求计算A-B，其中A和B都是字符串。从字符串A中删除字符串B包含的所有字符，
 * 剩下的字符组成的就是字符串A-B。
 *
 * 示例 1：
 *   输入：
 *   I love GPLT!  It's a fun game!
 *   aeiou
 *   输出：
 *   I lv GPLT!  It's  fn gm!
 *   解释：
 *   从第一个字符串中删除了所有元音字母
 *
 * 示例 2：
 *   输入：
 *   Hello World!
 *   Hd!
 *   输出：
 *   ello Worl
 *   解释：
 *   从第一个字符串中删除了H、d和!字符
 *
 * 提示：
 *   - 两字符串长度都不超过10^4
 *   - 字符串由可见ASCII码和空白字符组成
 *   - 输入以换行符结束
 *   - 注意处理空格字符
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
    unordered_set<char> set;
    string a, b;
    getline(cin, a);
    getline(cin, b);

    for (auto c : b)
    {
        set.insert(c);
    }
    for (auto c : a)
    {
        if (!set.count(c))
        {
            cout << c;
        }
    }

    return 0;
}