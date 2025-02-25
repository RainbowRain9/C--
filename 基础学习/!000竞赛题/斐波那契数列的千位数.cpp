// Source : https://xujcoj.com/home/contest/2100/problem/3
// Date   : 2025-01-28

/**************************************************
 * 题目描述：
 * 输出斐波那契数列第m项的千位数字。
 *
 * 示例 1：
 *   输入：
 *   2
 *   5
 *   17
 *   输出：
 *   0
 *   1
 *   解释：
 *   第5项是5，千位数是0
 *   第17项是1597，千位数是1
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

long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 0;
    
    int a = 1, b = 1;
    for (int i = 3; i <= n; i++) {
        int temp = (a + b) % 10000;
        a = b;
        b = temp;
    }
    return b / 1000;
}

int main() {
    int n;
    scanf("%d", &n);
    
    while (n--) {
        int m;
        scanf("%d", &m);
        printf("%d\n", fibonacci(m));
    }
    
    return 0;
}