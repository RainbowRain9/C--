/*
描述
    输入m，输出2到m之间（包含2和m）所有素数之和。

输入
    一个正整数n，表示测试案例的数量。
    每组案例中有一个正整数m。

输出
    针对每组案例，输出一个整数，表示2到m之间（包含2和m）所有素数之和。每组案例输出完都要换行。

样例输入
    2
    5
    10

样例输出
    10
    17

提示说明
    2到5之间素数的和是2+3+5=10
    2到10之间素数的和是2+3+5+7=17
*/

#include <iostream>
using namespace std;
bool isPrime(int j) {
    if (j <= 1) return false;
    if (j == 2) return true;
    if (j % 2 == 0) return false;
    for (int i = 3; i * i <= j; i += 2)
    {
        if (j % i == 0) return false;
    }
    return true;
}

int main ()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        int sum = 0;
        for (int j = 2; j <= m; j++)
        {
            if (isPrime(j))
            {
                sum += j;
            }
            
        }
        cout << sum << endl;
    }
    
    return 0;
}