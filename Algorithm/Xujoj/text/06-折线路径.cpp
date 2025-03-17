/*
 * @Author: RainbowRain9
 * @Date: 2025-03-16 15:44:51
 * @LastEditTime: 2025-03-16 16:49:38
 * @FilePath: \C++\Algorithm\Xujoj\text\06-折线路径.cpp
 * @Description:
 */
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

double f(int x1, x2, x3, x4){
    if (x1 == x2 && y1 == y2) return 0;

    if (x1 == x2) return abs(y1 - y2);

    double len = 0;
    
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        double w, h, ans;
        w = abs(x1 - x2);
        h = abs(y1 - y2);
        ans = sqrt(w * w + h * h);
        cout << ans << endl;
    }

    return 0;
}