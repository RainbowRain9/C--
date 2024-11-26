#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("8.dat", ios::ate | ios::binary);
    ofstream fout1("81.dat", ios::binary);
    ofstream fout2("82.dat", ios::binary);
    if (!fin || !fout1 || fout2)
        exit(1);
    int len = fin.tellg();
    fin.seekg(0);
    char c;
    for (int i = 0; i < len / 2; i++)
    {
        fin.get(c);
        fout1.put(c);
    }
    for (int i = 0; i < len / 2; i++)
    {
        fin.get(c);
        fout2.put(c);
    }
    fin.close();
    fout1.close();
    fout2.close();
    return 0;
}