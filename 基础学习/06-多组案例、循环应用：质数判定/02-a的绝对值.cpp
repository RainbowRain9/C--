/*
描述
    输出数字a的绝对值

输入
    第1行是一个正整数n，表示测试样例的数量。

    从第2~第n+1行，每行一个数字

输出
    针对每行测试数据，输出这个数字的绝对值，以换行符相隔。

样例输入
    2
    -1
    3.5

样例输出
    1
    3.5

提示说明
    需要包含cmath头文件
*/

#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        float a;
        cin >> a;
        cout << abs(a) << endl;
    }
    
    return 0;
}