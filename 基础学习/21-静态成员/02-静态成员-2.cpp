/*
描述


把代码补充完整，定义一个Goat类以实现要求的输出。

主函数如下：

int main()
{
 Goat g1("Pleasant Goat"), g2("Pretty Goat"), g3("Athlect Goat");
 g2.visit("the pavilion", "having a romance", g3);
 Goat g4("Lazy Goat");
 g4.visit("the library", "studying");
 Goat g5("Slow Goat"), g6("Warm Goat");
 g2.visit("Zhongshan street", "shopping", g5);
 g1.visit("Nanputuo Temple", "chanting scriptures");
 g6.visit("the gymnasium", "doing physical exercise");
 return 0;
}

输入
无

输出
以下文字，最后一行后面也要换行。

Pleasant Goat is the No.1 goat on the grassland. There is 1 goat remains.
Pretty Goat is the No.2 goat on the grassland. There are 2 goats remain.
Athlect Goat is the No.3 goat on the grassland. There are 3 goats remain.
Pretty Goat, the No.2 goat, and Athlect Goat, the No.3 goat, are having a romance together at the pavilion. There is 1 goat remains.
Lazy Goat is the No.4 goat on the grassland. There are 2 goats remain.
Lazy Goat, the No.4 goat, is studying at the library. There is 1 goat remains.
Slow Goat is the No.5 goat on the grassland. There are 2 goats remain.
Warm Goat is the No.6 goat on the grassland. There are 3 goats remain.
Pretty Goat, the No.2 goat, and Slow Goat, the No.5 goat, are shopping together at Zhongshan street. There are 2 goats remain.
Pleasant Goat, the No.1 goat, is chanting scriptures at Nanputuo Temple. There is 1 goat remains.
Warm Goat, the No.6 goat, is doing physical exercise at the gymnasium. There is 0 goat remains.



样例输入


样例输出
Pleasant Goat is the No.1 goat on the grassland. There is 1 goat remains.
Pretty Goat is the No.2 goat on the grassland. There are 2 goats remain.
Athlect Goat is the No.3 goat on the grassland. There are 3 goats remain.
Pretty Goat, the No.2 goat, and Athlect Goat, the No.3 goat, are having a romance together at the pavilion. There is 1 goat remains.
Lazy Goat is the No.4 goat on the grassland. There are 2 goats remain.
Lazy Goat, the No.4 goat, is studying at the library. There is 1 goat remains.
Slow Goat is the No.5 goat on the grassland. There are 2 goats remain.
Warm Goat is the No.6 goat on the grassland. There are 3 goats remain.
Pretty Goat, the No.2 goat, and Slow Goat, the No.5 goat, are shopping together at Zhongshan street. There are 2 goats remain.
Pleasant Goat, the No.1 goat, is chanting scriptures at Nanputuo Temple. There is 1 goat remains.
Warm Goat, the No.6 goat, is doing physical exercise at the gymnasium. There is 0 goat remains.
*/

#include <iostream>
#include <string>
using namespace std;
class Goat
{
private:
    string name;
    int id;
    bool remain;
    static int num;
    static int remainNum;

public:
    Goat(string name_) : name(name_), remain(true)
    {
        id = ++num;
        ++remainNum;
        string strBe = (remainNum <= 1) ? "is" : "are";
        string strRe = (remainNum <= 1) ? "goat remains." : "goats remain.";
        cout << name << " is the No." << id << " goat on the grassland. There " << strBe << " " << remainNum << " " << strRe << endl;
    }

    void visit(string str1, string str2, Goat &g)
    {
        if (remain)
        {
            remainNum -= 1;
            remain = false;
        }
        if (g.remain)
        {
            remainNum -= 1;
            g.remain = false;
        }
        string strBe = (remainNum <= 1) ? "is" : "are";
        string strRe = (remainNum <= 1) ? "goat remains." : "goats remain.";
        cout << name << ", the No." << id << " goat, and " << g.name << ", the No." << g.id << " goat, are " << str2 << " together at " << str1
             << ". There " << strBe << " " << remainNum << " " << strRe << endl;
    }

    void visit(string str1, string str2)
    {
        if (remain)
        {
            remainNum -= 1;
            remain = false;
        }
        string strBe = (remainNum <= 1) ? "is" : "are";
        string strRe = (remainNum <= 1) ? "goat remains." : "goats remain.";
        cout << name << ", the No." << id << " goat, is " << str2 << " at " << str1 << ". There " << strBe << " " << remainNum << " " << strRe << endl;
    }
};

int Goat::num = 0;
int Goat::remainNum = 0;

int main()
{
    Goat g1("Pleasant Goat"), g2("Pretty Goat"), g3("Athlect Goat");
    g2.visit("the pavilion", "having a romance", g3);
    Goat g4("Lazy Goat");
    g4.visit("the library", "studying");
    Goat g5("Slow Goat"), g6("Warm Goat");
    g2.visit("Zhongshan street", "shopping", g5);
    g1.visit("Nanputuo Temple", "chanting scriptures");
    g6.visit("the gymnasium", "doing physical exercise");
    return 0;
}