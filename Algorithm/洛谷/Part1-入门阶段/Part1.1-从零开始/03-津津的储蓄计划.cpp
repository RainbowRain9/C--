/*https://www.luogu.com.cn/problem/P1089*/

#include <iostream>
using namespace std;

int main()
{
    int money = 0;
    int month = 0;
    int sum = 0;
    for (int i = 1; i <= 12; i++)
    {
        money += 300;
        int n;
        cin >> n;
        money -= n;
        int temp = money / 100;
        if (temp > 0)
        {
            sum += 100 * temp;
            money -= 100 * temp;
        }
        if (money < 0)
        {
            month = -i;
            break;
        }
    }
    if (month != 0)
    {
        cout << month << endl;
    }
    else
    {
        cout << money + sum * 1.2 << endl;
    }

    return 0;
}
