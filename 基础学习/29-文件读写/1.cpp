#include <iostream>
#include <fstream>
using namespace std;
int main() 
{ 
    ofstream fout("data1.txt"); 
    if (fout.fail()) 
    { 
        cout << "文件打开失败" << endl; 
        exit(1); 
    } 
    for (int i = 0; i < 10; i++) 
    { 
        fout << i << " + 1 = " << i + 1 << endl; 
    } 
    fout.close(); 

    ifstream fin("data1.txt");
    if (!fin)
        exit(1);
    char x;
    while (fin.get(x))
    {
        cout << x;
    }
    fin.close();
    return 0; 
}