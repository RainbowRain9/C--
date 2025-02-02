/*
描述
为了确定参加嘉庚学院15周年庆的代表，有m个编号为1~m的学生参与了一场投票活动，
他们总共收到了p张投票，每张投票上有一个数字a（1~m之间），表示推荐编号是a的学生参加15周年校庆。

如果一个学生得到了3张或者3张以上的投票推荐，那么就有资格参加校庆。问有多少人有资格参加校庆？

输入
一个正整数n，表示案例的数量。

每组案例中，先是两个正整数m和p（m<=3000000，p<=5000000），然后是p个数字a1~ap（1~m之间）。

输出
针对每组案例，输出一个整数，表示有资格参加校庆的人数。

每组案例输出后都要换行。

样例输入
2

3 5

1 1 2 2 3

3 9

1 1 1 2 2 2 2 3 3

样例输出
0

2

提示说明
注意内存限制
*/

#include <iostream>

using namespace std;

int main()
{
    int t;    // 存储案例的数量
    cin >> t; // 输入案例的数量

    while (t--)
    {             // 对于每个案例
        int m, p; // 分别存储学生数量和投票数量
        cin >> m >> p;

        // 创建大小为 m 的整型数组，所有元素初始为0
        int votes[m] = {0}; // 注意这里的大小是m，而不是m+1

        for (int i = 0; i < p; ++i)
        { // 遍历所有的投票
            int a;
            cin >> a; // 输入投票号码
            // 由于数组是从0开始的，我们需要将投票号码a减1
            votes[a - 1]++; // 增加对应学生的得票数
        }

        int qualified = 0; // 统计有资格参加校庆的学生数量
        for (int i = 0; i < m; ++i)
        {                      // 遍历所有学生，注意这里的循环是从0开始的
            if (votes[i] >= 3) // 如果得票数大于等于3
                qualified++;   // 增加有资格的学生数量
        }

        cout << qualified << endl; // 输出有资格参加校庆的学生数量，并换行
    }

    return 0; // 程序结束
}