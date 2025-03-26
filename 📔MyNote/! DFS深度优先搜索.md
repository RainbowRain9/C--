# ! DFS深度优先搜索

## 一、前置知识
- 递归
- 栈
- 图的基本概念
- 树的基

## 二、算法分析

### 1. 算法定义
深度优先搜索(Depth First Search, DFS)是一种用于遍历或搜索树/图的算法。其过程简要来说是对每一个可能的分支路径深入到不能再深入为止。

### 2. 基本特点
- 沿着一条路径一直走到底
- 使用回溯返回到最近的岔路口
- 可以用递归或栈实现
- 空间复杂度与搜索深度成正比

### 3. 应用场景
- 寻找路径问题
- 迷宫求解
- 连通性问题
- 拓扑排序
- 求解排列组合

## 三、示例分析

### 1. 基本示例：二叉树遍历
```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

void dfs(TreeNode* root) {
    if (!root) return;
    
    cout << root->val;     // 先序遍历
    dfs(root->left);       // 遍历左子树
    dfs(root->right);      // 遍历右子树
}
```

### 2. 图的DFS
```cpp
void dfs(vector<vector<int>>& graph, int start, vector<bool>& visited) {
    visited[start] = true;
    cout << start << " ";
    
    for (int next : graph[start]) {
        if (!visited[next]) {
            dfs(graph, next, visited);
        }
    }
}
```

## 四、实现方式

### 1. 递归实现
```cpp
class Solution {
private:
    vector<bool> visited;
    
public:
    void dfs(vector<vector<int>>& graph, int node) {
        // 1. 访问当前节点
        visited[node] = true;
        cout << node << " ";
        
        // 2. 递归访问相邻节点
        for (int next : graph[node]) {
            if (!visited[next]) {
                dfs(graph, next);
            }
        }
    }
};
```

### 2. 栈实现
```cpp
class Solution {
public:
    void dfsIterative(vector<vector<int>>& graph, int start) {
        vector<bool> visited(graph.size(), false);
        stack<int> st;
        
        // 1. 将起始节点压入栈
        st.push(start);
        
        while (!st.empty()) {
            // 2. 弹出栈顶节点
            int node = st.top();
            st.pop();
            
            if (visited[node]) continue;
            
            // 3. 访问该节点
            visited[node] = true;
            cout << node << " ";
            
            // 4. 将未访问的相邻节点压入栈
            for (int i = graph[node].size() - 1; i >= 0; i--) {
                int next = graph[node][i];
                if (!visited[next]) {
                    st.push(next);
                }
            }
        }
    }
};
```

## 五、模拟代码过程

### 1. 以二叉树为例
```
       1
      / \
     2   3
    / \
   4   5

执行过程：
1. 访问节点1
2. 递归访问左子树
   - 访问节点2
   - 访问节点4
   - 回溯到节点2
   - 访问节点5
   - 回溯到节点2
3. 回溯到节点1
4. 递归访问右子树
   - 访问节点3

输出序列：1 2 4 5 3
```

## 六、复杂度分析

### 1. 时间复杂度
- 树的DFS：O(n)，n为节点数
- 图的DFS：O(V + E)，V为顶点数，E为边数

### 2. 空间复杂度
- 递归实现：O(h)，h为递归深度
- 栈实现：O(V)，V为顶点数

## 七、常见错误

### 1. 忘记标记访问状态
```cpp
// 错误代码
void dfs(vector<vector<int>>& graph, int node) {
    for (int next : graph[node]) {
        dfs(graph, next);  // 没有判断是否访问过，会导致死循环
    }
}

// 正确代码
void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited) {
    visited[node] = true;
    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(graph, next, visited);
        }
    }
}
```

### 2. 递归终止条件不明确
```cpp
// 错误代码
void dfs(TreeNode* root) {
    dfs(root->left);   // 没有判断空节点
    dfs(root->right);
}

// 正确代码
void dfs(TreeNode* root) {
    if (!root) return;  // 明确递归终止条件
    dfs(root->left);
    dfs(root->right);
}
```

## 八、实战技巧

### 1. 回溯模板
```cpp
void backtrack(参数) {
    if (终止条件) {
        保存结果;
        return;
    }
    
    for (选择：选择列表) {
        做选择;
        backtrack(参数);
        撤销选择;
    }
}
```

### 2. 记忆化搜索
```cpp
unordered_map<string, bool> memo;

bool dfs(string state) {
    if (memo.count(state)) {
        return memo[state];
    }
    
    // 处理逻辑
    bool result = ...;
    
    return memo[state] = result;
}
```

## 九、经典题目

### 1. 岛屿数量 (LeetCode 200)
```cpp
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }
        
        grid[i][j] = '0';  // 标记已访问
        
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
```

## 十、总结

### 1. 核心要点
- 理解DFS的本质是沿着一条路径搜索到底
- 掌握递归和栈两种实现方式
- 注意访问标记和终止条件
- 灵活运用回溯思想

### 2. 实战建议
- 先画图理清搜索路径
- 确定状态转移方式
- 考虑边界情况
- 注意代码优化

### 3. 进阶方向
- 结合动态规划
- 使用记忆化搜索
- 优化空间复杂度
- 处理复杂约束
