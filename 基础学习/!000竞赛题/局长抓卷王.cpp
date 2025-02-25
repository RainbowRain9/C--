// Source : https://www.xujcoj.com/home/contest/2099/problem/1
// Date   : 2025-01-19

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

string solve(vector<string> &tokens, int &pos) 
{
    if (pos >= tokens.size())
        return "";

    if (tokens[pos] != "max") 
    {
        string num = tokens[pos];
        pos++;
        return num;
    }

    pos++;
    if (pos >= tokens.size())
        return "";

    string param1 = solve(tokens, pos);
    if (pos >= tokens.size())
        return "";

    string param2 = solve(tokens, pos);
    if (param1.empty() || param2.empty())
        return "";

    return "max(" + param1 + "," + param2 + ")";
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        vector<string> tokens(m);

        for (int i = 0; i < m; i++)
        {
            cin >> tokens[i];
        }

        if (m == 1 && tokens[0] != "max")
        {
            cout << tokens[0] << ";" << endl;
            continue;
        }

        int pos = 0;
        string result = solve(tokens, pos);

        if (result.empty() || pos != m)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << result << ";" << endl;
        }
    }

    return 0;
}