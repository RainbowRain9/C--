/*
描述
定义一个MyString类，用于提取字符串中的数字字符、大写字母字符和小写字母字符。

主函数如下：

int main()
{
 string s;
 cin >> s;
 MyString ms(s);
 cout << ms.f1() << endl; //输出字符串中所有的数字字符
 cout << ms.f2() << endl; //输出字符串中所有的大写字母字符
 cout << ms.f3() << endl; //输出字符串中所有的小写字母字符
 return 0;
}


输入
只有一组案例。

一个字符串s。

输出
3个字符串：字符串中所有的数字字符、字符串中所有的大写字母字符、字符串中所有的小写字母字符

每个字符串输出完都要换行。


样例输入
aPd31%E2a

样例输出
312
PE
ada
*/

#include <iostream>
using namespace std;
class MyString
{
private:
    string s;

public:
    MyString(string _s) : s(_s) {}
    string f1()
    {
        string str;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                str += s[i];
            }
        }
        return str;
    }

    string f2()
    {
        string str;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (isupper(s[i]))
            {
                str += s[i];
            }
        }
        return str;
    }

    string f3()
    {
        string str;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (islower(s[i]))
            {
                str += s[i];
            }
        }
        return str;
    }
};
int main()
{
    string s;
    cin >> s;
    MyString ms(s);
    cout << ms.f1() << endl; // 输出字符串中所有的数字字符
    cout << ms.f2() << endl; // 输出字符串中所有的大写字母字符
    cout << ms.f3() << endl; // 输出字符串中所有的小写字母字符
    return 0;
}