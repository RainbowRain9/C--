// Source : https://xujcoj.com/home/contest/2127/problem/1
// Date   : 2025-03-03

/**************************************************
 * 题目描述：
 * 小明上"算法设计与分析"的课程很无聊，就在白纸上写下一串连续的整数：
 * 1、2、3、4、5、6、7、8、9、10...突然，他想到一个小游戏，可以统计这些数字中
 * 1到9的出现次数，并且考虑用算法来实现。
 * 
 * 输入描述：
 * 所写出的最大整数n，n<=10^9且n均为10的整数次幂
 * 
 * 输出描述：
 * 每行依次输出1到9中每个数字的出现次数，以换行符结束
 * 
 * 样例输入：
 * 10
 * 
 * 样例输出：
 * 2
 * 1
 * 1
 * 1
 * 1
 * 1
 * 1
 * 1
 * 1
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
    long long n;
    cin >> n;
    vector<long long> cnt(10, 0);
    
    long long pos = 1;
    while (pos <= n) {
        for (int d = 1; d <= 9; d++) {
            long long full_sets = n / (pos * 10);
            cnt[d] += full_sets * pos;
            
            long long remainder = n % (pos * 10);
            if (remainder >= d * pos) {
                cnt[d] += min(pos, remainder - d * pos + 1);
            }
        }
        pos *= 10;
    }

    for (int i = 1; i <= 9; i++) {
        cout << cnt[i] << endl;
    }

    return 0;
}