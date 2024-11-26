/*
描述
把代码补充完整，以实现要求的输出。

主函数如下：

int main()
{
 Goat *g1 = new Goat("Pretty Goat", 47);
 Goat *g2 = new Goat("Warm Goat", 60);
 Wolf *w1 = new Wolf("Wilie", 50);
 print(g1);
 print(g2);
 print(w1);
 g2->sleep();
 w1->eat(g1);
 print(g2);
 print(w1);
 return 0;
}

输入
无

输出
以下文字，最后一行后面也要换行。

Pretty Goat is a goat that weights 47 kg.
Warm Goat is a goat that weights 60 kg.
Wilie is a wolf that weights 50 kg.
Warm Goat has a good sleep, increasing 2 kg.
Wilie eats Pretty Goat, increasing 47 kg
Warm Goat is a goat that weights 62 kg.
Wilie is a wolf that weights 97 kg.




样例输入


样例输出
Pretty Goat is a goat that weights 47 kg.
Warm Goat is a goat that weights 60 kg.
Wilie is a wolf that weights 50 kg.
Warm Goat has a good sleep, increasing 2 kg.
Wilie eats Pretty Goat, increasing 47 kg
Warm Goat is a goat that weights 62 kg.
Wilie is a wolf that weights 97 kg.
*/

#include <iostream>
#include <string>
using namespace std;

class Goat
{
public:x
    string name;
    int weight;
    Goat(string n, int w) : name(n), weight(w){}
    void sleep()
    {
        weight += 2;
        cout << name << " has a good sleep, increasing 2 kg." << endl;
    }
};

class Wolf
{
public:
    string name;
    int weight;
    Wolf(string n, int w) : name(n), weight(w)
    {
    }
    void eat(Goat *g)
    {
        weight += g->weight;
        cout << name << " eats " << g->name << ", increasing " << g->weight << " kg" << endl;
        delete g;
    }
};
void print(Goat *a)
{
    cout << a->name << " is a goat that weights " << a->weight << " kg." << endl;
}
void print(Wolf *a)
{
    cout << a->name << " is a wolf that weights " << a->weight << " kg." << endl;
}
int main()
{
    Goat *g1 = new Goat("Pretty Goat", 47);
    Goat *g2 = new Goat("Warm Goat", 60);
    Wolf *w1 = new Wolf("Wilie", 50);
    print(g1);
    print(g2);
    print(w1);
    g2->sleep();
    w1->eat(g1);
    print(g2);
    print(w1);
    return 0;
}
