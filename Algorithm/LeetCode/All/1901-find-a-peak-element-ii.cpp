/*
 * @Author: RainbowRain9
 * @Date: 2025-03-21 15:02:15
 * @LastEditTime: 2025-03-21 15:18:12
 * @FilePath: \C++\Algorithm\LeetCode\All\1901-find-a-peak-element-ii.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=1901 lang=cpp
 * @lcpr version=30104
 *
 * [1901] 寻找峰值 II
 *
 * https://leetcode.cn/problems/find-a-peak-element-ii/description/
 *
 * algorithms
 * Medium (58.91%)
 * Likes:    181
 * Dislikes: 0
 * Total Accepted:    27.2K
 * Total Submissions: 46.4K
 * Testcase Example:  '[[1,4],[3,2]]'
 *
 * 一个 2D 网格中的 峰值 是指那些 严格大于 其相邻格子(上、下、左、右)的元素。
 *
 * 给你一个 从 0 开始编号 的 m x n 矩阵 mat ，其中任意两个相邻格子的值都 不相同 。找出 任意一个 峰值 mat[i][j] 并
 * 返回其位置 [i,j] 。
 *
 * 你可以假设整个矩阵周边环绕着一圈值为 -1 的格子。
 *
 * 要求必须写出时间复杂度为 O(m log(n)) 或 O(n log(m)) 的算法
 *
 *
 *
 *
 *
 * 示例 1:
 *
 *
 *
 * 输入: mat = [[1,4],[3,2]]
 * 输出: [0,1]
 * 解释: 3 和 4 都是峰值，所以[1,0]和[0,1]都是可接受的答案。
 *
 *
 * 示例 2:
 *
 *
 *
 * 输入: mat = [[10,20,15],[21,30,14],[7,16,32]]
 * 输出: [1,1]
 * 解释: 30 和 32 都是峰值，所以[1,1]和[2,2]都是可接受的答案。
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 500
 * 1 <= mat[i][j] <= 10^5
 * 任意两个相邻元素均不相等.
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
// TODO 2025-03-21:
// @lc code=start
class Solution
{
public:
    int indexOfMax(vector<int> &a)
    {
        return ranges::max_element(a) - a.begin();
    }

    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int left = -1, right = mat.size() - 1;
        while (left + 1 < right)
        {
            int i = left + (right - left) / 2;
            int j = indexOfMax(mat[i]);
            (mat[i][j] > mat[i + 1][j] ? right : left) = i;
        }
        return {right, indexOfMax(mat[right])};
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [[1,4],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[10,20,15],[21,30,14],[7,16,32]]\n
// @lcpr case=end

 */
