/*
 * @Author: RainbowRain9
 * @Date: 2025-04-08 09:24:58
 * @LastEditTime: 2025-04-08 09:28:17
 * @FilePath: \C++\Algorithm\PTA\L1-042-日期格式化.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 将美国格式的日期（月-日-年）转换为中国格式的日期（年-月-日）
 *
 * 示例 1：
 *   输入：03-15-2017
 *   输出：2017-03-15
 *   解释：将月份和年份的位置互换，并保持日期不变
 *
 * 示例 2：
 *   输入：12-31-1999
 *   输出：1999-12-31
 *   解释：将月份和年份的位置互换，并保持日期不变
 *
 * 提示：
 *   - 输入格式为"mm-dd-yyyy"
 *   - 输出格式为"yyyy-mm-dd"
 *   - 日期保证是1900年元旦至今合法的日期
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
    int m, d, y;
    char a, b;
    cin >> m >> a >> d >> b >> y;
    printf("%04d-%02d-%02d", y, m, d);

    return 0;
}