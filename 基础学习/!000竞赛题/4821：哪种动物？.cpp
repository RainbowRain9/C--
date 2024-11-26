/*
问题描述
涂涂养了5种动物：狮子、鹰、蚂蚁、蜘蛛、蜈蚣。

蜈蚣的腿的数量是奇数对，通常在15到191对之间‌。其他动物的腿的数量，养过的同学应该都知道。（都不建议在学校里养）

现在已知某一只动物的腿的数量，问这只动物是上述5种中的哪一种？

输入描述
一个正整数，表示某一只动物的腿的数量。

输出描述
如果是狮子，那么输出Lion

如果是鹰，那么输出Eagle

如果是蚂蚁，那么输出Ant

如果是蜘蛛，那么输出Spider

如果是蜈蚣，那么输出Centipede

如果不是以上5种动物，那么输出None

以上所有情况的输出都不要换行

样例输入
30

样例输出
Centipede
*/

#include <iostream>
using namespace std;

int main()
{
    int legs;
    cin >> legs;
    int aPairLegs = legs / 2;
    if (legs == 4)
    {
        cout << "Lion";
    }
    else if (legs == 2)
    {
        cout << "Eagle";
    }
    else if (legs == 6)
    {
        cout << "Ant";
    }
    else if (legs == 8)
    {
        cout << "Spider";
    }
    else if (legs % 2 == 0 && aPairLegs % 2 == 1 && aPairLegs >= 15 && aPairLegs <= 191)
    {
        cout << "Centipede";
    }
    else
    {
        cout << "None";
    }
    return 0;
}