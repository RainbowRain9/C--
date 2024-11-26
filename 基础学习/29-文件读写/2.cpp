#include<iostream> 
#include<fstream> 
using namespace std; 
int main() 
{ 
    ofstream fout("data2.txt", ios::out | ios::app); 
    if (!fout) exit(1); 
    fout << "Hello, C++!" << endl; 
    fout.close(); 
 
    ifstream fin("data2.txt", ios::in); 
    if (!fin) exit(1); 
    char c; 
    while (fin.get(c)) 
    { 
        cout << c; //这句写成 cout.put(c); 也可以 
    } 
    fin.close(); 
    return 0; 
}