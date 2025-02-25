#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &arr)
{
    int n = arr.size() - 1;
    vector<int> temp(arr.size());
    for (int i = 1; i <= n; i++)
    {
        temp[i] = arr[i - 1];
    }

    int swaps = 0;
    for (int j = 1; j <= n - 1; j++)
    {
        bool flag = false;
        for (int i = 1; i <= n - j; i++)
        {
            if (temp[i] > temp[i + 1])
            {
                swap(temp[i], temp[i + 1]);
                flag = true;
                swaps++;
            }
        }
        if (!flag)
            break;
    }
    return swaps;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << solve(arr) << endl;
    }
    return 0;
}