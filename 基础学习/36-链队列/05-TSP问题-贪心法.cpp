/*
问题描述：
【问题】
TSP问题（Traveling Salesman Problem）是指旅行家要旅行 n 个城市，要求各个城市经历且仅经历一次然后回到出发城市，并要求所走的路程最短。

【想法】
TSP问题的贪心策略可以采用最近邻点策略：从任意城市出发，每次在没有到过的城市中选择最近的一个，直至经过了所有城市，最后回到出发城市。

【算法】
设 cij 表示顶点 i 到顶点 j 的代价（1 ≤ i, j ≤ n）
集合 V 存储图的顶点
集合 P 存储经过的边
出发顶点是 w

算法步骤：
1. 初始化：P = ∅, U = {w}, v = w
2. 当|U| < n时，重复以下步骤：
   - 在V-U中找到距离v最近的顶点u
   - 将边(v,u)加入P
   - 将u加入U
   - v = u
3. 将边(v,w)加入P，完成回路
*/

#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;

int TSP(int arc[][100], int n, int start)
{
    bool *visited = new bool[n]();
    int TSPLength = 0;
    int u = start;

    visited[u] = true;
    int count = n - 1;

    while (count > 0)
    {
        int minDist = INF;
        int nextVertex = -1;

        for (int v = 0; v < n; v++)
        {#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;

int TSP(int arc[][100], int n, int start)
{
    bool *visited = new bool[n]();
    int TSPLength = 0;
    int u = start;

    visited[u] = true;
    int count = n - 1;

    while (count > 0)
    {
        int minDist = INF;
        int nextVertex = -1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && arc[u][v] < minDist)
            {
                minDist = arc[u][v];
                nextVertex = v;
            }
        }

        TSPLength += minDist;
        u = nextVertex;
        visited[u] = true;
        count--;
    }

    TSPLength += arc[u][start];

    delete[] visited;
    return TSPLength;
}

int main()
{
    const int MAX = 1000;
    int arc[100][100] = {
        {MAX, 3, 3, 2, 6},
        {3, MAX, 7, 3, 2},
        {3, 7, MAX, 2, 5},
        {2, 3, 2, MAX, 3},
        {6, 2, 5, 3, MAX}};
    int n = 5, w;
    cin >> w;
    cout << TSP(arc, n, w) << endl;

    return 0;
}
            if (!visited[v] && arc[u][v] < minDist)
            {
                minDist = arc[u][v];
                nextVertex = v;
            }
        }

        TSPLength += minDist;
        u = nextVertex;
        visited[u] = true;
        count--;
    }

    TSPLength += arc[u][start];

    delete[] visited;
    return TSPLength;
}

int main()
{
    const int MAX = 1000;
    int arc[100][100] = {
        {MAX, 3, 3, 2, 6},
        {3, MAX, 7, 3, 2},
        {3, 7, MAX, 2, 5},
        {2, 3, 2, MAX, 3},
        {6, 2, 5, 3, MAX}};
    int n = 5, w;
    cin >> w;
    cout << TSP(arc, n, w) << endl;

    return 0;
}