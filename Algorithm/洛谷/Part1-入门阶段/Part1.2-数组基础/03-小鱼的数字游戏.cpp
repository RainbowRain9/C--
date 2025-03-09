/*https://www.luogu.com.cn/problem/P1427*/

#include <iostream>
using namespace std;

int main()
{
    int a[100];
    int i = 0;
    int n;
    while(cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        
        a[i] = n;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        cout << a[j] << " ";
    }
    

    return 0;
}