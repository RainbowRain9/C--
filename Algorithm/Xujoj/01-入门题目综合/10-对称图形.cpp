/*
问题描述
用一个数字矩阵（二维数组）表示图像，数组每个元素表示图像对应位置像素点的色彩，值相同表示色彩相同。图像有时会是上下对称或者左右对称，也有可能既上下对称也左右对称。

给定一个二维数组，判断其表示图像的对称性。

输入描述
多组案例。

一个正整数n，表示案例的数量。

每组案例中，第一行是正整数a和b，表示二维数组的行数和列数。（a<=10, b<=10）

然后是a行数据，每行数据由b个非负整数组成，表示二维数组每个元素的值，也就是图像在对应位置的色彩。

输出描述
每组案例，如果图像仅是左右对称，那么输出L-R；如果仅是上下对称，那么输出U-D；如果既是左右对称又是上下对称，那么输出Both；如果都不对称，那么输出None。输出后换行。

样例输入
2

2 2

3 5

3 5

2 3

1 2 1

1 2 1

样例输出
U-D

Both
*/

#include <iostream>
#include <vector>
using namespace std;

bool c(const vector<vector<int>> &m)
{
    int rows = m.size();
    int cols = m[0].size();

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols / 2; ++j)
        {
            if (m[i][j] != m[i][cols - 1 - j])
            {
                return false;
            }
        }
    }
    return true;
}

bool d(const vector<vector<int>> &m)
{
    int rows = m.size();
    int cols = m[0].size();

    for (int j = 0; j < cols; ++j)
    {
        for (int i = 0; i < rows / 2; ++i)
        {
            if (m[i][j] != m[rows - 1 - i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n; // 读取案例数量

    while (n--)
    {
        int a, b;
        cin >> a >> b; // 读取行数和列数

        vector<vector<int>> m(a, vector<int>(b));
        for (int i = 0; i < a; ++i)
        {
            for (int j = 0; j < b; ++j)
            {
                cin >> m[i][j]; // 读取矩阵元素
            }
        }

        bool flag1 = c(m);
        bool flag2 = d(m);

        if (flag1 && flag2)
        {
            cout << "Both" << endl;
        }
        else if (flag1)
        {
            cout << "L-R" << endl;
        }
        else if (flag2)
        {
            cout << "U-D" << endl;
        }
        else
        {
            cout << "None" << endl;
        }
    }

    return 0;
}