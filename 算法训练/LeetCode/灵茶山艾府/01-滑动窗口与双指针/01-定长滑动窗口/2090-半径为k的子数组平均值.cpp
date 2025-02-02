// Source : https://leetcode.cn/problems/k-radius-subarray-averages/
// Date   : 2024-11-10

/**************************************************
 * 给你一个下标从 0 开始的数组 nums，该数组由 n 个整数组成，另给你一个整数 k。
 *
 * 半径为 k 的子数组平均值是指：nums 中一个以下标 i 为中心，长度为 2k+1 的子数组中所有元素的平均值，
 * 即下标在 i-k 和 i+k 范围（含 i-k 和 i+k）内所有元素的平均值。
 * 如果在下标 i 前或后不足 k 个元素，则下标 i 的子数组平均值是 -1。
 *
 * 构建并返回一个长度为 n 的数组 avgs，其中 avgs[i] 是以下标 i 为中心的子数组的半径为 k 的平均值。
 *
 * x 个元素的平均值是 x 个元素相加之和除以 x，此时使用截断式整数除法，即需要去掉结果的小数部分。
 *
 * 示例 1：
 *   输入：nums = [7,4,3,9,1,8,5,2,6], k = 3
 *   输出：[-1,-1,-1,5,4,4,-1,-1,-1]
 *   解释：
 *   - avg[0]、avg[1] 和 avg[2] 是 -1 ，因为在这几个下标左边的元素数量都不足 k 个
 *   - 中心为下标 3 且半径为 3 的子数组的元素总和是：7 + 4 + 3 + 9 + 1 + 8 + 5 = 37
 *     该子数组的平均值为 37 / 7 = 5，故 avg[3] = 5
 *   - 中心为下标 4 的子数组，avg[4] = (4 + 3 + 9 + 1 + 8 + 5 + 2) / 7 = 4
 *   - 中心为下标 5 的子数组，avg[5] = (3 + 9 + 1 + 8 + 5 + 2 + 6) / 7 = 4
 *   - avg[6]、avg[7] 和 avg[8] 是 -1 ，因为在这几个下标右边的元素数量都不足 k 个
 *
 * 示例 2：
 *   输入：nums = [100000], k = 0
 *   输出：[100000]
 *   解释：
 *   - 中心为下标 0 且半径 0 的子数组的平均值是 100000 / 1 = 100000
 *
 * 示例 3：
 *   输入：nums = [8], k = 100000
 *   输出：[-1]
 *   解释：
 *   - avg[0] = -1 ，因为在下标 0 前后的元素数量均不足 k 个
 *
 * 提示：
 *   - n == nums.length
 *   - 1 <= n <= 10^5
 *   - 0 <= nums[i], k <= 10^5
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口法，维护一个长度为2k+1的窗口
    2. 对于每个位置i:
       - 如果i < k 或 i > n-k-1,则avg[i] = -1
       - 否则计算以i为中心的2k+1个元素的平均值
    3. 使用long long避免整数溢出
    4. 窗口向右滑动时:
       - 减去左边移出的元素
       - 加上右边移入的元素

    时间复杂度分析：
    - 只需要遍历数组一次，时间复杂度为 O(n)
    - 只使用了常数个变量，空间复杂度为 O(1)，不包括返回数组

    注意事项：
    1. 需要处理k=0的特殊情况
    2. 使用long long避免整数溢出
    3. 窗口大小为2k+1
    4. 对于不足2k+1个元素的位置，返回-1
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        // 使用long long避免整数溢出
        long long sum = 0;
        // 窗口长度为2k+1
        int len = 2 * k + 1;
        // 数组长度
        int n = nums.size();
        // 初始化结果数组,所有元素为-1
        vector<int> avg(n, -1);

        // 遍历数组
        for (int i = 0; i < n; i++)
        {
            // 将新元素加入窗口
            sum += nums[i];

            // 窗口未形成时继续
            if (i + 1 < len)
            {
                continue;
            }

            // 计算窗口中心位置的平均值
            avg[i - k] = sum / len;

            // 移除窗口最左边的元素
            sum -= nums[i - len + 1];
        }
        return avg;
    }
};

int main()
{
    Solution s;
    // 测试用例
    vector<int> nums = {7, 4, 3, 9, 1, 8, 5, 2, 6};
    int k = 3;
    vector<int> result = s.getAverages(nums, k);

    // 输出结果
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
