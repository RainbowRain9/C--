#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("1.txt");
    if (!fin)
    {
        exit(1);
    }
    char s;
    while (fin.get(s))
    {
        cout << s;
    }
    return 0;
}