#include <iostream>
using namespace std;
void bubbleSort(int a[], int n)
{
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bubbleSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    delete[] a;
    return 0;
}