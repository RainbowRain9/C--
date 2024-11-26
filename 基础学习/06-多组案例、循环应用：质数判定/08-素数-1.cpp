/*
描述
    输入n个数字，输出其中所有素数的和

输入
    一个正整数n，

    然后是n个正整数。

输出
    一个整数，表示n个正整数中所有素数的和。不要换行。

样例输入
    5 2 3 4 5 6

样例输出
    10

提示说明
    2+3+5=10

*/

#include <iostream>
using namespace std;
bool isPrime(int m){
    if (m == 2) return true;
    if (m <= 1) return false;
    if (m % 2 == 0) return false;
    for (int i = 3; i * i <= m; i += 2)
    {
        if (m % i == 0) return false;
    }
    return true;
    
}

int main ()
{
    int n, sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        
        if (isPrime(m))
        {
            sum += m;
        }
        
    }
    cout << sum;
    
    return 0;
}