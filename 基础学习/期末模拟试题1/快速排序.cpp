#include <iostream>

using namespace std;

class Sort
{
public:
    int *data;

    Sort(int m)
    {
        data = new int[m];
    }

    int Partition(int first, int last);

    void QuickSort(int first, int last);
};

/*****************************

    快速排序的一次划分算法

******************************/

int Sort::Partition(int first, int last)
{
    int pivot = data[first];
    while (first < last)
    {
        while (first < last && data[last] >= pivot)
            last--;
        data[first] = data[last];
        while (first < last && data[first] <= pivot)
            first++;
        data[last] = data[first];
    }
    data[first] = pivot;
    return first;
}

/*******************

    快速排序算法

********************/

void Sort::QuickSort(int first, int last)
{
    // 补充代码
    if (first < last)
    {
        int pivot = Partition(first, last);
        QuickSort(first, pivot - 1);
        QuickSort(pivot + 1, last);
    }
}

int main()

{

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)

    {

        int m;

        cin >> m;

        Sort *a = new Sort(m);

        // int *a = new int[m];

        for (int j = 0; j < m; j++)
        {
            cin >> a->data[j];
        }

        a->QuickSort(0, m - 1);

        for (int j = 0; j < m; j++)
        {
            cout << a->data[j];

            if (j == m - 1) 
                cout << endl;

            else
                cout << ' ';
        }
    }

    return 0;
}