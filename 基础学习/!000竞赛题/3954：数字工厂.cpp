// Source : https://www.xujcoj.com/home/problem/detail/3954
// Date   : 2024-12-02

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

bool isPrime(int n)
{
    if (n == 2)
        return true;
    if (n <= 1 || n % 2 == 0)
        return false;
    for (int i = 3; i <= n / i; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    long long sum = 0;
    for (int i = 1; i <= 2022; i++)
    {
        string s = to_string(i);
        if (isPrime(i))
        {
            reverse(s.begin(), s.end());
            sum += stoi(s);
        }
        else
        {
            int num = 0;
            for (auto c : s)
            {
                num += (c - '0');
            }
            sum += num;
        }
    }
    cout << sum << endl;

    return 0;
}