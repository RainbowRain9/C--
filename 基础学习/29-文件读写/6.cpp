#include<iostream> 
#include<fstream> 
#include<string> 
using namespace std; 
int main() 
{ 
    string s1 = "东临碣石，以观沧海。\n"; 
    string s2 = "水何澹澹，山岛竦峙。\n"; 
    ofstream fout("data4.txt"); 
    if (!fout) exit(1); 
    fout.write(s1.c_str(), s1.size()).write(s2.c_str(), s2.size()); 
    fout.close(); 
    return 0; 
}