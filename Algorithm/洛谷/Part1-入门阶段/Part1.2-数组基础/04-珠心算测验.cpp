/*https://www.luogu.com.cn/problem/P2141*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int count = 0;
    bool found[10001] = {false};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                int sum = a[i] + a[j];
                for (int k = 0; k < n; k++)
                {
                    if (a[k] == sum && k != i && k != j && !found[sum])
                    {
                        count++;
                        found[sum] = true;  
                        break;
                    }
                }
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}