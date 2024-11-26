#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream f("1.txt");
    if (!f)
        exit(1);
    int a, cnt = 0, sum = 0;
    while (f.peek() != EOF)
    {
        f >> a;
        if (a >= 0 && a <= 150)
        {
            cnt++;
            sum += a;
        }
    }
    f << cnt << " " << sum;
    f.close();
    return 0;
}