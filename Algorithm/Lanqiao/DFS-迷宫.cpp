/**************************************************
 * 题目描述：
 * X星球的一处迷宫游乐场建在某个小山坡上，由10x10相互连通的小房间组成。
 * 房间地板上写着字母表示移动方向：
 * L - 左边房间
 * R - 右边房间
 * U - 上坡方向房间
 * D - 下坡方向房间
 *
 * 100名玩家被放入各个房间，必须按地板字母移动。
 * 求最后能走出迷宫的玩家数量。
 *
 * 示例 1：
 *   输入：
 *   UDDLUULRUL
 *   UURLLLRRRU
 *   RRUURLDLRD
 *   RUDDDDUUUU
 *   URUDLLRRUU
 *   DURLRLDLRL
 *   ULLURLLRDU
 *   RDLULLRDDD
 *   UUDDUDUDLL
 *   ULRDLUURRR
 *   输出：
 *   能走出迷宫的玩家数量
 *
 * 提示：
 *   - 使用DFS/BFS遍历每个格子的路径
 *   - 记录已访问过的格子避免重复
 *   - 如果能走到边界则说明可以走出迷宫
 **************************************************/

#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int cnt = 0;
// 修改1：使用 vector<string> 来存储迷宫地图，方便按行读取
vector<string> grid(N);
vector<vector<bool>> visited(N, vector<bool>(N));

void dfs(int x, int y)
{
    // 如果越界，说明找到一条可以走出迷宫的路径
    if (x < 0 || x >= N || y < 0 || y >= N) {
        cnt++;
        return;
    }

    // 如果在本次 DFS 中已访问过该格子，说明进入循环，返回
    // (防止因循环路径导致的无限递归)
    if (visited[x][y]) {
        return;
    }

    // 标记当前格子已访问
    visited[x][y] = true;

    // 根据当前格子的指示方向移动到下一个格子
    int next_x = x, next_y = y;
    // 修改3：访问字符的方式不变，仍然是 grid[x][y]
    switch (grid[x][y]) {
    case 'U':
        next_x--;
        break;
    case 'D':
        next_x++;
        break;
    case 'L':
        next_y--;
        break;
    case 'R':
        next_y++;
        break;
    }
    dfs(next_x, next_y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 修改2：按行读入字符串到 vector<string> grid 中
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    // 遍历每个起点
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 重置现有的 visited 数组
            // 使用 std::fill 清空 visited[row]
            for (auto& row : visited) {
                fill(row.begin(), row.end(), false);
            }
            dfs(i, j);
        }
    }

    cout << cnt;

    return 0;
}
// End of Selection