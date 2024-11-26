#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("data4.txt");
    if (fin.fail())
        exit(1);
    char c;
    while (fin.peek() != EOF)
    {
        fin.read(&c, sizeof(c));
        cout.write(&c, sizeof(c));
    }
    fin.close();
    return 0;
}