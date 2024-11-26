/*
描述
定义MyInt类，成员包括一个整数i，要求：
（1）MyInt类的构造函数
（2）重载运算符+，返回一个MyInt类的对象，该对象中i的值为两个对象中i值的平方和。
（3）重载运算符^，表示成幂运算
（4）重载运算符-，表示成负号运算
（5）MyInt类的display方法，用于显示i的值
int main()
{
 MyInt t1(4);
 MyInt t2(3);
 MyInt t3, t4, t5;
 t3 = t1 + t2;
 t4 = t1^t2;
 t5 = -t4;
 t1.display();
 t2.display();
 t3.display();
 t4.display();
 t5.display();
 return 0;
}

样例输出
4

3

25

64

-64
*/

#include <iostream>
using namespace std;
class MyInt
{
private:
    int i;

public:
    MyInt() {}
    MyInt(int i_) : i(i_) {}
    MyInt operator+(const MyInt &other)
    {
        return MyInt(i * i + other.i * other.i);
    }
    MyInt operator^(const MyInt &other) const
    {
        int result = 1;
        for (int count = 0; count < other.i; ++count)
        {
            result *= i;
        }
        return MyInt(result);
    }
    MyInt operator-()
    {
        return MyInt(-i);
    }
    void display()
    {
        cout << i << endl;
    }
};
int main()
{
    MyInt t1(4);
    MyInt t2(3);
    MyInt t3, t4, t5;
    t3 = t1 + t2;
    t4 = t1 ^ t2;
    t5 = -t4;
    t1.display();
    t2.display();
    t3.display();
    t4.display();
    t5.display();
    return 0;
}