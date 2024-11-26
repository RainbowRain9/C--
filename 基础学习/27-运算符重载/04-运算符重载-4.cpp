/*
描述
请严格按照题目要求完成，以达到练习运算符重载的目的

实现一个分数类Fraction（支持有理数即可），要求：
建立构造函数，当分数不是最简形式时进行约分，保证分母不为负数
重载加减乘除运算，当结果的分数不是最简形式时进行约分，保证分母不为负数
重载++，--运算（注意前置和后置的区别）
重载大于、等于、小于、大于等于、小于等于、不等于运算
重载<<输出显示功能
int main()
{
 Fraction r(20, -12); //r的分子应该是-5，分母应该是3
 Fraction s(-20, 5); //s的分子应该是-4，分母应该是1
 Fraction t = r + s + s; //t的分子应该是-29，分母应该是3，其他四则运算自行测试
 cout << t << endl;
 s = ++r; //r先变成-2/3，然后s等于-2/3
 cout << r << ' ' << s << endl;
 t = s--; //t先变成-2/3，然后s变成-5/3
 cout << t << ' ' << s << endl;
 //大于、小于等比较运算自行测试
 return 0;
}

样例输出
-29/3

-2/3 -2/3

-2/3 -5/3
*/
#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class Fraction
{
private:
    int x; // 分子
    int y; // 分母

    // 简化分数并确保分母为正数
    void simplify()
    {
        int g = gcd(abs(x), abs(y)); // 取绝对值后求最大公约数
        x /= g;
        y /= g;
        if (y < 0)
        {
            x = -x;
            y = -y;
        }
    }

public:
    // 构造函数
    Fraction(int x, int y) : x(x), y(y)
    {
        simplify();
    }

    // 重载+运算符
    Fraction operator+(const Fraction &other) const
    {
        return Fraction(x * other.y + other.x * y,
                        y * other.y);
    }

    // 重载-运算符
    Fraction operator-(const Fraction &other) const
    {
        return Fraction(x * other.y - other.x * y,
                        y * other.y);
    }

    // 重载*运算符
    Fraction operator*(const Fraction &other) const
    {
        return Fraction(x * other.x, y * other.y);
    }

    // 重载/运算符
    Fraction operator/(const Fraction &other) const
    {
        return Fraction(x * other.y, y * other.x);
    }

    // 前置++运算符重载
    Fraction &operator++()
    {
        x += y;
        return *this;
    }
    // 后置++运算符重载
    Fraction operator++(int)
    {
        Fraction temp = *this;
        x += y;
        return temp;
    }
    // 前置--运算符重载
    Fraction &operator--()
    {
        x -= y;
        return *this;
    }
    // 后置--运算符重载
    Fraction operator--(int)
    {
        Fraction temp = *this;
        x -= y;
        return temp;
    }
    // 重载>运算符
    bool operator>(const Fraction &other) const
    {
        return x * other.y > other.x * y;
    }

    // 重载=运算符
    bool operator==(const Fraction &other) const
    {
        return x * other.y == other.x * y;
    }
    // 重载<<运算符，用于输出显示
    friend ostream &operator<<(ostream &os, const Fraction &f)
    {
        os << f.x << "/" << f.y;
        return os;
    }
};

int main()
{
    Fraction r(20, -12);    // r的分子应该是-5，分母应该是3     
    Fraction s(-20, 5);     // s的分子应该是-4，分母应该是1
    Fraction t = r + s + s; // t的分子应该是-29，分母应该是3
    cout << t << endl;      // 输出 -29/3

    s = ++r;                       // r先变成-2/3，然后s等于-2/3
    cout << r << ' ' << s << endl; // 输出 -2/3 -2/3

    t = s--;                       // t先变成-2/3，然后s变成-5/3
    cout << t << ' ' << s << endl; // 输出 -2/3 -5/3

    return 0;
}