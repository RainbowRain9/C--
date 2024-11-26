/*
描述
把代码补充完整，以实现要求的输出。

主函数如下：

int main()
{
 Planet p[] = { {"Mercury", 57910000},
  {"Venus", 108200000},
  {"Earth", 149600000},
  {"Mars", 227940000},
  {"Jupiter", 778330000},
  {"Saturn", 1429400000}
 };
 showDistance(p[0], p[2]);
 showDistance(p[2], p[3]);
 return 0;
}


输入
无

输出
以下文字，最后一行后面也要换行。

Mercury's constructor. Distance between Mercury and Sun is 57910000 km.
Venus's constructor. Distance between Venus and Sun is 108200000 km.
Earth's constructor. Distance between Earth and Sun is 149600000 km.
Mars's constructor. Distance between Mars and Sun is 227940000 km.
Jupiter's constructor. Distance between Jupiter and Sun is 778330000 km.
Saturn's constructor. Distance between Saturn and Sun is 1429400000 km.
Distance between Mercury and Earth is 91690000 km.
Distance between Earth and Mars is 78340000 km.

样例输入


样例输出
Mercury's constructor. Distance between Mercury and Sun is 57910000 km.
Venus's constructor. Distance between Venus and Sun is 108200000 km.
Earth's constructor. Distance between Earth and Sun is 149600000 km.
Mars's constructor. Distance between Mars and Sun is 227940000 km.
Jupiter's constructor. Distance between Jupiter and Sun is 778330000 km.
Saturn's constructor. Distance between Saturn and Sun is 1429400000 km.
Distance between Mercury and Earth is 91690000 km.
Distance between Earth and Mars is 78340000 km.
*/

#include <iostream>
#include <string>

using namespace std;

class Planet
{
public:
    string name;
    long long distanceFromSun;

    Planet(string n, long long d) : name(n), distanceFromSun(d) 
    {
        cout << name << "'s constructor. Distance between " << name << " and Sun is " << distanceFromSun << " km." << endl;
    }
};

void showDistance(const Planet &p1, const Planet &p2)
{
    cout << "Distance between " << p1.name << " and " << p2.name <<" is " << p2.distanceFromSun - p1.distanceFromSun << " km." << endl;
}

int main()
{
    Planet p[] = {
        {"Mercury", 57910000},
        {"Venus", 108200000},
        {"Earth", 149600000},
        {"Mars", 227940000},
        {"Jupiter", 778330000},
        {"Saturn", 1429400000}};

    showDistance(p[0], p[2]);
    showDistance(p[2], p[3]);

    return 0;
}
