// Source : https://www.luogu.com.cn/problem/P1020
// Date   : 2025-01-23

/**************************************************
 * 题目描述：
 * 某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：
 * 虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。
 * 某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。
 * 输入导弹依次飞来的高度，计算这套系统最多能拦截多少导弹，如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。
 * 
 * 示例 1：
 *   输入：389 207 155 300 299 170 158 65
 *   输出：6
 *        2
 *   解释：一套系统最多可以拦截6个导弹，需要2套系统才能拦截所有导弹
 * 
 * 提示：
 *   - 对于前50%数据，导弹个数不超过10^4个，可使用O(n^2)做法
 *   - 对于后50%数据，导弹个数不超过10^5个，需要使用O(nlogn)做法
 *   - 导弹高度为正整数且不超过5×10^4
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
    int n;
    cin >> n;
    while(n--)
    {
        
    }

    return 0;
}