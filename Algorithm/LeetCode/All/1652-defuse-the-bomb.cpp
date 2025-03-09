// Source : https://leetcode.cn/problems/defuse-the-bomb/
// Date   : 2024-11-11

/**************************************************
 * 你有一个炸弹需要拆除，时间紧迫！你的情报员会给你一个长度为 n 的循环数组 code 以及一个密钥 k 。
 *
 * 为了获得正确的密码：
 * - 如果 k > 0 ，将第 i 个数字用接下来 k 个数字之和替换。
 * - 如果 k < 0 ，将第 i 个数字用之前 k 个数字之和替换。
 * - 如果 k == 0 ，将第 i 个数字用 0 替换。
 *
 * 由于 code 是循环的，code[n-1] 下一个元素是 code[0] ，且 code[0] 前一个元素是 code[n-1] 。
 *
 * 给你循环数组 code 和整数密钥 k ，请你返回解密后的结果来拆除炸弹！
 *
 * 示例 1：
 *   输入：code = [5,7,1,4], k = 3
 *   输出：[12,10,16,13]
 *   解释：每个数字都被接下来 3 个数字之和替换。解密后的密码为 [7+1+4, 1+4+5, 4+5+7, 5+7+1]。注意到数组是循环连接的。
 *
 * 示例 2：
 *   输入：code = [1,2,3,4], k = 0
 *   输出：[0,0,0,0]
 *   解释：当 k 为 0 时，所有数字都被 0 替换。
 *
 * 示例 3：
 *   输入：code = [2,4,9,3], k = -2
 *   输出：[12,5,6,13]
 *   解释：解密后的密码为 [3+9, 2+3, 4+2, 9+4]。注意到数组是循环连接的。
 *
 * 提示：
 *   - n == code.length
 *   - 1 <= n <= 100
 *   - 1 <= code[i] <= 100
 *   - -(n - 1) <= k <= n - 1
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口法，维护一个长度为|k|的窗口
    2. 由于数组是循环的，需要特殊处理边界情况:
       - 可以将原数组复制一份接在后面，这样就不用处理循环
       - 或者使用取模运算来处理循环
    3. 根据k的正负和大小分别处理:
       - k > 0: 用后面k个数之和替换
       - k < 0: 用前面|k|个数之和替换
       - k = 0: 全部替换为0

    时间复杂度分析：
    - 需要遍历数组一次，时间复杂度为 O(n)
    - 只使用了常数个变量，空间复杂度为 O(1)
*/

#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        // 获取数组长度
        int n = code.size();
        // 存储结果的数组
        vector<int> ans(n);
        // 如果k为0,直接返回全0数组
        if (k == 0) return ans;
        
        // r表示窗口右边界的初始位置
        // 如果k>0,从k+1开始;如果k<0,从n开始
        int r = k > 0 ? k + 1 : n;
        // 取k的绝对值,统一处理正负情况
        k = abs(k);
        // s记录窗口内元素之和
        int s = 0;
        
        // 初始化第一个窗口的和
        for (int i = r - k; i < r; i++)
        {
            s += code[i % n];  // 使用取模处理循环数组
        }
        
        // 滑动窗口遍历数组
        for (int i = 0; i < n; i++)
        {
            ans[i] = s;  // 记录当前窗口和
            // 更新窗口和:加入新元素,减去窗口最左侧元素
            s += code[r % n] - code[(r - k) % n];
            r++;  // 窗口右移
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> code1 = {5, 7, 1, 4};
    vector<int> ans1 = s.decrypt(code1, 3);
    for (int x : ans1)
        cout << x << " "; // 输出: 12 10 16 13
    cout << endl;

    vector<int> code2 = {1, 2, 3, 4};
    vector<int> ans2 = s.decrypt(code2, 0);
    for (int x : ans2)
        cout << x << " "; // 输出: 0 0 0 0
    cout << endl;

    vector<int> code3 = {2, 4, 9, 3};
    vector<int> ans3 = s.decrypt(code3, -2);
    for (int x : ans3)
        cout << x << " "; // 输出: 12 5 6 13
    cout << endl;

    return 0;
}