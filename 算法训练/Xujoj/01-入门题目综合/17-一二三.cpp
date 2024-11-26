/*
问题描述
小调发现，可以找出3个三位数，它们的大小比例是1：2：3，并且这3个三位数各个位置上一共9个数字都没有重复。

找到所有满足条件的数字。

输入描述
无

输出描述
按照从小到大的顺序，输出所有满足这样条件的3个三位数。

每组3个三位数两两之间都有一个空格字符，每组输出完都要换行。

样例输入


样例输出
192 384 576

219 438 657

...后面看不见了
*/

#include <iostream>

using namespace std;

int main()
{
    for (int a = 100; a <= 333; a++)
    {
        int b = 2 * a;
        int c = 3 * a;

        if (c > 999)
            break; 


        bool digits[10] = {false};
        int temp = a;
        while (temp > 0)
        {
            if (digits[temp % 10])
                goto next;
            digits[temp % 10] = true;
            temp /= 10;
        }
        
        temp = b;
        while (temp > 0)
        {
            if (digits[temp % 10])
                goto next;
            digits[temp % 10] = true;
            temp /= 10;
        }
        temp = c;
        while (temp > 0)
        {
            if (digits[temp % 10])
                goto next;
            digits[temp % 10] = true;
            temp /= 10;
        }

        cout << a << " " << b << " " << c << endl;

    next:
        continue;
    }
    return 0;
}
