#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(11);
    for (int i = 0; i < n; i++)
    {
        int num, index;
        cin >> num;
        index = num % 11;

        while (a[index] != 0)
        {
            index = (index + 1) % 11;
        }
        a[index] = num;
    }
    int m;
    while (cin >> m)
    {
        if (m == 0)
        {
            cout << "BYE" << endl;
            break;
        }
        bool b = false;
        for (int i = 0; i < 11; i++)
        {
            if (a[i] == m)
            {
                cout << i << endl;
                b = true;
            }
        }
        if (!b)
        {
            cout << "NOTFOUND" << endl;
        }
    }
}