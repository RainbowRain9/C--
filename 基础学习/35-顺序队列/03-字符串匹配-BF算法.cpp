/*
问题描述
给定两个串S="s1s2…sn" 和T="t1t2…tm"，在主串S中查找子串T，返回T第一次出现在S中的位置。
限用BF算法。

输入描述
两个字符串，S和T（均非空串，也不含任何空白符）

输出描述
若存在返回第一次匹配的S的位置，若不存在返回-1。输出后不换行。

样例输入
abcabcacb

abcac

样例输出
3

提示说明
"abcac"出现在"abcabcacb"中第4个位置起（下标为3）。
*/

#include <iostream>
using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;

    int n = S.length();
    int m = T.length();

    for (int i = 0; i <= n - m; i++)
    {
        bool index = true;
        for (int j = 0; j < m; j++)
        {
            if (S[i + j != T[j]])
            {
                index = false;
                break;
            }
        }
        if (index)
        {
            cout << i;
            return 0;
        }
    }
    cour << -1;

    return 0;
}