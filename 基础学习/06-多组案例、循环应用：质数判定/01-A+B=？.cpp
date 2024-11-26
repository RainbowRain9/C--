/*
描述
    输出两个整数的和

输入
    第1行是一个正整数n，表示测试样例的数量。

    从第2~第n+1行，每行为一组测试数据，包含两个整数，用空格相隔。

输出
    针对每行测试数据，输出这行两个整数的和，以换行符相隔。

样例输入
    2
    1 2
    3 4

样例输出
    3
    7
*/

#include <iostream>
using namespace std;
int main ()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    
    return 0;
}