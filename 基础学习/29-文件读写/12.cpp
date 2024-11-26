#include <iostream>
using namespace std;
class Num
{
public:
    int a;
    Num() {}
    Num(int a)
    {
        this->a = a;
    }
    // ①请补充
    Num operator+(Num &other)
    {
        return Num(a + other.a);
    }
    Num operator-(Num &other)
    {
        return Num(a - other.a);
    }
};
// ②请补充
ostream &operator<<(ostream &os, Num a)
{
    os << a.a << endl;
    return os;
}
int main()
{
    Num n1(5), n2(4), n3, n4;
    n3 = n1 + n2;
    n4 = n1 - n2;
    cout << n3 << n4;
    return 0;
}