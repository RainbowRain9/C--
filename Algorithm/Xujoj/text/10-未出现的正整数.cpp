#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    while (m--)
    {
        int k;
        cin >> k;
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (a[mid] - mid - 1 < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        cout << k + left << endl;
    }

    return 0;
}