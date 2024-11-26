// Source : https://www.nowcoder.com/practice/dcce2d0cc8f740c29e0885df96c9d625?tpId=376&tqId=10816557&ru=/exam/oj&qru=/ta/15-days-help/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E9%259D%25A2%25E8%25AF%2595%26topicId%3D376
// Date   : 2024-01-01

/**************************************************
 * 题目描述：
 * 给定一个正整数a,a翻转数位得到数字b,计算a+b。
 *
 * 示例 1：
 *   输入：12
 *   输出：33
 *   解释：a=12,翻转得到b=21,a+b=33
 *
 * 示例 2：
 *   输入：23
 *   输出：55
 *
 * 提示：
 *   - 1 <= a <= 10^9
 *   - a的每一位都非0
 **************************************************/

/*
    解题思路：
    1. 读入正整数a
    2. 将a翻转得到b
    3. 返回a+b

    时间复杂度：O(logn),n为输入数字的位数
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// int main()
// {
//     int a;
//     cin >> a;

//     // 翻转a得到b
//     int b = 0;
//     int temp = a;
//     while (temp > 0)
//     {
//         b = b * 10 + temp % 10;
//         temp /= 10;
//     }

//     cout << a + b << endl;

//     return 0;
// }

int main()
{
    int a;
    cin >> a;
    string s = to_string(a);
    string b = s;
    reverse(b.begin(), b.end());
    cout << a + stoi(b) << endl;
}