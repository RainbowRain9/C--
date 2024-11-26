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
    if (n == 1 || n == 2)
        cout << -1 << endl;
    else
    {
        for (int i = 3; i > 0; i--)
        {
            cout << i << " ";
        }
        for (int i = 4; i <= n; i++)
        {
            cout << i << " ";
        }
    }
    return 0;
}