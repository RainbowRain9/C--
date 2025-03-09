// Source : https://www.nowcoder.com/practice/1870e68256794c6aa727c8bb71fd9737?tpId=376&tqId=10816557&ru=%2Fexam%2Foj&qru=%2Fta%2F15-days-help%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E9%259D%25A2%25E8%25AF%2595%26topicId%3D376
// Date   : 2024-11-21

/**************************************************
 * 题目描述：
 * 给定一个正整数x,判断x是否存在偶数因子。
 *
 * 示例：
 *   输入：2
 *        1
 *        4
 *   输出：NO
 *        YES
 *
 * 提示：
 *   - 1 <= T <= 10^5
 *   - 1 <= x <= 10^9
 **************************************************/

/*
    解题思路：
    1. 读入测试用例数T
    2. 对每个测试用例x:
       - 从2开始遍历到sqrt(x)
       - 如果找到一个偶数因子,输出YES
       - 如果遍历完都没找到偶数因子,输出NO

    时间复杂度：O(T*sqrt(n))
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
