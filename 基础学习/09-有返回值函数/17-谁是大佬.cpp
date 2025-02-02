/*
描述
HX和YY经常互相夸对方是大佬，于是有一天，老徐拿了m根签让HX和YY轮流拿，
HX每次可以任意拿1~a根签，YY每次可以任意拿1~b根签，由HX先拿。
老徐规定，谁拿到了最后一根签，谁就是大佬。
HX十分想让YY当大佬，而YY十分想让HX当大佬，两个人都足够聪明地拿签以尽可能地达到自己的目的。
问：HX是否有合理的拿签方法能够注定让YY当大佬。

输入
1个正整数n，表示测试案例的数量。

每组测试案例中，有3个正整数m、a、b（m<10000, a<100, b<100），
其中m表示签的总数，a表示HX每次可以拿1~a根签，b表示YY每次可以拿1~b根签。

输出
针对每组案例，如果HX注定能让YY当大佬，则输出Yes，否则输出No。
每组案例输出后都要换行。

样例输入
2

10 5 4

6 4 4

样例输出
Yes

No

提示说明
第1组案例中，一共有10根签，HX第一次可以拿3根签，
这样无论接下来YY拿几根签（假设x根），那么HX可以拿6-x根，
这样最后剩一根签注定是YY拿

第2组案例中，一共有6根签，HX第一次无论拿几根签（假设z根），
YY可以拿5-z根，这样最后剩一根签注定是HX拿。
*/

#include<iostream>
using namespace std;
// 引入iostream库，允许使用输入输出流，如cin和cout
// 使用std命名空间，这样可以直接使用cout和cin等，而不需要std::前缀

int main()
{
    int n;
    // 声明一个整数变量n
    cin >> n;
    // 从用户处读取一个整数并存储在变量n中

    for (int i = 0; i < n; i++)
    // 开始一个循环，执行n次
    {
        int m, a, b;
        // 在每次循环中声明三个整数变量m, a, b
        cin >> m >> a >> b;
        // 从用户处读取三个整数并存储在变量m, a, b中

        if (m == 1)
        {
            cout << "No" << endl;
            // 如果m等于1，输出"No"并换行
        }
        else if (a > b)
        {
            cout << "Yes"<<endl;
            // 如果a大于b，输出"Yes"并换行
        }
        else if (a == b)
        {
            if ((m - 1) % (a + 1) == 0)
                cout << "No" << endl;
            // 如果a等于b且(m-1)能被(a+1)整除，输出"No"并换行
            else
            {
                cout << "Yes" << endl;
                // 否则输出"Yes"并换行
            }
        }
        else if (a < b)
        {
            if (a + 1 >= m)
            {
                cout << "Yes"<<endl;
                // 如果a小于b且a+1大于等于m，输出"Yes"并换行
            }
            else
            {
                cout << "No" << endl;
                // 否则输出"No"并换行
            }
        }
    }
    return 0;
}
// 主函数结束，返回0表示程序成功执行
