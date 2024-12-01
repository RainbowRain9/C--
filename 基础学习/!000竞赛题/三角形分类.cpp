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
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> ans = {a, b, c};
        sort(ans.begin(), ans.end());

        if (a == 60 && b == 60 && c == 60)
        {
            cout << 1 << endl;
        }
        else if (a == b || b == c || a == c)
        {
            if (ans[2] == 90)
            {
                cout << 2 << endl;
            }
            else if (ans[2] < 90)
            {
                cout << 3 << endl;
            }
            else
            {
                cout << 4 << endl;
            }
        }
        else if (ans[2] == 90)
        {
            cout << 5 << endl;
        }
        else if (ans[2] < 90)
        {
            cout << 6 << endl;
        }
        else
        {
            cout << 7 << endl;
        }
    }

    return 0;
}
