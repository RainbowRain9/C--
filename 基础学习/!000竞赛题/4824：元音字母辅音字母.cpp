/*
问题描述
英文中的元音字母是A、E、I、O、U（大小写都算），辅音字母是其它21个英文字母（大小写都算）。

输入一个字符，判断这个字符是大写元音字母、小写元音字母、大写辅音字母、小写辅音字母，还是别的字符？

输入描述
一个字符

输出描述
如果字符是大写元音字母，那么输出Upper vowel

如果字符是小写元音字母，那么输出Lower vowel

如果字符是大写辅音字母，那么输出Upper consonant

如果字符是小写辅音字母，那么输出Lower consonant

如果不是上述情况，那么输出Other

输出后不要换行。


样例输入
T

样例输出
Upper consonant
*/

#include <iostream>
using namespace std;

int main()
{
    char ch;
    cin >> ch;
    
    if(ch >= 'A' && ch <= 'Z')
    {
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            cout << "Upper vowel";
        }
        else
        {
            cout << "Upper consonant";
        }
    }
    else if(ch >= 'a' && ch <= 'z')
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            cout << "Lower vowel";
        }
        else
        {
            cout << "Lower consonant";
        }
        
    }
    else
    {
        cout << "Other";
    }
    
    return 0;
}