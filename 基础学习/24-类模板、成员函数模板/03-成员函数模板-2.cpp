/*
描述
模仿以下代码中Mage类的写法，写一个Paladin类。

Mage的物理抗性是0，魔法抗性是0.3；Paladin的物理抗性是0.25，魔法抗性是0.1。

Paladin具有两个技能

1、verdict：圣殿骑士的裁决，对敌方造成3000点伤害

2、flash：圣光闪现，对自己治疗1500点

#include<iostream>
#include<string>
using namespace std;
enum DamageType { Physical, Magic, Heal };
class Mage
{
public:
 string name;
 int maxhp, hp;
 double physicalResistance, magicResistance;
 Mage(string name, int hp) :name(name), maxhp(hp), hp(hp)
 {
  physicalResistance = 0;
  magicResistance = 0.3;
 }
 void showIntro()
 {
  cout << name << " HP: " << hp << endl;
 }
 bool isAlive()
 {
  if (hp <= 0)
   return false;
  else
   return true;
 }
 void destroy()
 {
  hp = 0;
  cout << name << " is destroyed." << endl;
 }
 template<typename T> void reduceHP(T &source, int damage, DamageType dt)
 {
  int realDamage = damage;
  if (dt == DamageType::Magic)
  {
   realDamage = (int)(realDamage*(1 - magicResistance) + 0.5);
  }
  else if (dt == DamageType::Physical)
  {
   realDamage = (int)(realDamage*(1 - physicalResistance) + 0.5);
  }
  hp -= realDamage;
  cout << name << " receive " << realDamage << " damage from " << source.name << "." << endl;
  if (!isAlive())
  {
   destroy();
  }
 }
 void increaseHP(int healpoint)
 {
  hp += healpoint;
  if (hp > maxhp)
  {
   hp = maxhp;
  }
 }
 template<typename T> void fireball(T &target)
 {
  attack(target, "Fireball", DamageType::Magic, 1000);
 }
 template<typename T> void pyroblast(T &target)
 {
  attack(target, "Pyroblast", DamageType::Magic, 5000);
 }
 template<typename T> void attack(T &target, string attackname, DamageType dt, int damage)
 {
  cout << name << " casts " << attackname << ", dealing " << damage << " damage to " << target.name << "." << endl;
  target.reduceHP(*this, damage, dt);
 }
};
//Paladin类的定义
int main()
{
 Mage mag("Jiana", 20000);
 Paladin pal("Arthus", 25000);
 mag.showIntro();
 pal.showIntro();
 while (mag.isAlive() && pal.isAlive())
 {
  cout << "----------" << endl;
  if (mag.isAlive())
  {
   mag.fireball(pal);
  }
  if (pal.isAlive())
  {
   pal.flash();
  }
  cout << "----------" << endl;
  mag.showIntro();
  pal.showIntro();
  if (!mag.isAlive() || !pal.isAlive())
  {
   break;
  }
  cout << "----------" << endl;
  if (mag.isAlive())
  {
   mag.pyroblast(pal);
  }
  if (pal.isAlive())
  {
   pal.verdict(mag);
  }
  cout << "----------" << endl;
  mag.showIntro();
  pal.showIntro();
 }
 return 0;
}



输入
无

输出
Jiana HP: 20000
Arthus HP: 25000
----------
Jiana casts Fireball, dealing 1000 damage to Arthus.
Arthus receive 900 damage from Jiana.
Arthus heals Arthus 1500 Points.
----------
Jiana HP: 20000
Arthus HP: 25000
----------
Jiana casts Pyroblast, dealing 5000 damage to Arthus.
Arthus receive 4500 damage from Jiana.
Arthus casts Templar's Verdict, dealing 3000 damage to Jiana.
Jiana receive 3000 damage from Arthus.
----------
Jiana HP: 17000
Arthus HP: 20500
----------
Jiana casts Fireball, dealing 1000 damage to Arthus.
Arthus receive 900 damage from Jiana.
Arthus heals Arthus 1500 Points.
----------
Jiana HP: 17000
Arthus HP: 21100
----------
Jiana casts Pyroblast, dealing 5000 damage to Arthus.
Arthus receive 4500 damage from Jiana.
Arthus casts Templar's Verdict, dealing 3000 damage to Jiana.
Jiana receive 3000 damage from Arthus.
----------
Jiana HP: 14000
Arthus HP: 16600
----------
Jiana casts Fireball, dealing 1000 damage to Arthus.
Arthus receive 900 damage from Jiana.
Arthus heals Arthus 1500 Points.
----------
Jiana HP: 14000
Arthus HP: 17200
----------
Jiana casts Pyroblast, dealing 5000 damage to Arthus.
Arthus receive 4500 damage from Jiana.
Arthus casts Templar's Verdict, dealing 3000 damage to Jiana.
Jiana receive 3000 damage from Arthus.
----------
Jiana HP: 11000
Arthus HP: 12700
----------
Jiana casts Fireball, dealing 1000 damage to Arthus.
Arthus receive 900 damage from Jiana.
Arthus heals Arthus 1500 Points.
----------
Jiana HP: 11000
Arthus HP: 13300
----------
Jiana casts Pyroblast, dealing 5000 damage to Arthus.
Arthus receive 4500 damage from Jiana.
Arthus casts Templar's Verdict, dealing 3000 damage to Jiana.
Jiana receive 3000 damage from Arthus.
----------
Jiana HP: 8000
Arthus HP: 8800
----------
Jiana casts Fireball, dealing 1000 damage to Arthus.
Arthus receive 900 damage from Jiana.
Arthus heals Arthus 1500 Points.
----------
Jiana HP: 8000
Arthus HP: 9400
----------
Jiana casts Pyroblast, dealing 5000 damage to Arthus.
Arthus receive 4500 damage from Jiana.
Arthus casts Templar's Verdict, dealing 3000 damage to Jiana.
Jiana receive 3000 damage from Arthus.
----------
Jiana HP: 5000
Arthus HP: 4900
----------
Jiana casts Fireball, dealing 1000 damage to Arthus.
Arthus receive 900 damage from Jiana.
Arthus heals Arthus 1500 Points.
----------
Jiana HP: 5000
Arthus HP: 5500
----------
Jiana casts Pyroblast, dealing 5000 damage to Arthus.
Arthus receive 4500 damage from Jiana.
Arthus casts Templar's Verdict, dealing 3000 damage to Jiana.
Jiana receive 3000 damage from Arthus.
----------
Jiana HP: 2000
Arthus HP: 1000
----------
Jiana casts Fireball, dealing 1000 damage to Arthus.
Arthus receive 900 damage from Jiana.
Arthus heals Arthus 1500 Points.
----------
Jiana HP: 2000
Arthus HP: 1600
----------
Jiana casts Pyroblast, dealing 5000 damage to Arthus.
Arthus receive 4500 damage from Jiana.
Arthus is destroyed.
----------
Jiana HP: 2000
Arthus HP: 0


样例输入


样例输出
Jiana HP: 20000
Arthus HP: 25000
----------
Jiana casts Fireball, dealing 1000 damage to Arthus.
Arthus receive 900 damage from Jiana.
Arthus heals Arthus 1500 Points.
----------
Jiana HP: 20000
Arthus HP: 25000
----------
Jiana casts Pyroblast, dealing 5000 damage to Arthus.
Arthus receive 4500 damage from Jiana.
Arthus casts Templar's Verdict, dealing 3000 damage to Jiana.
Jiana receive 3000 damage from Arthus.
----------
Jiana HP: 17000
Arthus HP: 20500
----------
Jiana casts Fireball, dealing 1000 damage to Arthus.
Arthus receive 900 damage from Jiana.
Arthus heals Arthus 1500 Points.
----------
Jiana HP: 17000
Arthus HP: 21100
----------
Jiana casts Pyroblast, dealing 5000 damage to Arthus.
Arthus receive 4500 damage from Jiana.
Arthus casts Templar's Verdict, dealing 3000 damage to Jiana.
Jiana receive 3000 damage from Arthus.
----------
Jiana HP: 14000
Arthus HP: 16600
----------
Jiana casts Fireball, dealing 1000 damage to Arthus.
Arthus receive 900 damage from Jiana.
Arthus heals Arthus 1500 Points.
----------
Jiana HP: 14000
Arthus HP: 17200
----------
Jiana casts Pyroblast, dealing 5000 damage to Arthus.
Arthus receive 4500 damage from Jiana.
Arthus casts Templar's Verdict, dealing 3000 damage to Jiana.
Jiana receive 3000 damage from Arthus.
----------
Jiana HP: 11000
Arthus HP: 12700
----------
Jiana casts Fireball, dealing 1000 damage to Arthus.
Arthus receive 900 damage from Jiana.
Arthus heals Arthus 1500 Points.
----------
Jiana HP: 11000
Arthus HP: 13300
----------
Jiana casts Pyroblast, dealing 5000 damage to Arthus.
Arthus receive 4500 damage from Jiana.
Arthus casts Templar's Verdict, dealing 3000 damage to Jiana.
Jiana receive 3000 damage from Arthus.
----------
Jiana HP: 8000
Arthus HP: 8800
----------
Jiana casts Fireball, dealing 1000 damage to Arthus.
Arthus receive 900 damage from Jiana.
Arthus heals Arthus 1500 Points.
----------
Jiana HP: 8000
Arthus HP: 9400
----------
Jiana casts Pyroblast, dealing 5000 damage to Arthus.
Arthus receive 4500 damage from Jiana.
Arthus casts Templar's Verdict, dealing 3000 damage to Jiana.
Jiana receive 3000 damage from Arthus.
----------
Jiana HP: 5000
Arthus HP: 4900
----------
Jiana casts Fireball, dealing 1000 damage to Arthus.
Arthus receive 900 damage from Jiana.
Arthus heals Arthus 1500 Points.
----------
Jiana HP: 5000
Arthus HP: 5500
----------
Jiana casts Pyroblast, dealing 5000 damage to Arthus.
Arthus receive 4500 damage from Jiana.
Arthus casts Templar's Verdict, dealing 3000 damage to Jiana.
Jiana receive 3000 damage from Arthus.
----------
Jiana HP: 2000
Arthus HP: 1000
----------
Jiana casts Fireball, dealing 1000 damage to Arthus.
Arthus receive 900 damage from Jiana.
Arthus heals Arthus 1500 Points.
----------
Jiana HP: 2000
Arthus HP: 1600
----------
Jiana casts Pyroblast, dealing 5000 damage to Arthus.
Arthus receive 4500 damage from Jiana.
Arthus is destroyed.
----------
Jiana HP: 2000
Arthus HP: 0
*/

#include <iostream>
#include <string>
using namespace std;
enum DamageType
{
    Physical,
    Magic,
    Heal
};
class Mage
{
public:
    string name;
    int maxhp, hp;
    double physicalResistance, magicResistance;
    Mage(string name, int hp) : name(name), maxhp(hp), hp(hp)
    {
        physicalResistance = 0;
        magicResistance = 0.3;
    }
    void showIntro()
    {
        cout << name << " HP: " << hp << endl;
    }
    bool isAlive()
    {
        if (hp <= 0)
            return false;
        else
            return true;
    }
    void destroy()
    {
        hp = 0;
        cout << name << " is destroyed." << endl;
    }
    template <typename T>
    void reduceHP(T &source, int damage, DamageType dt)
    {
        int realDamage = damage;
        if (dt == DamageType::Magic)
        {
            realDamage = (int)(realDamage * (1 - magicResistance) + 0.5);
        }
        else if (dt == DamageType::Physical)
        {
            realDamage = (int)(realDamage * (1 - physicalResistance) + 0.5);
        }
        hp -= realDamage;
        cout << name << " receive " << realDamage << " damage from " << source.name << "." << endl;
        if (!isAlive())
        {
            destroy();
        }
    }
    void increaseHP(int healpoint)
    {
        hp += healpoint;
        if (hp > maxhp)
        {
            hp = maxhp;
        }
    }
    template <typename T>
    void fireball(T &target)
    {
        attack(target, "Fireball", DamageType::Magic, 1000);
    }
    template <typename T>
    void pyroblast(T &target)
    {
        attack(target, "Pyroblast", DamageType::Magic, 5000);
    }
    template <typename T>
    void attack(T &target, string attackname, DamageType dt, int damage)
    {
        cout << name << " casts " << attackname << ", dealing " << damage << " damage to " << target.name << "." << endl;
        target.reduceHP(*this, damage, dt);
    }
};
// Paladin类的定义
class Paladin
{
public:
    string name;
    int maxhp, hp;
    double physicalResistance, magicResistance;
    Paladin(string name, int hp) : name(name), maxhp(hp), hp(hp)
    {
        physicalResistance = 0.25;
        magicResistance = 0.1;
    }
    void showIntro()
    {
        cout << name << " HP: " << hp << endl;
    }
    bool isAlive()
    {
        if (hp <= 0)
        {
            return false;
        }
        else
            return true;
    }
    void destory()
    {
        hp = 0;
        cout << name << " is destroyed." << endl;
    }
    template <typename T>
    void reduceHP(T &source, int damage, DamageType dt)
    {
        int realDamage = damage;
        if (dt == DamageType::Magic)
        {
            realDamage = (int)(realDamage * (1 - magicResistance) + 0.5);
        }
        else if (dt == DamageType::Physical)
        {
            realDamage = (int)(realDamage * (1 - physicalResistance) + 0.5);
        }
        hp -= realDamage;
        cout << name << " receive " << realDamage << " damage from " << source.name << "." << endl;
        if (!isAlive())
        {
            destory();
        }
    }
    void increaseHP(int healpoint)
    {
        hp += healpoint;
        if (hp > maxhp)
        {
            hp = maxhp;
        }
    }
    template <typename T>
    void verdict(T &target)
    {
        attack(target, "Templar's Verdict", DamageType::Physical, 3000);
    }
    void flash()
    {
        heal(*this, "Flash of Light", DamageType::Heal, 1500);
    }
    template <typename T>
    void attack(T &target, string attackname, DamageType dt, int damage)
    {
        cout << name << " casts " << attackname << ", dealing " << damage << " damage to " << target.name << "." << endl;
        target.reduceHP(*this, damage, dt);
    }
    template <typename T>
    void heal(T &target, string healname, DamageType dt, int healpoint)
    {
        cout << name << " heals " << target.name << " " << healpoint << " Points." << endl;
        target.increaseHP(healpoint);
    }
};
int main()
{
    Mage mag("Jiana", 20000);
    Paladin pal("Arthus", 25000);
    mag.showIntro();
    pal.showIntro();
    while (mag.isAlive() && pal.isAlive())
    {
        cout << "----------" << endl;
        if (mag.isAlive())
        {
            mag.fireball(pal);
        }
        if (pal.isAlive())
        {
            pal.flash();
        }
        cout << "----------" << endl;
        mag.showIntro();
        pal.showIntro();
        if (!mag.isAlive() || !pal.isAlive())
        {
            break;
        }
        cout << "----------" << endl;
        if (mag.isAlive())
        {
            mag.pyroblast(pal);
        }
        if (pal.isAlive())
        {
            pal.verdict(mag);
        }
        cout << "----------" << endl;
        mag.showIntro();
        pal.showIntro();
    }
    return 0;
}