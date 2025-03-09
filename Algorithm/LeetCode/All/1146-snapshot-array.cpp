// Source : https://leetcode.cn/problems/snapshot-array/description/
// Date   : 2025-02-25
/*
 * @lc app=leetcode.cn id=1146 lang=cpp
 * @lcpr version=30006
 *
 * [1146] 快照数组
 */

// @lcpr-template-start
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
// @lcpr-template-end
// @lc code=start
class SnapshotArray
{
    unordered_map<int, vector<pair<int, int>>> history;
    int cur_snap_id = 0;

public:
    SnapshotArray(int length)
    {
    }

    void set(int index, int val)
    {
        history[index].emplace_back(cur_snap_id, val);
    }

    int snap()
    {
        return cur_snap_id++;
    }

    int get(int index, int snap_id)
    {
        auto &h = history[index];
        int j = ranges::lower_bound(h, pair(snap_id + 1, 0)) - h.begin() - 1;
        return j >= 0 ? h[j].second : 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end

/*
// @lcpr case=start
// ["SnapshotArray","set","snap","set","get"][[3],[0,5],[],[0,6],[0,0]]\n
// @lcpr case=end

 */
