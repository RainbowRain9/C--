/*
 * @Author: RainbowRain9
 * @Date: 2025-04-02 23:13:52
 * @LastEditTime: 2025-04-04 20:15:18
 * @FilePath: \C++\Algorithm\PTA\L1-020-帅到没朋友.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 当芸芸众生忙着在朋友圈中发照片的时候，总有一些人因为太帅而没有朋友。
 * 本题要求你找出那些帅到没有朋友的人。
 *
 * 输入格式：
 * 第一行：正整数N（≤100），已知朋友圈的个数
 * 随后N行：每行首先给出一个正整数K（≤1000），为朋友圈中的人数，
 *          然后列出朋友圈内的所有人ID（5位数字，00000到99999）
 * 之后一行：正整数M（≤10000），待查询的人数
 * 最后一行：M个待查询的ID，以空格分隔
 *
 * 输出格式：
 * 按输入顺序输出那些帅到没朋友的人，ID间用1个空格分隔，
 * 行首尾不得有多余空格。如果没有人太帅，则输出"No one is handsome"
 *
 * 注意：
 * 1. 没有朋友的人可以是根本没安装"朋友圈"，也可以是只有自己一个人在朋友圈的人
 * 2. 同一个人可以被查询多次，但只输出一次
 *
 * 示例 1：
 *   输入：
 *   3
 *   3 11111 22222 55555
 *   2 33333 44444
 *   4 55555 66666 99999 77777
 *   8
 *   55555 44444 10000 88888 22222 11111 23333 88888
 *   输出：
 *   10000 88888 23333
 *   解释：
 *   10000、88888和23333没有出现在任何朋友圈中
 *
 * 示例 2：
 *   输入：
 *   3
 *   3 11111 22222 55555
 *   2 33333 44444
 *   4 55555 66666 99999 77777
 *   4
 *   55555 44444 22222 11111
 *   输出：
 *   No one is handsome
 *   解释：
 *   所有查询的ID都至少出现在一个朋友圈中
 *
 * 提示：
 *   - 所有K超过1的朋友圈里都至少有2个不同的人
 *   - ID号为5位数字，范围00000到99999
 *   - 注意处理重复查询的情况
 **************************************************/
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
// TODO 2025-04-04: 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<string> friends;
    friends.reserve(100000);

    while (n--)
    {
        int k;
        cin >> k;

        if (k > 1)
        {
            while (k--)
            {
                string id;
                cin >> id;
                friends.insert(move(id));
            }
        }
        else
        {
            string dummy;
            cin >> dummy;
        }
    }

    int m;
    cin >> m;
    
    unordered_set<string> queried;
    vector<string> result;
    bool hasHandsome = false;

    while (m--)
    {
        string id;
        cin >> id;
        
        if (queried.find(id) != queried.end())
            continue;
            
        queried.insert(id);
        
        if (friends.find(id) == friends.end())
        {
            result.push_back(id);
            hasHandsome = true;
        }
    }

    if (!hasHandsome)
    {
        cout << "No one is handsome";
    }
    else
    {
        for (size_t i = 0; i < result.size(); ++i)
        {
            if (i != 0) cout << " ";
            cout << result[i];
        }
    }
    cout << endl;

    return 0;
}