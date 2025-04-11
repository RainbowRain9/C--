/*
 * @Author: RainbowRain9
 * @Date: 2025-04-09 17:39:07
 * @LastEditTime: 2025-04-09 19:34:45
 * @FilePath: \C++\Algorithm\PTA\L1-054-福到了.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * "福"字倒着贴，寓意"福到"。本题要求编写程序，把各种汉字倒过来输出。
 * 每个汉字由 N × N 的网格组成，网格中的元素为字符 @ 或空格。
 * 倒过来的汉字所用的字符由裁判指定。
 *
 * 示例 1：
 *   输入：
 *   $ 9
 *    @  @@@@@
 *   @@@  @@@
 *    @   @ @
 *   @@@  @@@
 *   @@@ @@@@@
 *   @@@ @ @ @
 *   @@@ @@@@@
 *    @  @ @ @
 *    @  @@@@@
 *   输出：
 *   $$$$$  $
 *   $ $ $  $
 *   $$$$$ $$$
 *   $ $ $ $$$
 *   $$$$$ $$$
 *    $$$  $$$
 *    $ $   $
 *    $$$  $$$
 *   $$$$$  $
 *   解释：将输入的@字符替换为$，并将图形旋转180度
 *
 * 示例 2：
 *   输入：
 *   & 3
 *   @@@
 *    @
 *   @@@
 *   输出：
 *   bu yong dao le
 *   &&&
 *    &
 *   &&&
 *   解释：因为图形旋转180度后与原图相同，所以先输出提示信息
 *
 * 提示：
 *   - 网格规模 N 不超过100
 *   - 需要判断图形是否对称
 *   - 注意处理输入中的空格
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
    char m;
    cin >> m >> n;
    cin.ignore();
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        getline(cin, a[i]);
    }
    vector<string> b = a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i][j] == '@') {
                b[i][j] = m;
            }
        }
    }
    vector<string> c(n, string(n, ' '));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[n - i - 1][n - j - 1] = b[i][j];
        }
    }

    bool f = (c == b);

    if (f) {
        cout << "by youg dao le" << endl;
    }
    
    for (string i : c) {
        cout << i << endl;
    }
    
    return 0;
}