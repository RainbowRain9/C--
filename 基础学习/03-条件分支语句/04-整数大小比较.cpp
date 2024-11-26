/*
描述
    输入两个整数，比较它们的大小

输入
    两个整数x和y

输出
    如果x大于y，输出 >
    如果x等于y，输出 =
    如果x小于y，输出 <

样例输入
    3 5

样例输出
    <
*/

#include <iostream>
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;
    if (x > y)
    {
        cout << ">";
    }
    else if (x < y)
    {
        cout << "<";
    }
    else
    {
        cout << "=";
    }
    return 0;
}