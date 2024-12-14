// Source : https://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
// Date   : 2024-11-10

/**************************************************
 * 给你一个长度为 n 下标从 0 开始的字符串 blocks ，blocks[i] 要么是 'W' 要么是 'B' ，表示第 i 块的颜色。
 * 字符 'W' 和 'B' 分别表示白色和黑色。
 *
 * 给你一个整数 k ，表示想要 连续 黑色块的数量。
 *
 * 每一次操作中，你可以选择一个白色块将它 涂成 黑色块。
 *
 * 请你返回至少出现 一次 连续 k 个黑色块的最少操作次数。
 *
 * 示例 1：
 *   输入：blocks = "WBBWWBBWBW", k = 7
 *   输出：3
 *   解释：一种得到 7 个连续黑色块的方法是把第 0、4、6 个块涂成黑色。
 *   得到 blocks = "BBBWBBBWBW" 。
 *
 * 示例 2：
 *   输入：blocks = "WBWBBBW", k = 2
 *   输出：0
 *   解释：不需要任何操作，因为已经有 2 个连续的黑色块。
 *
 * 提示：
 *   - n == blocks.length
 *   - 1 <= n <= 100
 *   - blocks[i] 要么是 'W' ，要么是 'B'
 *   - 1 <= k <= n
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口法，维护一个长度为k的窗口
    2. 统计第一个窗口中白色块的数量
    3. 窗口向右滑动时:
       - 如果移出的是白色块，白色块数量减1
       - 如果移入的是白色块，白色块数量加1
    4. 记录过程中的最小白色块数量，即为最少操作次数

    时间复杂度分析：
    - 只需要遍历字符串一次，时间复杂度为 O(n)
    - 只使用了常数个变量，空间复杂度为 O(1)
*/

#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.length();
        int count = 0, num = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (blocks[i] == 'W')
            {
                count++;
            }
            if (i < k - 1)
            {
                continue;
            }
            num = min(count, num);
            if (blocks[i - k + 1] == 'W')
            {
                count--;
            }
        }
        return num;
    }
};

int main()
{
    Solution s;
    cout << s.minimumRecolors("WBBWWBBWBW", 7) << endl; // 输出: 3
    cout << s.minimumRecolors("WBWBBBW", 2) << endl;    // 输出: 0
    return 0;
}