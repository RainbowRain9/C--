/*
 * @Author: RainbowRain9
 * @Date: 2025-04-08 23:08:59
 * @LastEditTime: 2025-04-09 13:16:52
 * @FilePath: \C++\Algorithm\PTA\L1-048-矩阵A乘以B.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 给定两个矩阵A和B，要求计算它们的乘积矩阵AB。需要注意的是，只有规模匹配的矩阵才可以相乘。
 * 即若A有Ra行、Ca列，B有Rb行、Cb列，则只有Ca与Rb相等时，两个矩阵才能相乘。
 *
 * 输入格式：
 * 输入先后给出两个矩阵A和B。对于每个矩阵，首先在一行中给出其行数R和列数C，
 * 随后R行，每行给出C个整数，以1个空格分隔，且行首尾没有多余的空格。
 *
 * 输出格式：
 * 若输入的两个矩阵的规模是匹配的，则按照输入的格式输出乘积矩阵AB，
 * 否则输出Error: Ca != Rb，其中Ca是A的列数，Rb是B的行数。
 *
 * 示例 1：
 *   输入：
 *   2 3
 *   1 2 3
 *   4 5 6
 *   3 4
 *   7 8 9 0
 *   -1 -2 -3 -4
 *   5 6 7 8
 *   输出：
 *   2 4
 *   20 22 24 16
 *   53 58 63 28
 *   解释：
 *   矩阵A(2×3)与矩阵B(3×4)相乘，得到结果矩阵(2×4)
 *
 * 示例 2：
 *   输入：
 *   3 2
 *   38 26
 *   43 -5
 *   0 17
 *   3 2
 *   -11 57
 *   99 68
 *   81 72
 *   输出：
 *   Error: 2 != 3
 *   解释：
 *   矩阵A的列数(2)不等于矩阵B的行数(3)，无法相乘
 *
 * 提示：
 *   - 矩阵的行列数都是正整数
 *   - 矩阵元素的绝对值不超过100
 *   - 注意矩阵乘法的规则：C[i][j] = Σ(A[i][k] * B[k][j])
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
// TODO 2025-04-09: 二维矩阵
using namespace std;

vector<vector<int>> readMatrix(int rows, int cols)
{
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

void printMatrix(const vector<vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty()) {
        return;
    }
    int rows = matrix.size();
    int cols = matrix[0].size();
    cout << rows << " " << cols << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << (j == cols - 1 ? "" : " ");
        }
        cout << endl;
    }
}

int main()
{
    int Ra, Ca, Rb, Cb;
    cin >> Ra >> Ca;
    vector<vector<int>> A = readMatrix(Ra, Ca);

    cin >> Rb >> Cb;
    vector<vector<int>> B = readMatrix(Rb, Cb);

    if (Ca != Rb) {
        cout << "Error: " << Ca << " != " << Rb << endl;
    } else {
        vector<vector<int>> C(Ra, vector<int>(Cb, 0));

        for (int i = 0; i < Ra; ++i) {
            for (int j = 0; j < Cb; ++j) {
                for (int k = 0; k < Ca; ++k) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        printMatrix(C);
    }

    return 0;
}