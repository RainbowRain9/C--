/*
描述
（1）定义一个形状类Figure，具有以下成员：
保护属性：面积area，等于0
公有方法：getArea ，功能是返回面积
（2）定义一个正方形类Square继承形状类figure，具有以下成员：
保护属性：边长
构造函数：具有1个参数表示边长，构造函数的功能是初始化边长，并计算面积赋值给area属性
（3）定义一个矩形类Rectangle继承形状类figure，具有以下成员：
保护属性：两个，表示长和宽
构造函数：具有2个参数表示长和宽，构造函数的功能是初始化长和宽，并计算面积赋值给area属性
（4）用模板写一个排序函数sort，参数是数组名字和数组长度，功能是对任意形状类型的数组进行排序
（5）用模板写一个输出函数print，参数是数组名字和数组长度，功能是对任意类型的数组进行输出

int main()
{
 Figure f[5] = { Square(4), Rectangle(3, 4), Rectangle(6, 8), Square(2), Square(10) };
 cout << "Before Sorting:" << endl;
 print(f, 5);
 sort(f, 5);
 cout << "After Sorting:" << endl;
 print(f, 5);
 return 0;
}


样例输出
Before Sorting:
16
12
48
4
100
After Sorting:
4
12
16
48
100
*/

#include <iostream>
#include <string>
using namespace std;

class Figure
{
protected:
    int area;

public:
	Figure() :area(0) {}
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
    cout << "Before Sorting:" << endl;
    print(f, 5);
    sort(f, 5);
    cout << "After Sorting:" << endl;
    print(f, 5);
    return 0;
}
