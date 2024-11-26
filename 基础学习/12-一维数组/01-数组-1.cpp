/*
描述
把一些整数存放在数组中，然后再输出出来

输入
只有一组案例，有5个整数。

输出
把这5个整数先存到一个数组里，然后再输出出来，每个整数输出后都要换行。

样例输入
1 2 3 4 5

样例输出
1

2

3

4

5
*/

#include <iostream>
using namespace std;
int main()
{
    int a[5];
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<5;i++)
    {
        cout<<a[i];
        cout<<endl;
    }
    
    return 0;
}