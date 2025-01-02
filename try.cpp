#include <iostream>
#include <vector>
using namespace std;

// 插入排序
void InsertSort(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

// 冒泡排序
void BubbleSort(vector<int> &a)
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

// 简单排序
void SelectSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        if (i != minIndex)
        {
            swap(a[i], a[minIndex]);
        }
    }
}

// 希尔排序
void ShellSort(vector<int> &a)
{
    int n = a.size();
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j = i - gap;
            while (j >= 0 && a[j] > temp)
            {
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j + gap] = temp;
        }
    }
}

// 堆排序
void heapify(vector<int> &a, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;

    if (i != largest)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void HeapSort(vector<int> &a)
{
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

// 快速排序
int partition(vector<int> &a, int left, int right)
{
    int pivot = a[left];
    while (left < right)
    {
        while (left < right && a[right] >= pivot)
            right--;
        a[left] = a[right];
        while (left < right && a[left] <= pivot)
            left++;
        a[right] = a[left];
    }
    a[left] = pivot;
    return left;
}

void QuickSort(vector<int> &a, int left, int right)
{
    if (left < right)
    {
        int pos = partition(a, left, right);
        QuickSort(a, left, pos - 1);
        QuickSort(a, pos + 1, right);
    }
}

// 主程序
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // InsertSort(a);
    // BubbleSort(a);
    // SelectSort(a);
    // ShellSort(a);
    // HeapSort(a);
    QuickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

// 5 3 2 1 5 4
