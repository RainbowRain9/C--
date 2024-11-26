/*
描述
补充Boy类和Girl类的定义，这两个类都是Person类的派生类。

#include<iostream>
#include<string>
using namespace std;
enum class Gender { Male, Female };
class Person
{
public:
 string name;
 Gender gender;
 double money;
 void showMoney()
 {
  cout << name << " has $" << money << "." << endl;
 }
 Person(string name, Gender gender) :name(name), gender(gender)
 {
  money = 0;
 }
 void work(double hour, double salaryPerHour)
 {
  money += hour * salaryPerHour;
  cout << name << " has worked " << hour << " hours, earning $" << hour * salaryPerHour << "." << endl;
  showMoney();
 }
};
//Boy类的定义，Boy类是Person类的派生类
//Girl类的定义，Girl类是Person类的派生类
int main()
{
 Boy b("Athlect Goat");
 b.work(30);
 cout << "----------" << endl;

 Girl g1("Wilie");
 g1.work(20);
 g1.shopping(300);
 cout << "----------" << endl;

 Girl g2("Pretty Goat", &b);
 g2.shopping(500);
 cout << "----------" << endl;

 g2.transfer(300);
 return 0;
}


样例输出
Creating a boy named Athlect Goat.
Athlect Goat has worked 30 hours, earning $900.
Athlect Goat has $900.
----------
Creating a girl named Wilie.
Wilie has worked 20 hours, earning $700.
Wilie has $700.
Wilie spends $300 shopping.
Wilie has $400.
----------
Creating a girl named Pretty Goat.
Pretty Goat's boyfriend is Athlect Goat.
Pretty Goat spends $500 shopping, which is paid by Athlect Goat.
Pretty Goat has $0.
Athlect Goat has $400.
----------
Athlect Goat transfers $300 to Pretty Goat.
Pretty Goat has $300.
Athlect Goat has $100.
*/

#include <iostream>
#include <string>
using namespace std;
enum class Gender
{
    Male,
    Female
};
class Person
{
public:
    string name;
    Gender gender;
    double money;
    void showMoney()
    {
        cout << name << " has $" << money << "." << endl;
    }
    Person(string name, Gender gender) : name(name), gender(gender)
    {
        money = 0;
    }
    void work(double hour, double salaryPerHour)
    {
        money += hour * salaryPerHour;
        cout << name << " has worked " << hour << " hours, earning $" << hour * salaryPerHour << "." << endl;
        showMoney();
    }
};
// Boy类的定义，Boy类是Person类的派生类
class Boy : public Person
{
public:
    Boy(string name_) : Person(name_, Gender::Male)
    {
        cout << "Creating a boy named " << name << "." << endl;
    }
    void work(double hour)
    {
        Person::work(hour, 30);
    }
};

// Girl类的定义，Girl类是Person类的派生类
class Girl : public Person
{
    Boy *bf;

public:
    Girl(string name_) : Person(name_, Gender::Female), bf(nullptr)
    {
        cout << "Creating a girl named " << name << "." << endl;
    }
    Girl(string name_, Boy *b) : Person(name_, Gender::Female), bf(b)
    {
        cout << "Creating a girl named " << name << "." << endl;
        cout << name << "'s boyfriend is " << bf->name << "." << endl;
    }
    void work(double hour)
    {
        Person::work(hour, 35);
    }
    void shopping(double spends)
    {
        string strInfo = ".";
        if (bf)
        {
            strInfo = ", which is paid by " + bf->name + ".";
            bf->money -= spends;
        }
        else
        {
            money -= spends;
        }
        cout << name << " spends $" << spends << " shopping" << strInfo << endl;
        showMoney();
        if (bf)
        {
            bf->showMoney();
        }
    }
    void transfer(int s)
    {
        if (bf)
        {
            bf->money -= s;
            this->money += s;
            cout << bf->name << " transfers $" << s << " to " << name << "." << endl;
            this->showMoney();
            bf->showMoney();
        }
    }
};
int main()
{
    Boy b("Athlect Goat");
    b.work(30);
    cout << "----------" << endl;

    Girl g1("Wilie");
    g1.work(20);
    g1.shopping(300);
    cout << "----------" << endl;

    Girl g2("Pretty Goat", &b);
    g2.shopping(500);
    cout << "----------" << endl;

    g2.transfer(300);
    return 0;
}
