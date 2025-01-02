// Source : https://xujcoj.com/home/contest/2041/problem/3
// Date   : 2024-12-12

/**************************************************
 * 题目描述：
 * 给定一个长度为n的整数序列，请你使用堆排序对这个序列进行升序排序。
 *
 * 示例 1：
 *   输入：5
 *        4 2 5 1 3
 *   输出：1 2 3 4 5
 *   解释：对序列[4,2,5,1,3]使用堆排序，得到升序序列[1,2,3,4,5]
 *
 * 示例 2：
 *   输入：3
 *        3 1 2
 *   输出：1 2 3
 *   解释：对序列[3,1,2]使用堆排序，得到升序序列[1,2,3]
 *
 * 提示：
 *   - 1 <= n <= 100000
 *   - 序列中的元素取值范围为[-10^9, 10^9]
 *   - 序列中的元素各不相同
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

// 向下调整堆的函数
void heapify(vector<int> &nums, int n, int parent) // 向下调整堆的函数
{
    while (parent * 2 + 1 < n) // 当左子节点存在时继续循环
    {
        int child = parent * 2 + 1; // 获取左子节点的索引
        // 如果右子节点存在且大于左子节点,则选择右子节点
        if (child + 1 < n && nums[child + 1] > nums[child])
        {
            child++; // child指向较大的子节点
        }
        // 如果父节点已经大于等于较大的子节点,说明已经满足堆的性质,终止调整
        if (nums[parent] >= nums[child])
        {
            break;
        }
        // 交换父节点和较大的子节点
        swap(nums[parent], nums[child]);
        // 继续向下调整
        parent = child;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // 建立大根堆
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(nums, n, i);
    }

    // 堆排序
    for (int i = n - 1; i > 0; i--)
    {
        swap(nums[0], nums[i]); // 将最大值交换到末尾
        heapify(nums, i, 0);    // 重新调整堆
    }

    // 输出结果
    cout << nums[0];
    for (int i = 1; i < n; i++)
    {
        cout << " " << nums[i];
    }
    cout << endl;

    return 0;
}