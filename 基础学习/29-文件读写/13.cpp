#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("1.bin", ios::binary);
    ofstream fout("2.bin", ios::binary);
    if (!fin || !fout)
        exit(1);
    char c;
    int leng = fin.tellg();
    fin.seekg(0);
    for (int i = 0; i < leng; i++)
    {
        fout << c;
    }
    fin.close();
    fout.close();
    return 0;
}