/*
描述
    老王卖西瓜有个习惯，每天都是自己先吃一个瓜，再卖掉剩下的一半。
    从第1天开始卖到第n天，在第n天的时候，老王按照惯例自己吃了一个瓜，然后发现瓜没了。
    求一开始的时候老王有几个瓜？

输入
    1个正整数n，表示天数

输出
    最开始的时候瓜的数量

样例输入
    2

样例输出
    3
*/

#include <iostream>
using namespace std;

int main ()
{
    int n;
    int i = 0;
    cin >> n;
    while (n--)
    {
        i = i * 2 + 1;
    }
    cout << i;

    return 0;
}