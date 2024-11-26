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
    int pos = 0;
    while (n != 0)
    {
        if (n & 1 == 1)
        {
            cout << (char)('a' + pos);
        }
        pos++;
        n = n >> 1;
    }

    return 0;
}