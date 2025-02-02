/*
描述
    有一个程序员给自己定了个目标，第1天写1个代码，之后两天（第2、3天）里，
    每天写2个代码；
    之后3天（第4、5、6天）里，每天写3个代码……当连续N天每天写N个代码后，
    程序员会在之后的连续N+1天里，每天写N+1个代码。
    给定一个天数，问从第一天开始的这些天里，程序员一共写了多少个代码。

输入
    第1行是一个正整数n，表示测试案例的数量。
    从第2行到第n+1行，每行有1个正整数，表示天数。

输出
    针对每组测试案例，输出程序员写了多少个代码。
    每组案例输出完都要换行。

样例输入
    1
    3

样例输出
    5
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int day, sum = 0, temp = 1;
        cin >> day;
        while (day >= 1)
        {
            
            for (int j = 1; j <= temp; j++)
            {
                sum += temp;
                day--;
                if (day == 0)
                {
                    break;
                }
            }
            temp++;
        }
        cout << sum;
    }
}