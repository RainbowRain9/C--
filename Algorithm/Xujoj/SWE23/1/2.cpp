/**************************************************
 * 题目描述：
 * Alice在银行存了a元钱，定期b年，每年的利息是c%。年利息计算时会只保留到分（0.01元），
 * 分以下的利息会被舍去（注意不是四舍五入，是舍弃），年利息会累加到本金中。
 * 问最终Alice的账户里有多少钱？
 *
 * 示例 1：
 *   输入：1000 2 10
 *   输出：1210
 *   解释：第1年利息100元，本金变为1100元，第2年利息110元，最终本金1210元
 *
 * 示例 2：
 *   输入：9 2 1
 *   输出：9.18
 *   解释：第1年利息0.09元，本金变为9.09元，第2年利息0.09元，最终本金9.18元
 *
 * 提示：
 *   - 这是一道多组案例的题目，n表示案例数量(n<=1000)
 *   - 每组案例由三个正整数a、b、c组成(a<=1e5，b<=100，c<=10)
 *   - 输出浮点数表示最终账户金额，每组案例输出后换行
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
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        double a;
        int b, c;
        cin >> a >> b >> c;
        for (int i = 0; i < b; i++)
        {
            double d = a * c / 100;
            d = floor(d * 100) / 100;
            a += d;
        }
        if (a == floor(a))
        {
            cout << static_cast<int>(a) << endl;
        }
        else
        {
            cout << fixed << setprecision(2) << a << endl;
        }
    }
    return 0;
}