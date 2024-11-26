#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout("data2.txt", ios::out | ios::app); // 如果忘了 ios::app 会清空原有内容
    if (!fout)
        exit(1);
    fout << "Hello!" << endl;
    fout.close();
    ifstream fin("data2.txt", ios::in);
    if (!fin)
        exit(1);
    char c;
    while (fin.get(c))
    {
        cout << c;
    }
    fin.close();
    return 0;
}