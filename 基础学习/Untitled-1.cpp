#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    ofstream outFile("1.txt");
    if (!outFile)
    {
        cerr << "Unable to open file!" << endl;
        return 1;
    }

    outFile.put('a');
    outFile.put('b');
    outFile.put('c');
    outFile.put('d');
    outFile.put('e');

    outFile.close();
    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string data = "abcde";
    ofstream outFile("1.txt", ios::binary);
    if (!outFile)
    {
        cerr << "Unable to open file!" << endl;
        return 1;
    }

    outFile.write(data.c_str(), data.size());

    outFile.close();
    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outFile("1.txt");
    if (!outFile)
    {
        cerr << "Unable to open file!" << endl;
        return 1;
    }

    outFile << "abcde";

    outFile.close();
    return 0;
}