/*
描述
编写日期类Date，可以保存一个日期的年、月、日信息

成员函数isLeapYear()，用于判断当前年份是否闰年，如果是闰年则返回true，如果不是闰年则返回false。

成员函数void decrease(int a)，用于把当前日期往回减a天，例如当前日期是2019.3.4，则调用decrease(3)就变成了2019.3.1。

成员函数void increase(int a)，用于把当前日期变后a天，例如当前日期是2019.3.4，则调用increase(3)就变成了2019.3.7。

成员函数void display()，用于显示当前日期，以及当前日期是所在年份的第几天，例如当前日期是2019.3.4，则应该显示2019 3 4 63，最后的63表示2019.3.4是2019年的第63天。

主函数是：

int main()
{
 int n;
 cin >> n;
 while (n--)
 {
  int year, month, day, a;
  cin >> year >> month >> day >> a;
  Date d(year, month, day);
  if (d.isLeapYear())
  {
   d.decrease(a);
  }
  else
  {
   d.increase(a);
  }
  d.display();
 }
 return 0;
}


输入
一个正整数n，表示有n组案例。

每组案例先是3个正整数，表示年、月、日，组成的日期保证是合法的；然后是一个正整数a，表示调整的天数。

输出
针对每组案例，如果当前年份是闰年，则调用decrease成员函数把当前日期往回减a天；如果当前年份不是闰年，则调用increase成员函数把当前日期变后a天。然后调用display成员函数输出当前日期，以及当前日期是所在年份的第几天。

样例输入
2

2019 3 4 3

2020 3 4 3

样例输出
2019 3 7 66

2020 3 1 61
*/

#include <iostream>
#include <string>
using namespace std;
int dayLeapYear[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dayComYear[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date
{
private:
    int year;
    int day;
    int month;

public:
    bool isLeapYear()
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    void decrease(int a)
    {
        while (a--)
        {
            if (day == 1)
            {
                if (month == 1)
                {
                    month = 12;
                    year -= 1;
                }
                else
                {
                    month -= 1;
                }
                day = isLeapYear() ? dayLeapYear[month - 1] : dayComYear[month - 1];
            }
            else
            {
                day -= 1;
            }
        }
    }

    void increase(int a)
    {
        while (a--)
        {
            int monthDay = isLeapYear() ? dayLeapYear[month - 1] : dayComYear[month - 1];
            if (day == monthDay)
            {
                if (month == 12)
                {
                    month = 1;
                    year += 1;
                }
                else
                {
                    month += 1;
                }
                day = 1;
            }
            else
            {
                day += 1;
            }
        }
    }

    void display()
    {
        int days = 0;
        int *pDays = isLeapYear() ? dayLeapYear : dayComYear;
        for (size_t i = 0; i < month - 1; i++)
        {
            days += pDays[i];
        }
        days += day;
        cout << year << " " << month << " " << day << " " << days << endl;
    }
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
};

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int year, month, day, a;
        cin >> year >> month >> day >> a;
        Date d(year, month, day);
        if (d.isLeapYear())
        {
            d.decrease(a);
        }
        else
        {
            d.increase(a);
        }
        d.display();
    }
    return 0;
}