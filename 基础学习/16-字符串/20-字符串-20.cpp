/*
描述
输入一个字符串，统计字符串中各英文字母出现的次数（大小写视为相同字母），
输出出现次数最多的字母（以大写字母形式）以及出现次数，
如果有多个字母出现次数并列第一，则先按字母表顺序输出并列第一的所有字母，再输出出现次数。


输入
一个正整数n，表示n组案例。

每组案例由一个字符串构成。

输出
针对每组案例中的字符串，出现次数最多的字母（以大写字母形式）以及出现次数，
如果有多个字母出现次数并列第一，则先按字母表顺序输出并列第一的所有字母，再输出出现次数。

字母和字母之间，字母和数字之间都用一个空格相隔。

每组案例输出完要换行。



样例输入
1

a555bBC#C&

样例输出
B C 2
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;    // 测试案例的数量
    cin >> n; // 读取测试案例的数量
    while (n--)
    {                        // 对于每个测试案例
        string s;            // 定义一个字符串变量s来存储输入的字符串
        cin >> s;            // 读取输入的字符串
        int count[26] = {0}; // 定义一个整数数组count，用于跟踪每个字母的出现次数

        // 遍历字符串中的每个字符，并统计字母的出现次数
        for (char c : s)
        {
            if (isalpha(c))
            {                     // 检查字符是否为字母
                c = toupper(c);   // 转换为大写
                count[c - 'A']++; // 增加对应字母的出现次数
            }
        }

        // 初始化出现次数最多的字母和次数
        int maxCount = 0;
        char maxLetters[26] = {0}; // 存储出现次数最多的字母
        int maxLettersCount = 0;   // 出现次数最多的字母的数量

        // 找出出现次数最多的字母
        for (int i = 0; i < 26; i++)
        {
            if (count[i] > maxCount)
            {
                maxCount = count[i];
                maxLettersCount = 1;     // 重置为1，因为找到了新的最大次数
                maxLetters[0] = 'A' + i; // 存储字母
            }
            else if (count[i] == maxCount)
            {
                // 如果有多个字母出现次数相同且最多，添加到maxLetters数组中
                maxLetters[maxLettersCount++] = 'A' + i;
            }
        }

        // 按字母表顺序输出出现次数最多的字母及其次数
        for (int i = 0; i < maxLettersCount; i++)
        {
            cout << maxLetters[i] << " ";
        }
        cout << maxCount << endl; // 输出次数，并换行
    }
    return 0; // 程序结束
}