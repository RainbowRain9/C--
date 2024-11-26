#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("1.txt");
    if (!fin)
        exit(1);
    int n;
    fin >> n;

    ofstream fout("2.txt");
    if (!fout)
        exit(1);
    for (int i = 0; i < n; i++)
    {
        fout << "*";
    }
    return 0;
}