/*
问题描述
人类对于声音频率的听觉范围是20~20000Hz（包括20和20000），现在来了五种不同的动物，分别发出一段具有固定频率的声音。求这五段声音中，人能听到的频率最低和最高的声音频率。

输入描述
只有一组案例。

5个正整数，分别表示五种动物分别发出的声音频率。

输出描述
两个整数，分别代表人能听到的声音中的最低频率和最高频率，中间留一个空格。

如果所有声音人都听不到，则输出-1。

不要换行。

样例输入
样例1：

1 2 3 4 5

样例2：

30 40 1000 100000 2

样例输出
样例1：

-1

样例2：

30 1000
*/

#include <iostream>
using namespace std;

int main()
{
    int a[5];
    int min = 200001;
    int max = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
        if (a[i] >= 20 && a[i] <= 20000)
        {
            if(min > a[i]) min = a[i];
            if(max < a[i]) max = a[i];
        }
    }
    if (min == 200001 && max == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << min << " " << max << endl;
    }
    

    return 0;
}