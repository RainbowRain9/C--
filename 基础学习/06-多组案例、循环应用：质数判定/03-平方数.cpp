/*
描述
    针对输入的正整数，依次输出从1到该整数每个数字的平方，每个数字之间用一个空格相隔。

    输入
    第1行是一个正整数n，表示测试样例的数量。

    从第2~第n+1行，每行是一个正整数。

输出
    针对每行测试数据，依次输出从1到该整数每个数字的平方，每个数字之间用一个空格相隔，每行最后一个数字后不得有空格。
    每组案例输出完都要换行。

样例输入
    1

    3

样例输出
    1 4 9
*/

#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        for (int j = 1; j <= a; j++)
        {
            cout << j * j;
            if (j < a)
            {
                cout << " ";
            }
            
        }
        cout << endl;
    }
    
    return 0;
}