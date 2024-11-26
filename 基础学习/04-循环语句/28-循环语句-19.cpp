/*
描述
    输入一个正整数n，然后输入n个整数，输出这n个整数中大于10的数字的个数和总和

输入
    一个正整数n，然后是n个整数

输出
    这n个整数中所有大于10的数字的个数以及大于10的数字的总和，两个数字中间用空格相隔，不要换行

样例输入
    3
    12 5 20

样例输出
    2 32
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int i = 0;
    
    while (n--)
    {
        int m;
        cin >> m;
        

        if (m > 10)
        {
            i++;
            sum += m;
        }
        
    }
    
    cout << i << " " << sum;

    return 0;
}