// Source : https://www.xujcoj.com/home/problem/detail/4348
// Date   : 2024-12-01

/**************************************************
 * 题目描述：
 * 在一个8×8的国际象棋棋盘中挖几个洞，这些洞上无法放棋子。
 * 现在给你8个车，请把它们全部放到棋盘上，使得任意两个车都不会互相攻击。
 * 车本来可以攻击和它同行同列的棋子，但本题中，车在攻击的时候如果踩到一个洞，
 * 那么便会自取灭亡。故，车的攻击范围止于洞。
 *
 * 以下是挖洞后的棋盘，1表示可以放置车，0表示洞，请计算有多少种放置方案：
 * 0 0 0 0 1 1 1 0
 * 0 0 0 0 0 0 1 0
 * 1 0 1 0 1 1 1 0
 * 0 1 1 1 0 0 0 1
 * 1 1 0 0 0 0 1 1
 * 0 1 0 0 1 1 1 1
 * 1 1 0 1 0 1 0 1
 * 0 1 0 1 1 0 0 0
 *
 * 输入描述：
 * 本题没有输入。
 *
 * 输出描述：
 * 这是一道填空题，方法不限，你只需要输出答案即可。
 *
 * 示例：
 * 输入：无
 * 输出：答案数字
 *
 * 相关：
 * 2024蓝桥杯校内选拔赛
 * 题单#13（递归&DFS&回溯）
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

// 棋盘布局,1表示可放置,0表示洞
const int board[8][8] = {
    {0, 0, 0, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {1, 0, 1, 0, 1, 1, 1, 0},
    {0, 1, 1, 1, 0, 0, 0, 1},
    {1, 1, 0, 0, 0, 0, 1, 1},
    {0, 1, 0, 0, 1, 1, 1, 1},
    {1, 1, 0, 1, 0, 1, 0, 1},
    {0, 1, 0, 1, 1, 0, 0, 0}};

int pos[8];  // 记录每行车的列位置
int ans = 0; // 记录答案

// 检查(row,col)位置是否可以放置车
bool check(int row, int col)
{
    if (!board[row][col])
        return false; // 是洞不能放

    // 检查之前的行
    for (int i = 0; i < row; i++)
    {
        // 同列检查,需考虑中间是否有洞
        if (pos[i] == col)
        {
            bool blocked = false;
            for (int r = i + 1; r < row; r++)
            {
                if (!board[r][col])
                {
                    blocked = true;
                    break;
                }
            }
            if (!blocked)
                return false;
        }
    }
    return true;
}

// DFS回溯
void dfs(int row, int cnt)
{
    if (cnt == 8)
    { // 放满8个车
        ans++;
        return;
    }
    if (row >= 8)
        return;

    // 尝试在当前行的每一列放置
    for (int col = 0; col < 8; col++)
    {
        if (check(row, col))
        {
            pos[row] = col;
            dfs(row + 1, cnt + 1);
        }
    }
}

int main()
{
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}