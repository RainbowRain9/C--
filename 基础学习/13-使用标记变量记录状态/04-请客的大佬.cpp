/*
描述
HX要请同学吃饭，询问他们哪天有空，想找到一个大家都有空的时候请客。
输入
1个正整数n，表示测试案例的数量。

每组测试案例中，先是一个正整数m，表示同学的人数；然后是m行字符串，代表每个同学的空闲情况；
每个字符串有7个字符，由Y和N构成，分别表示星期一到星期日是否有空，Y表示有空，N表示没空。

输出
针对每组案例，如果能至少找到一天所有同学都有空的，则输出Yes，否则输出No。每组案例输出后都要换行。

样例输入
2

2

YYYYNNN

NNNNYYY

2

YYYYYNN

NNNYYYY

样例输出
No

Yes
*/

#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        int a[8] = {0};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                char ch;
                cin >> ch;
                if (ch == 'Y')
                {
                    a[j]++;
                }
            }
        }
        bool flag = false;
        for (int i = 0; i < 7; i++)
        {
            if (a[i] == m)
            {
                flag = true;
            }
        }
        if (flag)
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
        cout << endl;
    }
    
    return 0;
}