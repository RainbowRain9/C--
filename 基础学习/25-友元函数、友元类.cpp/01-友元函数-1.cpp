/*
描述
补充代码，把showDistance函数声明为Planet类的友元函数（注释处）

#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Planet
{
private:
 string name;
 int distance;
public:
 Planet(string name, int distance)
 {
  this->name = name;
  this->distance = distance;
 }
 //这里要添加showDistance函数的友元声明
};
void showDistance(Planet &p1, Planet &p2)
{
 cout << "Distance between " << p1.name << " and " << p2.name << " is " << abs(p1.distance - p2.distance) << " km." << endl;
}
int main()
{
 Planet p[] = { { "Mercury", 57910000 },
 { "Venus", 108200000 },
 { "Earth", 149600000 },
 { "Mars", 227940000 },
 { "Jupiter", 778330000 },
 { "Saturn", 1429400000 }
 };
 showDistance(p[0], p[2]);
 showDistance(p[2], p[3]);
 return 0;
}

输入
无

输出
Distance between Mercury and Earth is 91690000 km.
Distance between Earth and Mars is 78340000 km.


样例输入


样例输出
Distance between Mercury and Earth is 91690000 km.
Distance between Earth and Mars is 78340000 km.
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Planet
{
private:
    string name;
    int distance;

public:
    Planet(string name, int distance)
    {
        this->name = name;
        this->distance = distance;
    }
    friend void showDistance(Planet &, Planet &);
};
void showDistance(Planet &p1, Planet &p2)
{
    cout << "Distance between " << p1.name << " and " << p2.name << " is " << abs(p1.distance - p2.distance) << " km." << endl;
}
int main()
{
    Planet p[] = {{"Mercury", 57910000},
                  {"Venus", 108200000},
                  {"Earth", 149600000},
                  {"Mars", 227940000},
                  {"Jupiter", 778330000},
                  {"Saturn", 1429400000}};
    showDistance(p[0], p[2]);
    showDistance(p[2], p[3]);
    return 0;
}