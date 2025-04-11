---
命名: __
课程: []
状态: 计划中
执行人: 蔡蔡鸿宇
时间安排: Invalid date
待解决问题: 待解决:[ 0 ]
created: 2025-04-11T13:05
updated: 2025-04-11T13:06
---

# 蓝桥杯高频考点C++代码模板

## 一、基础模板（输入输出加速）
```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    // 输入输出加速（慎用scanf/printf混用）
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // 代码逻辑
    return 0;
}
```

---

## 二、暴力搜索模板

### 1. **DFS（回溯法）**
```cpp
// 例：全排列
vector<int> path;
vector<bool> visited(n, false);

void dfs(vector<int>& nums) {
    if (path.size() == nums.size()) {
        // 处理结果
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (visited[i]) continue;
        visited[i] = true;
        path.push_back(nums[i]);
        dfs(nums);
        path.pop_back();
        visited[i] = false;
    }
}
```

### 2. **BFS（层序遍历）**
```cpp
// 例：迷宫最短路径
struct Node { int x, y, step; };
queue<Node> q;
vector<vector<bool>> visited(n, vector<bool>(m, false));

q.push({0, 0, 0});
visited[0][0] = true;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

while (!q.empty()) {
    auto [x, y, step] = q.front();
    q.pop();
    if (x == n-1 && y == m-1) {
        cout << step;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] != '#') {
            visited[nx][ny] = true;
            q.push({nx, ny, step + 1});
        }
    }
}
```

---

## 三、动态规划模板

### 1. **线性DP（最长上升子序列）**
```cpp
vector<int> dp(n, 1);
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
}
int ans = *max_element(dp.begin(), dp.end());
```

### 2. **背包问题（01背包）**
```cpp
vector<int> dp(容量 + 1, 0);
for (int i = 0; i < n; i++) {
    for (int j = 容量; j >= w[i]; j--) { // 逆序！
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
}
```

---

## 四、图论模板

### 1. **Dijkstra（最短路）**
```cpp
vector<vector<pair<int, int>>> graph(n); // {to, weight}
vector<int> dist(n, INT_MAX);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // {distance, node}

dist[0] = 0;
pq.push({0, 0});

while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u]) continue;
    for (auto [v, w] : graph[u]) {
        if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
        }
    }
}
```

### 2. **并查集（连通性）**
```cpp
vector<int> parent(n);
iota(parent.begin(), parent.end(), 0); // 初始化父节点为自己

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) parent[fx] = fy;
}
```

---

## 五、其他高频模板

### 1. **快速幂（取模）**
```cpp
long long fast_pow(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
```

### 2. **KMP（字符串匹配）**
```cpp
vector<int> build_next(const string& pattern) {
    vector<int> next(pattern.size(), 0);
    for (int i = 1, j = 0; i < pattern.size(); i++) {
        while (j > 0 && pattern[i] != pattern[j]) j = next[j-1];
        if (pattern[i] == pattern[j]) j++;
        next[i] = j;
    }
    return next;
}
```

---

## 六、调试技巧
```cpp
// 输出中间变量
cout << "Debug: " << variable << endl;

// 断言检查
#include <cassert>
assert(condition);
```

---

**使用建议**：根据题目类型选择模板，优先背诵 **DFS/BFS、DP、并查集、Dijkstra**，考试时冷静修改参数即可！