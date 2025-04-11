/*
 * @Author: RainbowRain9
 * @Date: 2025-04-07 19:57:47
 * @LastEditTime: 2025-04-07 20:16:51
 * @FilePath: \C++\Algorithm\PTA\L1-027-出租.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 为给定的11位手机号码生成代码的前两行，其中arr数组包含号码中所有不重复的数字并按递减顺序排列，
 * index数组表示号码中每个数字在arr数组中的索引位置。
 *
 * 示例 1：
 *   输入：18013820100
 *   输出：
 *   int[] arr = new int[]{8,3,2,1,0};
 *   int[] index = new int[]{3,0,4,3,1,0,2,4,3,4,4};
 *   解释：
 *   arr数组包含号码中所有不重复数字并按降序排列
 *   index数组表示号码中每个数字在arr数组中的位置
 *
 * 提示：
 *   - 输入是一个11位的手机号码
 *   - arr数组需要包含号码中所有不重复的数字并按降序排列
 *   - index数组表示号码中每个数字在arr数组中的索引位置
 **************************************************/

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    string number;
    cin >> number;
    unordered_set<int> uniqueDigits;
    for (char c : number) {
        uniqueDigits.insert(c - '0');
    }
    vector<int> arr(uniqueDigits.begin(), uniqueDigits.end());
    sort(arr.rbegin(), arr.rend());
    cout << "int[] arr = new int[]{" << arr[0];
    for (int i = 1; i < arr.size(); i++) {
        cout << "," << arr[i];
    }
    cout << "};" << endl;
    cout << "int[] index = new int[]{";
    bool first = true;
    for (char c : number) {
        int i = c - '0';
        auto it = find(arr.begin(), arr.end(), i);
        if (!first) {
            cout << ",";
        }
        cout << distance(arr.begin(), it);
        first = false;
    }
    cout << "};" << endl;

    return 0;
}