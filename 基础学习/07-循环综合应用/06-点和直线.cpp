/*
描述
    判断一个点是否在一条直线上

输入
    第1行是一个正整数n，表示测试案例的数量
    从第2行到第n+1行，每行有五个数字a、b、c、d、e（不一定是整数，c和d不会都为0），
    其中a和b是点的横坐标和纵坐标，c、d、e构成了一条直线cx+dy=e。

输出
    如果点(a,b)在直线cx+dy=e上，则输出true，否则输出false。
    每组案例输出完都要换行。

样例输入
    1
    1 1 1 1 2

样例输出
    true
*/

#include <iostream>
using namespace std;

int main ()
{
    int n; // 定义变量n，用于存储将要读取的数值组数
    cin >> n; // 从标准输入读取n的值

    // 循环n次，每次处理一组五个浮点数
    for (int i = 0; i < n; i++)
    {
        float a, b, c, d, e; // 定义变量a, b, c, d, e，用于存储每组的数值
        cin >> a >> b >> c >> d >> e; // 从标准输入读取这五个浮点数

        // 计算方程式的左侧 cx + dy 与右侧的 e 之间的差的绝对值
        // 如果差的绝对值小于或等于 1e-6，则认为方程式满足条件
        if (abs(c * a + d * b - e) <= 1e-6)
        {
            cout << "true"; // 如果满足条件，输出true
        }
        else
        {
            cout << "false"; // 如果不满足条件，输出false
        }
        cout << endl; // 输出换行符，确保每组数值的结果是单独一行
    }   
    
    return 0; // 程序结束，返回0
}