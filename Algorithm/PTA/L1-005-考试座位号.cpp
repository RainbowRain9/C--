/*
 * @Author: RainbowRain9
 * @Date: 2025-04-01 22:50:46
 * @LastEditTime: 2025-04-01 23:04:45
 * @FilePath: \C++\Algorithm\PTA\L1-005-考试座位号.cpp
 * @Description: https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805140211482624
 */
/**************************************************
 * 题目描述：
 * 每个PAT考生有两个座位号：试机座位和考试座位。考生可能迟到，需要根据试机座位号查询考试座位号。
 *
 * 输入格式：
 * 第一行给出正整数N（≤1000），随后N行给出考生信息：准考证号 试机座位号 考试座位号。
 * 接着给出正整数M（≤N），随后一行给出M个待查询的试机座位号码。
 *
 * 输出格式：
 * 对每个查询的试机座位号，输出对应考生的准考证号和考试座位号码，用空格分隔。
 *
 * 示例：
 * 输入：
 * 4
 * 3310120150912233 2 4
 * 3310120150912119 4 1
 * 3310120150912126 1 3
 * 3310120150912002 3 2
 * 2
 * 3 4
 *
 * 输出：
 * 3310120150912002 2
 * 3310120150912119 1
 *
 * 提示：
 * - 准考证号由16位数字组成
 * - 座位号从1到N编号
 * - 每个准考证号唯一
 * - 不会有两个考生被分配到同一个座位
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
    unordered_map<int, pair<string, int>> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int testSeat, examSeat;
        string id;
        cin >> id >> testSeat >> examSeat;
        mp[testSeat] = {id, examSeat};
    }
    int m;
    cin >> m;
    while (m--){
        int a;
        cin >> a;
        cout << mp[a].first << " " << mp[a].second << endl;
    }

    return 0;
}