/*
描述
实现一个复数类（Complex），可以进行复数的加减乘除运算、判断相等以及输出显示功能。
int main()
{
 Complex c1(2, 10), c2(2, 6), c5, c6;
 Complex c3 = c1 + c2 + c2;
 Complex c4 = c1 - c2;
 c1.display();
 c2.display();
 c3.display();
 c4.display();
 if (c3 == c4)
  c5 = c3 * c4;
 else
  c5 = c3 / c4;
 c5.display();
 if (c1 != c2)
  c6 = c1 * c2;
 else
  c6 = c1 / c2;
 c6.display();
 return 0;
}

样例输出
2+10i

2+6i

6+22i

4i

5.5-1.5i

-56+32i
*/
#include <iostream>
using namespace std;
class Complex
{
private:
    double c;
    double d;

public:
    Complex() {}
    Complex(double a, double b) : c(a), d(b) {}
    Complex operator+(Complex &other)
    {
        return Complex(c + other.c, d + other.d);
    }
    Complex operator-(Complex &other)
    {
        return Complex(c - other.c, d - other.d);
    }
    Complex operator*(Complex &other)
    {
        double a, b;
        a = c * other.c - d * other.d;
        b = c * other.d + d * other.c;
        return Complex(a, b);
    }
    Complex operator/(Complex &other)
    {
        double b = other.c * other.c + other.d * other.d;
        return Complex((c * other.c + d * other.d) / b,
                       (d * other.c - c * other.d) / b);
    }
    // 重载==运算符
    bool operator==(Complex &other) const
    {
        return (c == other.c) && (d == other.d);
    }

    // 重载!=运算符
    bool operator!=(Complex &other) const
    {
        return !(*this == other);
    }

    void display()
    {
        if (c == 0)
            cout << d << "i" << endl;
        else if (d == 0)
            cout << c << endl;
        else if (d < 0)
            cout << c << d << "i" << endl;
        else
            cout << c << "+" << d << "i" << endl;
    }
};

int main()
{
    Complex c1(2, 10), c2(2, 6), c5, c6;
    Complex c3 = c1 + c2 + c2;
    Complex c4 = c1 - c2;
    c1.display();
    c2.display();
    c3.display();
    c4.display();
    if (c3 == c4)
        c5 = c3 * c4;
    else
        c5 = c3 / c4;
    c5.display();
    if (c1 != c2)
        c6 = c1 * c2;
    else
        c6 = c1 / c2;
    c6.display();
    return 0;
}
