// Source : https://leetcode.cn/problems/time-based-key-value-store/description/
// Date   : 2025-02-25
/*
 * @lc app=leetcode.cn id=981 lang=cpp
 * @lcpr version=30006
 *
 * [981] 基于时间的键值存储
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
class TimeMap
{
private:
    unordered_map<string, vector<pair<int, string>>> data;

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        data[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        if (data.find(key) == data.end())
        {
            return "";
        }

        auto &pairs = data[key];
        int left = 0, right = pairs.size() - 1;
        
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (pairs[mid].first <= timestamp)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        
        if (right >= 0)
        {
            return pairs[right].second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

/*
// @lcpr case=start
// ["TimeMap", "set", "get", "get", "set", "get", "get"][[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]\n
// @lcpr case=end

 */
