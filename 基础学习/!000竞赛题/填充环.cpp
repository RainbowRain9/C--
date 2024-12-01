using namespace std;
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

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        vector<int> a(x);
        for (long long i = 0; i < x; i++)
        {
            cin >> a[i];
        }
        long long cnt = 0;
        long long num = x;
        long long sum = 0;
        for (int i = 0; i < x; i++)
        {
            sum += a[i];
            long long next = (i + 1) % x;
            if (a[i] != a[next])
            {
                cnt = abs(a[i] - a[next]) - 1;
                num += cnt;
                sum += ((a[i] + a[next]) * cnt) / 2;
            }
        }

        cout << num << " " << sum << endl;
    }

    return 0;
}