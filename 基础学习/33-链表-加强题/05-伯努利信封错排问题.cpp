/*
问题描述
错排问题。欧洲数学家伯努利收到一位朋友的来信，打开一看信不是写给他的，但是信封上的地址、姓名都没有问题。五封信装入写有不同地址和姓名的五个信封，全部装错的可能性有多少种? 设 Fn 表示 n 错排问题，有 F1 = 0，F2 = 1，当 n > 2 时，设第一封信装在第二个信封中，若第二封信装在第一个信封中，则剩下的即为 n-2 错排问题；若第二封信不装在第一个信封中，则剩下的即为 n-1 错排问题，设第一封信装不在第一个信封中，共有 n-1 种方法。

解题思路：有五封信装在五个信封中，每个信封只能装一封信。如果全部装错，即没有一封信装在它应该装的信封里，求有多少种可能性。

这是一个经典的错排问题，可以用递归的方法解决。设 F(n) 表示 n 封信全部错装的可能性，则有：

F(n) = (n-1) [F(n-2) + F(n-1)]

其中，(n-1) 表示第一封信可以放在 n-1 个信封中任意一个，F(n-2) 表示第一封信装在第二个信封中，剩下 n-2 封信全部错装的可能性，F(n-1) 表示第一封信不装在第二个信封中，剩下 n-1 封信全部错装的可能性。

边界条件为 F(1) = 0，F(2) = 1。

输入描述
输入整数信封数。

输出描述
输出全部装错的可能性有多少种。

样例输入
5

样例输出
44

提示说明
最后输出需要换行回车。
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int F[n+1];
    F[1] = 0;
    F[2] = 1;
    
    for(int i = 3; i <= n; i++)
    {
        F[i] = (i-1) * (F[i-2] + F[i-1]);
    }
    
    cout << F[n] << endl;
    
    return 0;
}
