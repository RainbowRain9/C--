/*
 * @Author: RainbowRain9
 * @Date: 2025-04-02 19:33:55
 * @LastEditTime: 2025-04-02 20:18:21
 * @FilePath: \C++\Algorithm\PTA\L1-016-查验身份证.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 一个合法的身份证号码由17位地区、日期编号和顺序编号加1位校验码组成。校验码的计算规则如下：
 * 1. 对前17位数字加权求和，权重为{7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}
 * 2. 将和对11取模得到值Z
 * 3. 根据Z值对应校验码M：Z：0 1 2 3 4 5 6 7 8 9 10
 *                       M：1 0 X 9 8 7 6 5 4 3 2
 * 给定一些身份证号码，验证校验码的有效性，并输出有问题的号码。
 *
 * 示例 1：
 *   输入：
 *   4
 *   320124198808240056
 *   12010X198901011234
 *   110108196711301866
 *   37070419881216001X
 *   输出：
 *   12010X198901011234
 *   110108196711301866
 *   37070419881216001X
 *   解释：
 *   第一个号码校验通过，后三个号码校验失败
 *
 * 示例 2：
 *   输入：
 *   2
 *   320124198808240056
 *   110108196711301862
 *   输出：
 *   All passed
 *   解释：
 *   两个号码都校验通过
 *
 * 提示：
 *   - 只检查前17位是否全为数字且最后1位校验码计算准确
 *   - 不检验前17位是否合理
 *   - 如果所有号码都正常，则输出All passed
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

int main()
{
    const array<char, 11> arr = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    const array<int, 17> weights = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    int n;
    cin >> n;
    bool f = true;
    while (n--)
    {
        string id;
        cin >> id;
        bool t = true;
        long long sum = 0, z;
        for (int i = 0; i < 17; i++)
        {
            if (!isdigit(id[i]))
            {
                t = false;
                break;
            }
            sum += (id[i] - '0') * weights[i];
        }
        z = sum % 11;
        if (id[17] != arr[z])
        {
            t = false;
        }
        if (!t)
        {
            f = false;
            cout << id << endl;
        }
    }
    if (f)
    {
        cout << "All passed" << endl;
    }
    return 0;
}