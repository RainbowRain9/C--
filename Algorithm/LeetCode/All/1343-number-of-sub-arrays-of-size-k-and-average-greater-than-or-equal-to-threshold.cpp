// Source : https://leetcode.cn/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
// Date   : 2024-11-10

/**************************************************
 * 给你一个整数数组 arr 和两个整数 k 和 threshold 。
 *
 * 请你返回长度为 k 且平均值大于等于 threshold 的子数组数目。
 *
 * 示例 1：
 *   输入：arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
 *   输出：3
 *   解释：子数组 [2,5,5],[5,5,5] 和 [5,5,8] 的平均值分别为 4，5 和 6 。
 *   其他长度为 3 的子数组的平均值都小于 4 （threshold 的值)。
 *
 * 示例 2：
 *   输入：arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
 *   输出：6
 *   解释：前 6 个长度为 3 的子数组平均值都大于 5 。注意平均值不是整数。
 *
 * 提示：
 *   - 1 <= arr.length <= 10^5
 *   - 1 <= arr[i] <= 10^4
 *   - 1 <= k <= arr.length
 *   - 0 <= threshold <= 10^4
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口法，维护一个长度为k的窗口
    2. 计算第一个窗口的和
    3. 窗口向右滑动时:
       - 减去左边移出的元素
       - 加上右边移入的元素
    4. 判断当前窗口的平均值是否大于等于阈值
    5. 统计满足条件的窗口数量

    时间复杂度分析：
    - 只需要遍历数组一次，时间复杂度为 O(n)
    - 只使用了常数个变量，空间复杂度为 O(1)
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        double sum = 0;
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (i < k - 1)
            {
                continue;
            }
            if (sum / k >= threshold)
            {
                count++;
            }
            sum -= arr[i - k + 1];
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {2, 2, 2, 2, 5, 5, 5, 8};
    cout << s.numOfSubarrays(arr1, 3, 4) << endl; // 输出: 3

    vector<int> arr2 = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
    cout << s.numOfSubarrays(arr2, 3, 5) << endl; // 输出: 6

    return 0;
}