#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int first, m;
        cin >> first;

        int count = 0;
        for (int i = 0; i < 9; i++)
        {
            cin >> m;
            if (first != 0 && m % first == 0)
            {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}