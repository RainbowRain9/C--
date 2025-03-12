/*
 * @Author: RainbowRain9
 * @Date: 2025-03-11 20:21:38
 * @LastEditTime: 2025-03-11 22:04:18
 * @FilePath: \C++\Algorithm\LeetCode\All\344-reverse-string.cpp
 * @Description: 
 */
/*
 * @lc app=leetcode.cn id=344 lang=cpp
 * @lcpr version=30101
 *
 * [344] 反转字符串
 *
 * https://leetcode.cn/problems/reverse-string/description/
 *
 * algorithms
 * Easy (80.57%)
 * Likes:    922
 * Dislikes: 0
 * Total Accepted:    969.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
 * 
 * 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = ["h","e","l","l","o"]
 * 输出：["o","l","l","e","h"]
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = ["H","a","n","n","a","h"]
 * 输出：["h","a","n","n","a","H"]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] 都是 ASCII 码表中的可打印字符
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
    void reverseString(vector<char>& s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while(left < right){
            swap(s[left++], s[right--]);
        }
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<char> s1 = {'h','e','l','l','o'};
    solution.reverseString(s1);
    for(char c : s1) cout << c;
    cout << endl;

    vector<char> s2 = {'H','a','n','n','a','h'};
    solution.reverseString(s2);
    for(char c : s2) cout << c;
    cout << endl;
}



/*
// @lcpr case=start
// ["h","e","l","l","o"]\n
// @lcpr case=end

// @lcpr case=start
// ["H","a","n","n","a","h"]\n
// @lcpr case=end

 */

