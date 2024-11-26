/*
描述
输出字符串中的小写字符，但如果一个小写字符不是第一次出现，那么第二次开始起都不要输出。

输入
一个正整数n，表示有n组案例。

每组案例由一个字符串构成。

输出
针对每组案例，输出字符串中的小写字符，但如果一个小写字符不是第一次出现，那么第二次开始起都不要输出。

每组案例输出完都要换行。

样例输入
2

aaBBCccba

aaaaa

样例输出
acb

a
*/

#include <iostream>
using namespace std;

int main()
{
    int n;    // 测试案例的数量
    cin >> n; // 读取测试案例的数量
    while (n--)
    {                                       // 对于每个测试案例
        string a;                           // 定义一个字符串变量a来存储输入的字符串
        cin >> a;                           // 读取输入的字符串
        bool firstAppearance[26] = {false}; // 定义一个布尔数组来跟踪每个小写字母的第一次出现
        // 遍历字符串中的每个字符
        for (int i = 0; i < a.size(); i++)
        {
            if (islower(a[i]))
            {                           // 如果字符是小写字母
                int index = a[i] - 'a'; // 计算字符在字母表中的位置
                if (!firstAppearance[index])
                {                                  // 如果这是该字符的第一次出现
                    cout << a[i];                  // 输出该字符
                    firstAppearance[index] = true; // 标记为已出现
                }
            }
        }
        cout << endl; // 每个测试案例输出后换行
    }
    return 0; // 程序结束
}