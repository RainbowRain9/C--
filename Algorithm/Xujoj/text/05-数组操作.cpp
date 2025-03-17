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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool r;

    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int k;
            cin >> k;
            int index;
            if (r)
            {
                index = n - k;
            }
            else
            {
                index = k - 1;
            }
            cout << a[index] << endl;
        }
        else if (t == 2)
        {
            int k, x;
            cin >> k >> x;
            int index;
            if (r)
            {
                index = n - k;
            }
            else
            {
                index = k - 1;
            }
            a[index] = x;
        }
        else if (t == 3)
        {
            r = !r;
        }
    }

    return 0;
}