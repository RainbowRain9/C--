#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    string s;
    cin >> s;

    // 获取字符集
    set<char> charset;
    for (char c : s)
    {
        charset.insert(c);
    }

    // 判断是否有解
    if (charset.size() == 1)
    {
        cout << -1;
        return 0;
    }

    // 构造新字符串
    string t;
    auto it = charset.begin();
    for (char c : s)
    {
        // 如果当前字符相同,选择下一个字符
        if (*it == c)
        {
            it++;
            if (it == charset.end())
            {
                it = charset.begin();
            }
        }
        t += *it;
        it++;
        if (it == charset.end())
        {
            it = charset.begin();
        }
    }

    cout << t;
    return 0;
}