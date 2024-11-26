#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("1.txt");
    if (!fin)
        exit(1);

    fin.seekg(0, ios::end);
    int len = fin.tellg();
    cout << len << endl;

    fin.seekg(-9, ios::end);
    char c = fin.peek();
    cout << c << endl;

}