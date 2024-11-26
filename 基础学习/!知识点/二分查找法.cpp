#include <iostream>
#include <random>
using namespace std;
int binaryfind(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}i


