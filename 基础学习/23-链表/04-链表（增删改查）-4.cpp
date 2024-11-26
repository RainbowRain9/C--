/*
描述


补充完整代码，实现一个链表类Link，用于按照学号从小到大的结点顺序记录小马宝莉资料（假设name和ID都不会重复），至少需要设计以下方法：
构造函数：建立空的头结点
displayAll：显示所有小马宝莉资料
displayByID：根据ID显示小马宝莉资料
displayByName：根据name显示小马宝莉资料
insertByOrder：把一匹小马根据ID插入到链表中适当的位置，使得链表中的结点依然保持ID从小到大的顺序
insertHead：把一匹小马插入到链表中的首部（头结点后面）
insertBottom：把一匹小马插入到链表中的尾部
visitByID：根据ID返回一匹小马的资料
visitByName：根据名字返回一匹小马的资料
deleteByID：根据ID在链表中删除一匹小马结点
析构函数：用于清理链表里所有new出来的结点

部分代码如下：

#include<iostream>
#include<string>
using namespace std;
class Score
{
private:
 int cpp, math, eng;
public:
 Score() {}
 Score(int cpp, int math, int eng) :cpp(cpp), math(math), eng(eng)
 {}
 void display()
 {
  cout << "C++: " << cpp << " Math: " << math << " Eng: " << eng;
 }
};
class Pony
{
public:
 string ID, name;
 Score score;
 Pony *next;
 Pony() :next(nullptr)
 {}
 Pony(string ID, string name, int cpp, int math, int eng) :ID(ID), name(name), score(cpp, math, eng), next(nullptr)
 {}
 void display()
 {
  cout << "Name: " << name << " ID: " << ID << ' ';
  score.display();
  cout << endl;
 }
};

//补充class Link

int main()
{
 Link link; //初始化链表，建立一个头结点
 link.insertByOrder(Pony("T1001", "Twilight Sparkle", 90, 92, 94)); //把T1001加入链表
 link.insertByOrder(Pony("T1012", "Rainbow Dash", 70, 72, 74)); //把T1012加入链表，这里需要根据ID顺序，把这个节点加入到T1001之后
 link.displayByID("T1001"); //应当显示T1001的资料
 cout << "----------" << endl;
 link.displayByName("Rainbow Dash"); //应当显示T1012的资料
 cout << "----------" << endl;
 link.insertByOrder(Pony("T1005", "Apple Jack", 78, 83, 81)); //把T1005加入链表，这里需要根据ID顺序，把这个节点加入到T1001和T1012之间
 link.displayAll(); //应当按顺序显示T1001、T1005、T1012的资料
 cout << "----------" << endl;
 Pony s = link.visitByID("T1005"); //s存储T1005的资料
 link.deleteByID("T1005"); //把T1005从链表中删除
 s.display(); //显示T1005的资料
 cout << "----------" << endl;
 Pony t = link.visitByName("Twilight Sparkle");
 t.display(); //显示T1001的资料
 cout << "----------" << endl;
 link.insertBottom(Pony("T1000", "Rarity", 60, 62, 64)); //把T1000加入链表尾部
 link.displayAll(); //应当显示T1001、T1012、T1000的资料
 cout << "----------" << endl;
 link.insertHead(Pony("T1010", "Fluttershy", 93, 90, 100)); //把T1010加入链表首部
 link.insertHead(Pony("T1011", "Pinkie Pie", 86, 83, 80)); //把T1011加入链表首部
 link.displayAll(); //应当显示T1011、T1010、T1001、T1012、T1000的资料
 return 0;
}


输入
无

输出
Name: Twilight Sparkle ID: T1001 C++: 90 Math: 92 Eng: 94
----------
Name: Rainbow Dash ID: T1012 C++: 70 Math: 72 Eng: 74
----------
Name: Twilight Sparkle ID: T1001 C++: 90 Math: 92 Eng: 94
Name: Apple Jack ID: T1005 C++: 78 Math: 83 Eng: 81
Name: Rainbow Dash ID: T1012 C++: 70 Math: 72 Eng: 74
----------
Name: Apple Jack ID: T1005 C++: 78 Math: 83 Eng: 81
----------
Name: Twilight Sparkle ID: T1001 C++: 90 Math: 92 Eng: 94
----------
Name: Twilight Sparkle ID: T1001 C++: 90 Math: 92 Eng: 94
Name: Rainbow Dash ID: T1012 C++: 70 Math: 72 Eng: 74
Name: Rarity ID: T1000 C++: 60 Math: 62 Eng: 64
----------
Name: Pinkie Pie ID: T1011 C++: 86 Math: 83 Eng: 80
Name: Fluttershy ID: T1010 C++: 93 Math: 90 Eng: 100
Name: Twilight Sparkle ID: T1001 C++: 90 Math: 92 Eng: 94
Name: Rainbow Dash ID: T1012 C++: 70 Math: 72 Eng: 74
Name: Rarity ID: T1000 C++: 60 Math: 62 Eng: 64


样例输入


样例输出
Name: Twilight Sparkle ID: T1001 C++: 90 Math: 92 Eng: 94
----------
Name: Rainbow Dash ID: T1012 C++: 70 Math: 72 Eng: 74
----------
Name: Twilight Sparkle ID: T1001 C++: 90 Math: 92 Eng: 94
Name: Apple Jack ID: T1005 C++: 78 Math: 83 Eng: 81
Name: Rainbow Dash ID: T1012 C++: 70 Math: 72 Eng: 74
----------
Name: Apple Jack ID: T1005 C++: 78 Math: 83 Eng: 81
----------
Name: Twilight Sparkle ID: T1001 C++: 90 Math: 92 Eng: 94
----------
Name: Twilight Sparkle ID: T1001 C++: 90 Math: 92 Eng: 94
Name: Rainbow Dash ID: T1012 C++: 70 Math: 72 Eng: 74
Name: Rarity ID: T1000 C++: 60 Math: 62 Eng: 64
----------
Name: Pinkie Pie ID: T1011 C++: 86 Math: 83 Eng: 80
Name: Fluttershy ID: T1010 C++: 93 Math: 90 Eng: 100
Name: Twilight Sparkle ID: T1001 C++: 90 Math: 92 Eng: 94
Name: Rainbow Dash ID: T1012 C++: 70 Math: 72 Eng: 74
Name: Rarity ID: T1000 C++: 60 Math: 62 Eng: 64
*/

#include <iostream>
#include <string>
using namespace std;
class Score
{
private:
    int cpp, math, eng;

public:
    Score() {}
    Score(int cpp, int math, int eng) : cpp(cpp), math(math), eng(eng) {}
    void display()
    {
        cout << "C++: " << cpp << " Math: " << math << " Eng: " << eng;
    }
};

class Pony
{
public:
    string ID, name;
    Score score;
    Pony *next;
    Pony() : next(nullptr) {}
    Pony(string ID, string name, int cpp, int math, int eng) : ID(ID), name(name), score(cpp, math, eng), next(nullptr) {}
    void display()
    {
        cout << "Name: " << name << " ID: " << ID << ' ';
        score.display();
        cout << endl;
    }
};

// 补充class Link
class Link
{
private:
    Pony *head;

public:
    Link()
    {
        head = new Pony();
    }

    void displayAll()
    {
        Pony *p = head->next;
        while (p != nullptr)
        {
            p->display();
            p = p->next;
        }
    }

    void displayByID(string a)
    {
        Pony *p = head->next;
        while (p != nullptr)
        {
            if (p->ID == a)
            {
                p->display();
                break;
            }
            else
            {
                p = p->next;
            }
        }
    }

    void displayByName(string a)
    {
        Pony *p = head->next;
        while (p != nullptr)
        {
            if (p->name == a)
            {
                p->display();
                break;
            }
            else
            {
                p = p->next;
            }
        }
    }

    void insertByOrder(Pony pony)
    {
        Pony *p = head;
        while (p->next != nullptr && p->next->ID < pony.ID)
        {
            p = p->next;
        }
        Pony *newPony = new Pony(pony);
        newPony->next = p->next;
        p->next = newPony;
    }

    void insertHead(Pony pony)
    {
        Pony *newPony = new Pony(pony);
        newPony->next = head->next;
        head->next = newPony;
    }

    void insertBottom(Pony pony)
    {
        Pony *p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        Pony *newPony = new Pony(pony);
        p->next = newPony;
    }

    Pony visitByID(string ID)
    {
        Pony *p = head->next;
        while (p != nullptr)
        {
            if (p->ID == ID)
            {
                return *p;
                break;
            }
            else
            {
                p = p->next;
            }
        }
    }

    Pony visitByName(string ID)
    {
        Pony *p = head->next;
        while (p != nullptr)
        {
            if (p->name == ID)
            {
                return *p;
            }
            p = p->next;
        }
    }

    void deleteByID(string ID)
    {
        Pony *p = head->next;
        Pony *q = head;
        while (p != nullptr)
        {
            if (p->ID == ID)
            {
                q->next = p->next;
                delete (p);
                p = q->next;
            }
            else
            {
                p = p->next;
                q = q->next;
            }
        }
    }
};

int main()
{
    Link link;                                                         // 初始化链表，建立一个头结点
    link.insertByOrder(Pony("T1001", "Twilight Sparkle", 90, 92, 94)); // 把T1001加入链表
    link.insertByOrder(Pony("T1012", "Rainbow Dash", 70, 72, 74));     // 把T1012加入链表，这里需要根据ID顺序，把这个节点加入到T1001之后
    link.displayByID("T1001");                                         // 应当显示T1001的资料
    cout << "----------" << endl;
    link.displayByName("Rainbow Dash"); // 应当显示T1012的资料
    cout << "----------" << endl;
    link.insertByOrder(Pony("T1005", "Apple Jack", 78, 83, 81)); // 把T1005加入链表，这里需要根据ID顺序，把这个节点加入到T1001和T1012之间
    link.displayAll();                                           // 应当按顺序显示T1001、T1005、T1012的资料
    cout << "----------" << endl;
    Pony s = link.visitByID("T1005"); // s存储T1005的资料
    link.deleteByID("T1005");         // 把T1005从链表中删除
    s.display();                      // 显示T1005的资料
    cout << "----------" << endl;
    Pony t = link.visitByName("Twilight Sparkle");
    t.display(); // 显示T1001的资料
    cout << "----------" << endl;
    link.insertBottom(Pony("T1000", "Rarity", 60, 62, 64)); // 把T1000加入链表尾部
    link.displayAll();                                      // 应当显示T1001、T1012、T1000的资料
    cout << "----------" << endl;
    link.insertHead(Pony("T1010", "Fluttershy", 93, 90, 100)); // 把T1010加入链表首部
    link.insertHead(Pony("T1011", "Pinkie Pie", 86, 83, 80));  // 把T1011加入链表首部
    link.displayAll();                                         // 应当显示T1011、T1010、T1001、T1012、T1000的资料
    return 0;
}
