// Source : https://www.xujcoj.com/home/problem/detail/3422
// Date   : 2024-12-04

/**************************************************
 * 题目描述：
 * 小蓝很喜欢喝可乐，这天有个活动，2个空瓶可以兑换一瓶可乐，4个瓶盖也可以兑换一瓶可乐。
 * 小蓝直接买了10瓶可乐，他想知道最终总共能喝多少瓶。
 * 老板允许小蓝临时赊账：假设小蓝目前只有1个空瓶，他可以先向老板要一瓶可乐，喝完之后再把这2个空瓶换给老板，
 * 相当于抵消了刚才的可乐钱（瓶盖同理）。
 * 无论小蓝欠了老板多少瓶可乐，他最后只要能将所有空瓶和瓶盖按照数目兑换后悉数归还就可以。
 *
 * 示例 1：
 *   输入：无
 *   输出：23
 *   解释：
 *   1. 初始购买10瓶可乐，得到10个空瓶和10个瓶盖
 *   2. 10个空瓶可以兑换5瓶可乐，得到5个空瓶和5个瓶盖
 *   3. 8个瓶盖可以兑换2瓶可乐，得到2个空瓶和2个瓶盖
 *   4. 7个空瓶可以兑换3瓶可乐，得到3个空瓶和3个瓶盖
 *   5. 4个瓶盖可以兑换1瓶可乐，得到1个空瓶和1个瓶盖
 *   6. 4个空瓶可以兑换2瓶可乐，得到2个空瓶和2个瓶盖
 *   最终总共可以喝到23瓶可乐
 *
 * 提示：
 *   - 这是一道结果填空的题，只需要算出结果后提交即可
 *   - 注意可以临时赊账，只要最后能还清就行
 *   - 需要考虑空瓶和瓶盖分别可以兑换的情况
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
    int nums = 10;    // 初始购买的可乐数
    int bottles = 10; // 空瓶数
    int caps = 10;    // 瓶盖数

    while (bottles >= 2 || caps >= 4 || bottles == 1 || caps == 3)
    {
        // 处理赊账情况
        if (bottles == 1) {
            bottles++; // 赊1瓶
        }
        if (caps == 3) {
            caps++; // 赊1瓶
        }

        // 原有的兑换逻辑保持不变
        int newFromBottles = bottles / 2;
        bottles = bottles % 2;
        
        bottles += newFromBottles;
        caps += newFromBottles;
        nums += newFromBottles;

        int newFromCaps = caps / 4;
        caps = caps % 4;

        caps += newFromCaps;
        bottles += newFromCaps;
        nums += newFromCaps;
    }

    cout << nums << endl;
    return 0;
}