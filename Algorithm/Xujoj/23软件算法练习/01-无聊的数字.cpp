// Source : https://xujcoj.com/home/contest/2127/problem/1
// Date   : 2025-03-03

/**************************************************
 * 题目描述：
 * 小明上"算法设计与分析"的课程很无聊，就在白纸上写下一串连续的整数：
 * 1、2、3、4、5、6、7、8、9、10...突然，他想到一个小游戏，可以统计这些数字中
 * 0到9的出现次数，并且考虑用算法来实现。
 * 
 * 输入描述：
 * 所写出的最大整数n，n<=10000
 * 
 * 输出描述：
 * 每行依次输出0到9中每个数字的出现次数，以换行符结束
 * 
 * 样例输入：
 * 10
 * 
 * 样例输出：
 * 1
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
    int n;
    cin >> n;
    vector<int> a(10, 0);

    for (int i = 1; i <= n; i++) {
        string num = to_string(i);
        for (char c : num) {
            a[c - '0']++;
        }
    }
    for (int j = 0; j < 10; j++)
    {
        cout << a[j] << endl;
    }

    return 0;
}