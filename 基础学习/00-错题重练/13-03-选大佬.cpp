/*
描述
有m个同学围成一圈，编号分别是1、2、...、m，其中编号1的是蔡小佬。
从蔡小佬开始报数，他可以任意选择一个正整数p报数，然后编号2的同学应该报的数字是p+1，编号3的同学应该报p+2，
以此类推，循环报数。规定所有报的数字是7的倍数或者含有数字7的同学会被淘汰出局，已经被淘汰的同学不再参与报数。
这样总会在某个时刻，还留在场上的同学会仅剩下一个，这个同学就能被授予大佬的称号。
蔡小佬很想成为大佬，所以他很小心地选择了一个合理的正整数p，这个数字能够让他最终留在场上。
蔡小佬想要知道，所有能够满足条件的正整数p中，最小的一个会是几。

输入
一个正整数n，表示测试案例的数量。

每组案例的有一个正整数m，表示同学的数量。（m<=1000）

输出
针对每组案例，输出一个整数，表示最小的正整数p。

每组案例输出完要换行。

样例输入
2

2

3

样例输出
2

3
*/

#include<iostream>
using namespace std;

// 函数用于判断报的数是否与7有关，如果有关返回true，无关返回false
bool f(int n) 
{
    while (n != 0)
    {
        if (n % 7 == 0)
        {
            return true;
        }
        n /= 10;
    }
    return false;
}

int main() {
    int n; // 测试案例的数量
    cin >> n; // 读取测试案例的数量
    while (n--) 
    { // 对于每个测试案例
        int m; // 同学的数量
        cin >> m; // 读取同学的数量
        bool* a = new bool[m];
        for (int i = 0; i < m; i++)
        {
            a[i] = true;
        }

        int j = 0, p = 0;
        while (true)
        {
            for (int i = 0; i < m; i++)
            {
                if (a[i])
                {
                    j++;
                    if (f(j))
                    {
                        a[i] = false;
                    }
                }
            }
            int cnt = 0;
            for (int i = 0; i < m; i++)
            {
                if (a[i])
                {
                    cnt++;
                }
            }
            if (a[0] && cnt == 1)
            {
                break;
            }
            if (!a[0])
            {
                p++;
                j = p;
                for (int i = 0; i < m; i++)
                {                   a[i] = true;
                }
                
            }
            
        }
        cout << p + 1 << endl;
    }
    return 0;
}