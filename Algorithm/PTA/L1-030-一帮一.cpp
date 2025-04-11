/*
 * @Author: RainbowRain9
 * @Date: 2025-04-07 20:32:28
 * @LastEditTime: 2025-04-07 21:19:44
 * @FilePath: \C++\Algorithm\PTA\L1-030-一帮一.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * "一帮一学习小组"是中小学中常见的学习组织方式，老师把学习成绩靠前的学生跟学习成绩靠后的学生排在一组。
 * 本题要求编写程序帮助老师自动完成这个分配工作，即在得到全班学生的排名后，在当前尚未分组的学生中，
 * 将名次最靠前的学生与名次最靠后的异性学生分为一组。
 *
 * 输入格式：
 * 第一行给出正偶数N（≤50），即全班学生的人数。
 * 此后N行，按照名次从高到低的顺序给出每个学生的性别（0代表女生，1代表男生）和姓名（不超过8个英文字母的非空字符串），
 * 其间以1个空格分隔。保证本班男女比例是1:1，并且没有并列名次。
 *
 * 输出格式：
 * 每行输出一组两个学生的姓名，其间以1个空格分隔。名次高的学生在前，名次低的学生在后。
 * 小组的输出顺序按照前面学生的名次从高到低排列。
 *
 * 示例 1：
 *   输入：
 *   8
 *   0 Amy
 *   1 Tom
 *   1 Bill
 *   0 Cindy
 *   0 Maya
 *   1 John
 *   1 Jack
 *   0 Linda
 *   输出：
 *   Amy Jack
 *   Tom Linda
 *   Bill Maya
 *   Cindy John
 *
 * 提示：
 *   - 输入学生人数为正偶数且不超过50
 *   - 男女学生人数相等
 *   - 学生姓名不超过8个英文字母
 *   - 输出时名次高的学生在前，名次低的学生在后
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
// TODO 2025-04-07: 
using namespace std;

struct Student {
    bool sex;
    string name;
    bool paired;
};

int main()
{
    int n;
    cin >> n;
    vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        cin >> students[i].sex >> students[i].name;
        students[i].paired = false;
    }

    for (int i = 0; i < n; i++) {
        if (students[i].paired)
            continue;

        for (int j = n - 1; j > i; j--) {
            if (!students[j].paired && students[j].sex != students[i].sex) {
                cout << students[i].name << " " << students[j].name << endl;
                students[i].paired = students[j].paired = true;
                break;
            }
        }
    }

    return 0;
}