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
    string a;
    cin >> a;
    for (char c : a)
    {
        if (c == 'W')
        {
            cout << "E";
        }
        if (c == 'S')
        {
            cout << "N";
        }
        if (c == 'N')
        {
            cout << "S";
        }
        if (c == 'E')
        {
            cout << "W";
        }
    }

    return 0;
}