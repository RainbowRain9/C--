// Source : https://xujcoj.com/home/contest/2013/problem/5
// Date   : 2024-12-05

/**************************************************
 * 题目描述：
 * 给定图的顶点信息和边的信息，构建无向图，并对该图进行广度优先遍历。
 *
 * 示例 1：
 *   输入：
 *   5 A B C D E
 *   6
 *   0 1
 *   0 2
 *   1 3
 *   2 3
 *   2 4
 *   3 4
 *   输出：ABCDE
 *   解释：
 *   - 第一行输入5表示有5个顶点，后面是5个字符A B C D E
 *   - 第二行输入6表示有6条边
 *   - 接下来6行每行输入两个数字表示一条边的两个顶点的下标
 *   - 从顶点A(下标0)开始进行广度优先遍历,输出遍历序列ABCDE
 *
 * 提示：
 *   - 输入的第一个数字N表示顶点个数,后面跟N个字符表示顶点
 *   - 第二行输入一个数字M表示边数
 *   - 接下来M行每行输入两个数字表示一条边的两个顶点的下标
 *   - 需要使用队列来实现广度优先遍历
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

const int MaxSize = 10; // 图中最多顶点个数

int visited[MaxSize] = {0}; // 全局数组变量visited初始化

class MGraph
{
public:
    MGraph(char a[], int n, int e); // 构造函数，建立具有n个顶点e条边的图

    ~MGraph() {}; // 析构函数

    void DFTraverse(int v); // 深度优先遍历图

    void BFTraverse(int v); // 广度优先遍历图

private:
    char vertex[MaxSize]; // 存放图中顶点的数组

    int edge[MaxSize][MaxSize]; // 存放图中边的数组

    int vertexNum, edgeNum; // 图的顶点数和边数
};

MGraph::MGraph(char a[], int n, int e)
{
    int i, j, k;

    vertexNum = n;
    edgeNum = e;

    for (i = 0; i < vertexNum; i++) // 存储顶点
        vertex[i] = a[i];

    for (i = 0; i < vertexNum; i++) // 初始化邻接矩阵
        for (j = 0; j < vertexNum; j++)
            edge[i][j] = 0;

    for (k = 0; k < edgeNum; k++) // 依次输入每一条边
    {
        // cout << "请输入边依附的两个顶点的编号：";
        cin >> i >> j; // 输入边依附的两个顶点的编号

        edge[i][j] = 1;
        edge[j][i] = 1; // 置有边标志
    }
}

// 深度优先遍历

void MGraph::DFTraverse(int v)
{
    cout << vertex[v];
    visited[v] = 1;

    for (int j = 0; j < vertexNum; j++)
        if (edge[v][j] == 1 && visited[j] == 0)
            DFTraverse(j);
}

// 广度优先遍历

void MGraph ::BFTraverse(int v)
{
    queue<int> q;
    cout << vertex[v];
    visited[v] = 1;
    q.push(v);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int j = 0; j < vertexNum; j++)
        {
            if (edge[curr][j] == 1 && visited[j] == 0)
            {
                cout << vertex[j];
                visited[j] = 1;
                q.push(j);
            }
        }
    }
}

int main()
{

    int i;

    int n;

    cin >> n;

    char *ch = new char[n];

    for (int j = 0; j < n; j++)

        cin >> ch[j];

    // char ch[] = { 'A','B','C','D','E' };

    /* 测试数据六条边是：(0 1)(0 2)(0 3)(0 4)(1 2)(2 4) */

    int m;

    // cout << "请输入边数：" << endl;

    cin >> m; // 输入边数

    MGraph MG{ch, n, m}; // 建立具有5个顶点6条边的无向图

    for (i = 0; i < MaxSize; i++)

        visited[i] = 0;

    // cout << "广度优先遍历序列是：" << endl;

    MG.BFTraverse(0); // 从顶点0出发进行广度优先遍历

    return 0;
}