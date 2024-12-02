// Source : https://www.xujcoj.com/home/problem/detail/4348
// Date   : 2024-12-01

/**************************************************
 * 题目描述：
 * 小蓝想了一个6位数字，每个位置上的数可能是0-9，他告诉了你一些信息：
 * 1、第一位和第二位的和为11；
 * 2、第二位和第三位差的绝对值是5；
 * 3、第三位和第四位的最大公因数为2；
 * 4、第四位和第五位按位或的值是7；
 * 5、第五位和第六位按位异或的值是3；
 * 6、第六位和第一位按位与的值是4。
 * 请你说出满足以上条件的6位数有多少个。
 *
 * 示例 1：
 *   输入：
 *   无
 *   输出：
 *   答案数字
 *   解释：
 *   输出满足所有条件的6位数的个数
 *
 *
 * 提示：
 *   - 这是一道填空题，只需要输出最终答案
 *   - 需要考虑所有可能的6位数组合
 *   - 注意位运算：与(&)、或(|)、异或(^)的运算规则
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

int GCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int count = 0;
    
    for(int i = 100000; i <= 999999; i++) {
        // 提取各位数字
        int d1 = i / 100000;        // 第1位
        int d2 = (i / 10000) % 10;  // 第2位 
        int d3 = (i / 1000) % 10;   // 第3位
        int d4 = (i / 100) % 10;    // 第4位
        int d5 = (i / 10) % 10;     // 第5位
        int d6 = i % 10;            // 第6位
        
        // 判断6个条件
        if(d1 + d2 == 11 && 
           abs(d2 - d3) == 5 &&
           GCD(d3, d4) == 2 &&
           (d4 | d5) == 7 &&
           (d5 ^ d6) == 3 &&
           (d6 & d1) == 4) {
            count++;
        }
    }
    
    cout << count << endl;
    return 0;
}