---
description: 文章浏览阅读804次，点赞20次，收藏6次。通过对第13-15届蓝桥杯真题的分析，可以发现题目主要围绕。：如果数组是环形的（首尾相连），如何计算？：实现BST的插入和删除操作。祝大家备赛顺利，冲击省一！，找到和最大的连续子数组。展开，且近年逐渐增加。，返回最长回文子串。
title: 蓝桥杯备赛学习笔记：高频考点与真题预测（C++/Java/python版）-CSDN博客
url: https://blog.csdn.net/Magnolia_He/article/details/147091490?spm=1001.2014.3001.5502
author: 
banner: 
source: 
dtype: CSDN
tags: 
state: false
created: 2025-04-10T21:44
updated: 2025-04-10T21:45
---

# 2025蓝桥杯备赛学习笔记

# ——高频考点与真题预测

## 一、考察趋势分析

通过对第13-15届 [蓝桥杯真题](https://so.csdn.net/so/search?q=%E8%93%9D%E6%A1%A5%E6%9D%AF%E7%9C%9F%E9%A2%98&spm=1001.2101.3001.7020) 的分析，可以发现题目主要围绕 **基础算法、数据结构、数学问题、字符串处理、编程语言基础** 展开，且近年逐渐增加 **动态规划、图论、贪心算法** 等较难题目。

### 1\. 基础算法（必考）

- **排序与查找**
	- 快速排序、归并排序（手写实现）
	- 二分查找（变种题，如旋转数组查找）
- **搜索算法**
	- DFS（回溯、排列组合）
	- BFS（最短路径、层序遍历）
- **贪心算法**
	- 区间调度、背包问题（部分背包）
- **动态规划（重点）**
	- 背包问题（01背包、完全背包）
	- 最长公共子序列（LCS）
	- 股票买卖问题（变种DP）

### 2\. 数据结构（必考）

- **线性表**
	- 数组（前缀和、差分数组）
	- 链表（反转、快慢指针）
- **树与二叉树**
	- 二叉搜索树（BST）的插入、删除
	- 平衡二叉树（AVL、红黑树概念）
- **图论**
	- 最短路径（Dijkstra、Floyd）
	- 最小生成树（Prim、Kruskal）
- **栈与队列**
	- 单调栈（接雨水、柱状图最大矩形）
	- 队列（BFS、滑动窗口）

### 3\. 数学问题（常考）

- **数论**
	- 素数筛（埃氏筛、欧拉筛）
	- 最大公约数（GCD）、最小公倍数（LCM）
- **组合数学**
	- 排列组合（卡特兰数、容斥原理）
- **位运算**
	- 异或性质、状态压缩（子集枚举）

### 4\. 字符串处理（常考）

- **字符串匹配**
	- KMP算法（模式匹配）
	- 字典树（Trie）
- **字符串操作**
	- 反转、子串查找、回文判断

### 5\. 编程语言基础（C++/Java）

- **语法基础**
	- 变量、循环、递归
- **文件操作**
	- 读写文件（蓝桥杯常考）
- **输入输出优化**
	- C++ `scanf/printf` vs `cin/cout` （关闭同步流）

---

## 二、预测题目与解题思路

### 1\. 算法类

#### 题目1：最大子数组和（动态规划）

- **描述** ：给定一个整数数组 `nums` ，找到和最大的连续子数组。
- **解题思路** ：
- **C++** ：
	```cpp
	#include <vector>
	#include <algorithm>
	using namespace std;
	int maxSubArray(vector<int>& nums) {
	    int n = nums.size();
	    vector<int> dp(n);
	    dp[0] = nums[0];
	    int res = dp[0];
	    for (int i = 1; i < n; i++) {
	        dp[i] = max(nums[i], dp[i-1] + nums[i]);
	        res = max(res, dp[i]);
	    }
	    return res;
	}
	123456789101112131415
	```
- **Java** ：
	```java
	public int maxSubArray(int[] nums) {
	    int n = nums.length;
	    int[] dp = new int[n];
	    dp[0] = nums[0];
	    int res = dp[0];
	    for (int i = 1; i < n; i++) {
	        dp[i] = Math.max(nums[i], dp[i-1] + nums[i]);
	        res = Math.max(res, dp[i]);
	    }
	    return res;
	}
	1234567891011
	```
- **Python** ：
	```python
	def maxSubArray(nums):
	    dp = [0] * len(nums)
	    dp[0] = nums[0]
	    for i in range(1, len(nums)):
	        dp[i] = max(nums[i], dp[i-1] + nums[i])
	    return max(dp)
	123456
	```
- **变种** ：如果数组是环形的（首尾相连），如何计算？

#### 题目2：最短路径（Dijkstra算法）

- **描述** ：给定带权图，求从 `start` 到 `end` 的最短路径。
- **解题思路** ：
- **C++** ：
	```cpp
	#include <vector>
	#include <queue>
	#include <climits>
	using namespace std;
	vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start) {
	    int n = graph.size();
	    vector<int> dist(n, INT_MAX);
	    dist[start] = 0;
	    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	    pq.push({0, start});
	    
	    while (!pq.empty()) {
	        auto [current_dist, u] = pq.top();
	        pq.pop();
	        if (current_dist > dist[u]) continue;
	        for (auto [v, w] : graph[u]) {
	            if (dist[v] > dist[u] + w) {
	                dist[v] = dist[u] + w;
	                pq.push({dist[v], v});
	            }
	        }
	    }
	    return dist;
	}
	12345678910111213141516171819202122232425
	```
- **Java** ：
	```java
	import java.util.*;
	public int[] dijkstra(List<List<int[]>> graph, int start) {
	    int n = graph.size();
	    int[] dist = new int[n];
	    Arrays.fill(dist, Integer.MAX_VALUE);
	    dist[start] = 0;
	    PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
	    pq.offer(new int[]{0, start});
	    
	    while (!pq.isEmpty()) {
	        int[] curr = pq.poll();
	        int u = curr[1], currentDist = curr[0];
	        if (currentDist > dist[u]) continue;
	        for (int[] edge : graph.get(u)) {
	            int v = edge[0], w = edge[1];
	            if (dist[v] > dist[u] + w) {
	                dist[v] = dist[u] + w;
	                pq.offer(new int[]{dist[v], v});
	            }
	        }
	    }
	    return dist;
	}
	123456789101112131415161718192021222324
	```
- **Python** ：
	```python
	import heapq
	def dijkstra(graph, start):
	    heap = [(0, start)]
	    dist = {node: float('inf') for node in graph}
	    dist[start] = 0
	    while heap:
	        current_dist, u = heapq.heappop(heap)
	        if current_dist > dist[u]:
	            continue
	        for v, w in graph[u].items():
	            if dist[v] > dist[u] + w:
	                dist[v] = dist[u] + w
	                heapq.heappush(heap, (dist[v], v))
	    return dist
	1234567891011121314
	```

### 2\. 数据结构类

#### 题目3：二叉搜索树的插入与删除

- **描述** ：实现BST的插入和删除操作。
- **解题思路** ：
- **C++** ：
	```cpp
	struct TreeNode {
	    int val;
	    TreeNode *left;
	    TreeNode *right;
	    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};
	TreeNode* insert(TreeNode* root, int val) {
	    if (!root) return new TreeNode(val);
	    if (val < root->val) 
	        root->left = insert(root->left, val);
	    else 
	        root->right = insert(root->right, val);
	    return root;
	}
	123456789101112131415
	```
- **Java** ：
	```java
	class TreeNode {
	    int val;
	    TreeNode left, right;
	    TreeNode(int x) { val = x; }
	}
	public TreeNode insert(TreeNode root, int val) {
	    if (root == null) return new TreeNode(val);
	    if (val < root.val) 
	        root.left = insert(root.left, val);
	    else 
	        root.right = insert(root.right, val);
	    return root;
	}
	1234567891011121314
	```
- **\`Python** ：
	```python
	class TreeNode:
	    def __init__(self, val=0, left=None, right=None):
	        self.val = val
	        self.left = left
	        self.right = right
	def insert(root, val):
	    if not root:
	        return TreeNode(val)
	    if val < root.val:
	        root.left = insert(root.left, val)
	    else:
	        root.right = insert(root.right, val)
	    return root
	1234567891011121314
	```

#### 题目4：最长回文子串（动态规划/中心扩展）

- **描述** ：给定字符串 `s` ，返回最长回文子串。
- **解题思路** ：
- **C++** ：
	```cpp
	string longestPalindrome(string s) {
	    int n = s.size();
	    int start = 0, maxLen = 1;
	    
	    auto expand = [&](int l, int r) {
	        while (l >= 0 && r < n && s[l] == s[r]) {
	            if (r - l + 1 > maxLen) {
	                maxLen = r - l + 1;
	                start = l;
	            }
	            l--; r++;
	        }
	    };
	    
	    for (int i = 0; i < n; i++) {
	        expand(i, i);     // 奇数长度
	        expand(i, i+1);   // 偶数长度
	    }
	    return s.substr(start, maxLen);
	}
	1234567891011121314151617181920
	```
- **Java** ：
	```java
	public String longestPalindrome(String s) {
	    int n = s.length();
	    int start = 0, maxLen = 1;
	    
	    for (int i = 0; i < n; i++) {
	        expand(s, i, i);     // 奇数长度
	        expand(s, i, i+1);   // 偶数长度
	    }
	    return s.substring(start, start + maxLen);
	}
	private void expand(String s, int l, int r) {
	    while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
	        if (r - l + 1 > maxLen) {
	            maxLen = r - l + 1;
	            start = l;
	        }
	        l--; r++;
	    }
	}
	1234567891011121314151617181920
	```
- **Python** ：
	```python
	def longestPalindrome(s):
	    n = len(s)
	    dp = [[False] * n for _ in range(n)]
	    res = ""
	    for i in range(n-1, -1, -1):
	        for j in range(i, n):
	            if s[i] == s[j] and (j - i <= 2 or dp[i+1][j-1]):
	                dp[i][j] = True
	                if j - i + 1 > len(res):
	                    res = s[i:j+1]
	    return res
	1234567891011
	```

### 3\. 数学问题类

#### 题目5：数字1的个数（数位DP）

- **描述** ：计算 `1~n` 中数字 `1` 出现的次数。
- **解题思路** ：
- **C++** ：
	```cpp
	int countDigitOne(int n) {
	    int count = 0;
	    for (long i = 1; i <= n; i *= 10) {
	        long divider = i * 10;
	        count += (n / divider) * i + min(max(n % divider - i + 1, 0L), i);
	    }
	    return count;
	}
	12345678
	```
- **Java** ：
	```java
	public int countDigitOne(int n) {
	    int count = 0;
	    for (long i = 1; i <= n; i *= 10) {
	        long divider = i * 10;
	        count += (n / divider) * i + Math.min(Math.max(n % divider - i + 1, 0), i);
	    }
	    return count;
	}
	12345678
	```
- **Python** ：
	```python
	def countDigitOne(n):
	    count = 0
	    i = 1
	    while i <= n:
	        divider = i * 10
	        count += (n // divider) * i + min(max(n % divider - i + 1, 0), i)
	        i *= 10
	    return count
	12345678
	```

#### 题目6：阶乘计算（大数处理）

- **描述** ：计算 `n!`（ `n` 可能很大，如 `1000!`）。
- **解题思路** ：
	```python
	def factorial(n):
	    res = 1
	    for i in range(1, n+1):
	        res *= i
	    return res
	12345
	```
	- **优化** ：如果 `n` 很大，使用 `math.factorial` 或高精度计算（如Python默认支持大整数）。

### 4\. 字符串处理类

#### 题目7：判断回文串（双指针）

- **描述** ：判断字符串 `s` 是否是回文。
- **解题思路** ：
- **C++** ：
	```cpp
	bool isPalindrome(string s) {
	    int left = 0, right = s.size() - 1;
	    while (left < right) {
	        if (s[left++] != s[right--]) 
	            return false;
	    }
	    return true;
	}
	12345678
	```
- **Java** ：
	```java
	public boolean isPalindrome(String s) {
	    int left = 0, right = s.length() - 1;
	    while (left < right) {
	        if (s.charAt(left++) != s.charAt(right--)) 
	            return false;
	    }
	    return true;
	}
	12345678
	```
- **Python** ：
	```python
	def isPalindrome(s):
	    left, right = 0, len(s)-1
	    while left < right:
	        if s[left] != s[right]:
	            return False
	        left += 1
	        right -= 1
	    return True
	12345678
	```

#### 题目8：子序列判断（双指针）

- **描述** ：判断 `s` 是否是 `t` 的子序列。
- **解题思路** ：
	```python
	def isSubsequence(s, t):
	    i, j = 0, 0
	    while i < len(s) and j < len(t):
	        if s[i] == t[j]:
	            i += 1
	        j += 1
	    return i == len(s)
	1234567
	```

---

## 三、备考策略

1. **刷题优先级**
	- **必刷** ：动态规划（背包、LCS）、DFS/BFS、Dijkstra、二分查找。
	- **次重点** ：数论（素数筛、GCD）、字符串（KMP、回文）。
	- **保底题** ：文件操作、递归、基础语法。
2. **时间分配建议**
	- **填空题** （5题）：10分钟/题（数学、模拟题为主）。
	- **编程题** （5题）：前2题暴力解法（30分钟），后3题优化（60分钟）。
3. **调试技巧**
	- **对拍** ：用暴力算法验证优化算法的正确性。
	- **边界测试** ： `n=0` 、 `n=1e5` 等极端情况。

---

## 四、总结

蓝桥杯题目 **题型固定但变种多** ，重点掌握：

✅ **动态规划** （背包、LCS）

✅ **图论** （Dijkstra、BFS/DFS）

✅ **数学** （数论、组合数学）

✅ **字符串** （KMP、回文）

✅ **数据结构** （BST、单调栈）

**建议** ：

- 整理模板代码（如快速幂、并查集）。
- 模拟考试环境（限时、无IDE调试）。

祝大家备赛顺利，冲击省一！ 🚀

Better Rose的资料分享 微信名片