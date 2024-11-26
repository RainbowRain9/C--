#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("1.txt");
    if (!fin)
    {
        cerr << "无法打开文件" << endl;
        exit(1);
    }
    fin.seekg(0, ios::end);
    int len = fin.tellg();
    // 使用循环读取文件中的每个字符

    for (int i = 0; i < len; i += 2)
    {
        fin.seekg(i, ios::beg);
        char c = fin.get();
        cout << c;
    }

    fin.close(); // 关闭文件
    return 0;
}