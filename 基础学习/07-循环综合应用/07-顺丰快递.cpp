/*
描述
    根据邮件的重量和用户是否选择加急计算邮费。
    计算规则：重量在2000克以内（包括2000克），基本费10元。
    超过2000克的部分，每500克加收超重费3元，不足500克部分按500克计算；
    如果用户选择加急，多收8元。

输入
    第1行是一个正整数n，表示测试案例的数量
    从第2行到第n+1行，每行有1个正整数和1个字符，其中正整数表示邮件的重量，
    字符只可能是y或者n，如果是y，表示加急，如果是n，表示不加急。

输出
    针对每组测试案例，输出邮费。
    每组案例输出完都要换行。

样例输入
    1
    2300 y

样例输出
    21
*/

#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, prise = 10;
        char b;
        cin >> a >> b;
        if (b == 'y') 
        {
            prise += 8;
            if (a <= 2000)
            {
                cout << prise;
            }
            else
            {
                prise += (a - 2000) / 500 * 3;
                if ((a - 2000) % 500 != 0) prise += 3;
                cout << prise;
            }
        }
        if (b == 'n') 
        {
            if (a <= 2000)
            {
                cout << prise;
            }
            else
            {
                prise += (a - 2000) / 500 * 3;
                if ((a - 2000) % 500 != 0) prise += 3;
                cout << prise;
            }
        }
        cout << endl;
    }
    
    return 0;
}