/*
问题描述
Alice和Bob拿了一堆稻草玩游戏，规定由Alice开始依次轮流拾取一些稻草。每个人每次要么可以拿走一根，要么如果稻草数量是偶数根，还可以选择拿走其中的一半（即如果当前稻草是奇数根，则不能选择拿走一半，只能选择拿走一根）。如果有人拿到了最后一根稻草则获胜。

假设最开始稻草有m根，且Alice和Bob足够聪明，每次都可以做出最正确的选择，那么谁能取胜？

输入描述
一个正整数n，表示案例的数量。（n<=20）

每组案例由一个正整数m组成，表示稻草的初始数量。（m<=100000）

输出描述
针对每组案例，如果Alice获胜，则输出Alice，如果Bob获胜，则输出Bob。

每组案例输出完都要换行。

样例输入
2

1

5

样例输出
Alice

Bob
*/

#include <iostream>
#include <vector>

using namespace std;

string whoWins(int m)
{
    vector<bool> dp(m + 1, false);

    // Base cases
    dp[0] = false; // No straws, current player loses
    dp[1] = true;  // One straw, current player wins

    for (int i = 2; i <= m; i++)
    {
        // Try taking one straw
        if (!dp[i - 1])
        {
            dp[i] = true;
        }
        // Try taking half if even
        else if (i % 2 == 0 && !dp[i / 2])
        {
            dp[i] = true;
        }
        // If both moves lead to opponent's win, current player loses
        else
        {
            dp[i] = false;
        }
    }

    return dp[m] ? "Alice" : "Bob";
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        cout << whoWins(m) << endl;
    }

    return 0;
}