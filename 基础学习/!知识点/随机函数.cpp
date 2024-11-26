#include <iostream>
#include <random>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    random_device rd;
    int c = rd() % (b + a - 1) + a;
    cout << c;
}