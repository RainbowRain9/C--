#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int>& a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        vector<int> a(m);
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        BubbleSort(a);
        cout << a[0];
        for (int i = 1; i < m; i++)
        {
            cout << " " << a[i];
        }
        cout << endl;
    }
}