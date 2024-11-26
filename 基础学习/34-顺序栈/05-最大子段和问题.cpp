/*
问题描述：最大子段和问题

给定一个整数序列，找到该序列中连续子序列的最大和。要求使用分治法实现。

示例：
输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

输入描述：
第一行输入n，表示待输入的整数序列有n个元素。
第二行输入n个整数，表示整数序列。

输出描述：
输出最大子段和。

样例输入：
9
-2 1 -3 4 -1 2 1 -5 4

样例输出：
6

提示说明：
1. 使用分治法解决此问题。
2. 考虑三种情况：最大子段完全位于左半部分、右半部分，或者跨越中间点。
3. 递归求解左右两半部分，然后处理跨越中间的情况。
4. 最后比较这三种情况，取最大值。
5. 输出结果后需要换行。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int crossMidMax(const vector<int> &arr, int l, int m, int r)
{
    int leftSum = INT_MIN;
    int sum = 0;
    for (int i = m; i >= l; i--)
    {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    int rightSum = INT_MIN;
    sum = 0;
    for (int i = m + 1; i <= r; i++)
    {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubSum(const vector<int> &arr, int l, int r)
{
    if (l == r)
    {
        return arr[l];
    }

    int m = (l + r) / 2;

    int leftSum = maxSubSum(arr, l, m);
    int rightSum = maxSubSum(arr, m + 1, r);
    int crossSum = crossMidMax(arr, l, m, r);

    return max({leftSum, rightSum, crossSum});
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxSum = maxSubSum(arr, 0, n - 1);
    cout << maxSum << endl;

    return 0;
}
