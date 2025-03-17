/*
 * @Author: RainbowRain9
 * @Date: 2025-03-17 16:00:39
 * @LastEditTime: 2025-03-17 16:01:02
 * @FilePath: \C++\Algorithm\Xujoj\SWE23\week4\04-tree-outside-school-gate-hard.cpp
 * @Description: 
 */
/*
 * @Author: RainbowRain9
 * @Date: 2025-03-17 16:00:39
 * @LastEditTime: 2025-03-17 16:00:57
 * @FilePath: \C++\Algorithm\Xujoj\SWE23\week4\04-tree-outside-school-gate-hard.cpp
 * @Description: 
 */
/**************************************************
 * 题目描述：
 * 嘉庚学院大门外长度为L的马路上有一排树，每两棵相邻的树之间的间隔都是1米。我们可以把马路看成一个数轴，
 * 马路的一端在数轴0的位置，另一端在L的位置，数轴上的每个整数点（即0，1，2，……，L）都种有一棵树。
 * 由于马路上有一些区域要用来建地铁。这些区域用它们在数轴上的起始点和终止点表示。
 * 已知任一区域的起始点和终止点的坐标都是整数，区域之间可能有重合的部分。
 * 现在要把这些区域中的树（包括区域端点处的两棵树）移走。
 * 你的任务是计算将这些树都移走后，马路上还有多少棵树。
 * 
 * 输入描述：
 * 第一行是两个整数L，M，其中L代表马路的长度，M代表区域的数目。(0 <= L <= 2000000000，1 <= M <= 100000)
 * 接下来的M行每行有两个正整数a、b，分别表示一个区域的起始点坐标和终止点坐标。(0 <= a < b <= L)
 * 
 * 输出描述：
 * 一个整数表示马路上剩余的树的数目，然后换行。
 * 
 * 示例 1：
 *   输入：
 *   5 2
 *   0 2
 *   1 3
 *   输出：
 *   2
 *   解释：
 *   初始有6棵树（0-5），移除了0-2和1-3区域的树后，剩下4和5两棵树
 * 
 * 提示：
 *   - 注意L的范围可能很大（0 <= L <= 2000000000）
 *   - 需要高效处理大量区域（M <= 100000）
 *   - 考虑使用区间合并算法来优化
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

int main()
{
    // 读取输入
    long long L;
    int M;
    cin >> L >> M;
    
    // 存储区间
    vector<pair<int, int>> intervals(M);
    for(int i = 0; i < M; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    
    // 按左端点排序
    sort(intervals.begin(), intervals.end());
    
    // 区间合并
    int start = intervals[0].first;
    int end = intervals[0].second;
    long long remove = 0;
    
    for(int i = 1; i < M; i++) {
        if(intervals[i].first <= end) {
            // 区间重叠，更新右端点
            end = max(end, intervals[i].second);
        } else {
            // 区间不重叠，计算当前区间树的数量并开始新区间
            remove += end - start + 1;
            start = intervals[i].first;
            end = intervals[i].second;
        }
    }
    // 处理最后一个区间
    remove += end - start + 1;
    
    // 计算结果
    cout << (L + 1) - remove << endl;
    
    return 0;
}