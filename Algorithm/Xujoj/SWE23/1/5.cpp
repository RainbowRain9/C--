/*
 * @Author: RainbowRain9
 * @Date: 2025-03-23 15:22:52
 * @LastEditTime: 2025-03-23 16:03:27
 * @FilePath: \C++\Algorithm\Xujoj\SWE23\1\5.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 有一个数列，前3项是a、b、c，从第4项开始：
 * - 第3m+1项（如第4、7、10项）是前三项之和的末三位数
 * - 第3m+2项（如第5、8、11项）是前两项的最大公因数
 * - 第3m项（如第6、9、12项）是前三项乘积的末三位数
 * 规定：如果两个数中至少有一个是0，则最大公因数是另一个数
 *
 * 示例 1：
 *   输入：2
 *        1 2 3 6
 *        123 456 789 10
 *   输出：54
 *        514
 *   解释：第一组案例求第6项，是前三项乘积的末三位数
 *        第二组案例求第10项，是前三项之和的末三位数
 *
 * 提示：
 *   - n<=1000，表示案例数量
 *   - 0<=a,b,c<=999，分别是前三项的值
 *   - 1<=x<=300000，表示要求的项数
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

int threeSum(int a, int b, int c)
{
    return (a + b + c) % 1000;
}

int GCD(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int getPd(int a, int b, int c)
{
    return (a * b * c) % 1000;
}

int f(int a, int b, int c, int x)
{
    if (x == 1) return a;
    if (x == 2) return b;
    if (x == 3) return c;
    
    vector<int> ans(x + 1);
    ans[1] = a; // 1
    ans[2] = b; // 2
    ans[3] = c; // 3
    // ans[4] = threeSum(ans[1], ans[2], ans[3]); // 6
    // ans[5] = GCD(ans[3], ans[4]); // 3
    // ans[6] = getPd(ans[3], ans[4], ans[5]); // 54
    for (int i = 4; i <= x; i++)
    {
        if (i % 3 == 1)
        {
            ans[i] = threeSum(ans[i - 3], ans[i - 2], ans[i - 1]);
        }
        else if (i % 3 == 2)
        {
            ans[i] = GCD(ans[i - 2], ans[i - 1]);
        }
        else
        {
            ans[i] = getPd(ans[i - 3], ans[i - 2], ans[i - 1]);
        }
    }
    return ans[x];
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        int x;
        cin >> a >> b >> c >> x;
        cout << f(a, b, c, x) << endl;
    }
    return 0;
}