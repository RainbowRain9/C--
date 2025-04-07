/*
 * @Author: RainbowRain9
 * @Date: 2025-04-04 20:31:17
 * @LastEditTime: 2025-04-06 22:07:22
 * @FilePath: \C++\Algorithm\PTA\L1-024-后天.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 *
 *
 * 示例 1：
 *   输入：
 *   输出：
 *   解释：
 *
 * 示例 2：
 *   输入：
 *   输出：
 *   解释：
 *
 * 提示：
 *   -
 *   -
 *   -
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

int main() {
  int n;
  cin >> n;
  int result = (n + 2) % 7;

  if (result == 0) {
    result = 7;
  }
  cout << result;

  return 0;
}