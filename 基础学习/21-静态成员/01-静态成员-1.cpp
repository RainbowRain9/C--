/*
描述


把代码补充完整，定义一个GardenCharactor类以实现要求的输出。

主函数如下：

int main()
{
    GardenCharactor c1("Igglepiggle"), c2("Upsy Daisy"), c3("Makka Pakka"), c4("Tombliboo");
    c2.play("dancing");
    c3.play("heaping up stones");
    return 0;
}

输入
无

输出
以下文字，最后一行后面也要换行。

No.1 character in the night garden: Igglepiggle
No.2 character in the night garden: Upsy Daisy
No.3 character in the night garden: Makka Pakka
No.4 character in the night garden: Tombliboo
Upsy Daisy is dancing
Makka Pakka is heaping up stones

样例输入


样例输出
No.1 character in the night garden: Igglepiggle
No.2 character in the night garden: Upsy Daisy
No.3 character in the night garden: Makka Pakka
No.4 character in the night garden: Tombliboo
Upsy Daisy is dancing
Makka Pakka is heaping up stones
*/

#include <iostream>
#include <string>
using namespace std;

class GardenCharactor
{
private:
    string name;

public:
    GardenCharactor(string n) : name(n)
    {
        static int count = 1;
        display(count, name);
        count++;
    }

    void play(string action)
    {
        cout << name << " is " << action << endl;
    }   
    static void display(int index, string name)
    {
        cout << "No." << index << " character in the night garden: " << name << endl;
    }
};

int main()
{
    GardenCharactor c1("Igglepiggle"), c2("Upsy Daisy"), c3("Makka Pakka"), c4("Tombliboo");
    c2.play("dancing");
    c3.play("heaping up stones");
    return 0;
}
