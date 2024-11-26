/*
问题描述
一个矩阵被称为稀疏矩阵(sparse matrix)，若其元素大部分为0。我们可以用三元组顺序表来表示这样的稀疏矩阵。

例：以下5×4矩阵，
3  0  0  7
0  0 -1  0
2  0  0  0
0  0  0  0
0  0  0 -8

可以用以下的三元组顺序表表示：
其中第1行为矩阵大小（行×列）；
第2行N为矩阵中非零的元素个数；
以后N行为该矩阵的三元组。

5 4    // 矩阵大小
5      // 非零元素个数
1 1 3  // 第1行第1列值为3
1 4 7  // 第1行第4列值为7
2 3 -1 // 第2行第3列值为-1
3 1 2  // 第3行第1列值为2
5 4 -8 // 第5行第4列值为-8

求这样两个矩阵的相加。

输入描述
M+N+3行；其中：
- 第1行有2个数字，为该矩阵的大小（行×列）
- 第2行有1个数字M，为第1个矩阵中非零的数据元素个数；以后M行为这些数据元素的三元组
- 随后的第M+3行有1个数字N，为第2个矩阵中非零的数据元素个数；以后N行为这些数据元素的三元组

可以假设矩阵中的三元组是按照行及列的次序排好序的。M+N不会大于50。

输出描述
K+2行；其中：
- 第1行有2个数字，为相加后矩阵的大小（行×列），以1个空格隔开
- 第2行有1个数字K，为相加后的矩阵中非零的数据元素个数；以后K行为这些数据元素的三元组，数字间均间隔1个空格
每一行最后都要换行。

样例输入
5 4
5
1 1 3
1 4 7
2 3 -1
3 1 2
5 4 -8
2
1 1 2
5 3 6

样例输出
5 4
6
1 1 5
1 4 7
2 3 -1
3 1 2
5 3 6
5 4 -8

提示说明
矩阵1：
3  0  0  7
0  0 -1  0
2  0  0  0
0  0  0  0
0  0  0 -8

加上矩阵2：
2  0  0  0
0  0  0  0
0  0  0  0
0  0  0  0
0  0  6  0

等于：
5  0  0  7
0  0 -1  0
2  0  0  0
0  0  0  0
0  0  6 -8

注意：
1. 两个矩阵都有(1,1)这个数据元素，所以要相加(3+2=5)
2. 若加完后某个数据元素变成0，则应该从三元组中移除
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Triple
{
    int row, col, value;
};

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    int m;
    cin >> m;
    vector<Triple> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].row >> a[i].col >> a[i].value;
    }

    int n;
    cin >> n;
    vector<Triple> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i].row >> b[i].col >> b[i].value;
    }

    vector<Triple> c;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i].row < b[j].row || a[i].row == b[j].row && a[i].col < b[i].col)
        {
            c.push_back(a[i++]);
        }
        else if (a[i].row > b[j].row || a[i].row == b[j].row && a[i].col > b[i].col)
        {
            c.push_back(b[j++]);
        }
        else
        {
            int sum = a[i].value + b[j].value;
            if (sum != 0)
            {
                Triple t = {a[i].row, a[i].col, sum};
                c.push_back(t);
            }
            i++;
            j++;
        }
    }
    while (i < m)
        c.push_back(a[i++]);
    while (j < n)
        c.push_back(b[j++]);

    sort(c.begin(), c.end(), [](const Triple &a, const Triple &b)
         {
        if (a.row != b.row) return a.row < b.row;
        return a.col < b.col; });

    cout << rows << " " << cols << endl;
    cout << c.size() << endl;
    for (const Triple &t : c)
    {
        cout << t.row << " " << t.col << " " << t.value << endl;
    }
    return 0;
}