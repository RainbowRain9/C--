/*
 * @Author: RainbowRain9
 * @Date: 2025-03-16 17:29:39
 * @LastEditTime: 2025-03-16 17:33:41
 * @FilePath: \C++\Algorithm\Xujoj\text\12-小丑夜宴.cpp
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

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int m;
    cin >> m;
    while(m--)
    {
        string op;
        cin >> op;
        if (op == "SWAP"){
            int l1,r1,l2,r2;
            cin >> l1 >> r1 >> l2 >> r2;
            while(l1 <= r1){
                st[l2] = a[l1];
                l1++;
                l2++;
            }
            
        }
    }

    return 0;
}