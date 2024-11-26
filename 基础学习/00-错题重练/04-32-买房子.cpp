/*
描述
    某程序员开始工作，年薪a万，他希望在厦门买房子，现在价格是200万，
    假设房子价格以每年百分之b的速度增长，并且该程序员未来年薪不变，
    且不吃不喝，不用交税，
    每年所得a万全都积攒起来，问是否能在20年之内买下这套房子？
    如果可以，那么第几年能够买下这套房子？（第一年年薪a万，房价200万）

输入
    一个正整数n，表示案例的数量。
    每组案例由两个正整数a和b组成（10<=a<=50, 1<=b<=20)

输出
    如果在第20年或者之前就能买下这套房子，则输出一个整数M，表示最早需要在第M年能买下，否则输出No。
    每组案例输出完都要换行。

样例输入
    1
    50 10

样例输出
    8
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        float b;
        cin >> a >> b;
        int house = 200, money = a;
        for (int i = 0; i < 20; i++)
        {
            house *= (1 + b / 100);
            money = a * (i + 2);
            if (money >= house)
            {
                cout << i + 2 << endl;
                break;
            }
            if (i == 20)
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
