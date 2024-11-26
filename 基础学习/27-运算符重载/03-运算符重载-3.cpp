/*
描述
请严格按照题目要求完成，以达到练习运算符重载的目的

（1）定义一个形状类Figure，具有以下成员：
保护属性：面积area，在构造函数中把它设置为0
公有方法：getArea ，功能是返回面积
对运算符>进行重载，功能是比较两个形状的面积，如果参数1的面积大于参数2的面积则返回true，否则返回false
对运算符<<进行重载，功能是输出面积
（2）定义一个正方形类Square继承形状类figure，具有以下成员：
保护属性：边长
构造函数：具有1个参数表示边长，构造函数的功能是初始化边长，并计算面积赋值给area属性
（3）定义一个矩形类Rectangle继承形状类figure，具有以下成员：
保护属性：两个，表示长和宽
构造函数具有2个参数表示长和宽，构造函数的功能是初始化长和宽，并计算面积赋值给area属性
（4）用模板写一个排序函数sort，参数是数组名字和数组长度，功能是对任意形状类型的数组进行排序。利用重载的运算符>进行排序。
（5）用模板写一个输出函数print，参数是数组名字和数组长度，功能是对任意类型的数组进行输出。利用重载的运算符<<进行输出。
int main()
{
 Figure f[5] = { Square(4), Rectangle(3, 4), Rectangle(6, 8), Square(2), Square(10) };
 cout << "Before sorting:" << endl;
 print(f, 5);
 sort(f, 5);
 cout << "After sorting:" << endl;
 print(f, 5);
 return 0;
}

样例输出
Before sorting:
16
12
48
4
100
After sorting:
4
12
16
48
100
*/
#include <iostream>
using namespace std;
class Figure
{
protected:
    int area;

public:
    Figure() : area(0) {}
    bool operator>(const Figure &other)
    {
        if (area > other.area)
            return true;
        else
            return false;
    }
    void operator<<(int)
    {
        cout << area << endl;
    }
    double getArea()
    {
        return area;
    }
};

class Square : public Figure
{
protected:
    int a;

public:
    Square(int a_) : a(a_)
    {
        area = a * a;
    }
};

class Rectangle : public Figure
{
protected:
    int a;
    int b;

public:
    Rectangle(int a_, int b_) : a(a_), b(b_)
    {
        area = a * b;
    }
};

template <class T>
void sort(T f[], int n)
{

    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 1; j < n - i; j++)
        {
            if (f[j - 1].getArea() > f[j].getArea())
            {
                flag = true;
                swap(f[j - 1], f[j]);
            }
        }
        if (!flag)
        {
            break;
        }
    }
}
template <class T>
void print(T f[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << f[i].getArea() << endl;
    }
}

int main()
{
    Figure f[5] = {Square(4), Rectangle(3, 4), Rectangle(6, 8), Square(2), Square(10)};
    cout << "Before sorting:" << endl;
    print(f, 5);
    sort(f, 5);
    cout << "After sorting:" << endl;
    print(f, 5);
    return 0;
}