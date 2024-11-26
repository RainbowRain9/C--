/*
描述
编写函数bool f(int m)，当m能被3、5、7中任意一个数字整除时，返回true，
否则返回false，然后在主函数中利用这个函数输出a~b之间能被3、5、7中任意一个数字整除的数字总个数。

输入
一个正整数n，表示n组案例。

每组案例由两个整数a和b构成。（a<=b）

输出
针对每组案例，输出a到b之间（包括a和b）能被3、5、7中任意一个数字整除的数字总个数。

每组案例输出完都要换行。

样例输入
1

2 10

样例输出
6
*/

#include <iostream>
using namespace std;
bool f(int m){
    if (m % 3 == 0) return true;
    if (m % 5 == 0) return true;
    if (m % 7 == 0) return true;
    return false;
}
int main ()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        int temp = 0;
        cin >> a >> b;
        for (int i = a; i <= b; i++)
        {
            if (f(i))
            {
                temp++;
            }
            
        }
        cout << temp << endl;
    }
    
    return 0;
}