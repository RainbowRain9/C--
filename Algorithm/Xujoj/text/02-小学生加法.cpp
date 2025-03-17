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
    int a, b, c;
    cin >> a >> b >> c;
    int a1 = a % 10;
    int b1 = b % 10;
    int c1 = c % 10;
    cout << a1 + b1 + c1;

    return 0;
}