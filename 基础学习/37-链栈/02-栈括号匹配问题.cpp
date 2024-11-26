// Source : https://xujcoj.com/home/contest/1957/problem/2
// Date   : 2024-11-14

/**************************************************
 * 题目描述：
 * 给定一个只包含括号的字符串，判断括号是否匹配。
 * 括号包括小括号()、中括号[]、大括号{}。
 *
 * 示例 1：
 *   输入：()[]{}
 *   输出：true
 *   解释：括号完全匹配
 *
 * 示例 2：
 *   输入：([)]
 *   输出：false
 *   解释：括号交叉，不匹配
 *
 * 提示：
 *   - 1 <= s.length <= 104
 *   - s 只包含括号字符 '()[]{}'
 **************************************************/

/*
    解题思路：
    1. 使用栈来判断括号是否匹配
    2. 遇到左括号就入栈
    3. 遇到右括号就与栈顶元素匹配
    4. 如果匹配则弹出栈顶元素，不匹配则返回false
    5. 最后栈为空则说明完全匹配

    时间复杂度分析：
    - 只需要遍历一次字符串，时间复杂度为O(n)
    - 使用栈存储左括号，空间复杂度为O(n)
*/

#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                    return false;
                if (c == ')' && st.top() != '(')
                    return false;
                if (c == '}' && st.top() != '{')
                    return false;
                if (c == ']' && st.top() != '[')
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

int main()
{
    Solution s;
    string str;
    cin >> str;

    if (s.isValid(str))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Unbalanced" << endl;
    }

    return 0;
}

