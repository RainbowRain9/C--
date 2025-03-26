/*
 * @lc app=leetcode.cn id=1042 lang=cpp
 * @lcpr version=30104
 *
 * [1042] 不邻接植花
 *
 * https://leetcode.cn/problems/flower-planting-with-no-adjacent/description/
 *
 * algorithms
 * Medium (61.41%)
 * Likes:    242
 * Dislikes: 0
 * Total Accepted:    34.3K
 * Total Submissions: 55.7K
 * Testcase Example:  '3\n[[1,2],[2,3],[3,1]]'
 *
 * 有 n 个花园，按从 1 到 n 标记。另有数组 paths ，其中 paths[i] = [xi, yi] 描述了花园 xi 到花园 yi
 * 的双向路径。在每个花园中，你打算种下四种花之一。
 * 
 * 另外，所有花园 最多 有 3 条路径可以进入或离开.
 * 
 * 你需要为每个花园选择一种花，使得通过路径相连的任何两个花园中的花的种类互不相同。
 * 
 * 以数组形式返回 任一 可行的方案作为答案 answer，其中 answer[i] 为在第 (i+1) 个花园中种植的花的种类。花的种类用
 * 1、2、3、4 表示。保证存在答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 3, paths = [[1,2],[2,3],[3,1]]
 * 输出：[1,2,3]
 * 解释：
 * 花园 1 和 2 花的种类不同。
 * 花园 2 和 3 花的种类不同。
 * 花园 3 和 1 花的种类不同。
 * 因此，[1,2,3] 是一个满足题意的答案。其他满足题意的答案有 [1,2,4]、[1,4,2] 和 [3,2,1]
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 4, paths = [[1,2],[3,4]]
 * 输出：[1,2,1,2]
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
 * 输出：[1,2,3,4]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^4
 * 0 <= paths.length <= 2 * 10^4
 * paths[i].length == 2
 * 1 <= xi, yi <= n
 * xi != yi
 * 每个花园 最多 有 3 条路径可以进入或离开
 * 
 * 
 */


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// 3\n[[1,2],[2,3],[3,1]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,2],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]\n
// @lcpr case=end

 */

