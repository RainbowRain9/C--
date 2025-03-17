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
    string s;
    cin >> s;
    int n = s.size();
    int left = 0, right = n - 1;
    while (left <= right)
    {
        if (s[left] != s[right])
        {
            s[right] = s[left];
        }
        left++;
        right--;
    }
    cout << s;

    return 0;
}