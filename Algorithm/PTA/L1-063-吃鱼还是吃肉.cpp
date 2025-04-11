/*
 * @Author: RainbowRain9
 * @Date: 2025-04-09 22:06:16
 * @LastEditTime: 2025-04-09 22:15:32
 * @FilePath: \C++\Algorithm\PTA\L1-063-吃鱼还是吃肉.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 国家给出了8岁男宝宝的标准身高为130厘米、标准体重为27公斤；
 * 8岁女宝宝的标准身高为129厘米、标准体重为25公斤。
 * 根据小宝宝的身高体重，给出补充营养的建议。
 *
 * 示例 1：
 *   输入：
 *   4
 *   0 130 23
 *   1 129 27
 *   1 130 30
 *   0 128 27
 *   输出：
 *   ni li hai! duo chi rou!
 *   duo chi yu! wan mei!
 *   wan mei! shao chi rou!
 *   duo chi yu! shao chi rou!
 *   解释：
 *   - 对每个宝宝先评价身高再评价体重,两句话之间有1个空格
 *   - 身高: 太矮(duo chi yu!), 标准(wan mei!), 太高(ni li hai!)
 *   - 体重: 太瘦(duo chi rou!), 标准(wan mei!), 太胖(shao chi rou!)
 *
 * 提示：
 *   - 性别用1表示男生,0表示女生
 *   - 身高和体重都是不超过200的正整数
 *   - N不超过10
 **************************************************/

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
struct Baby {
    int sex;
    int height;
    int weight;
};

int main()
{
    int n;
    cin >> n;
    while (n--) {
        Baby baby;
        cin >> baby.sex >> baby.height >> baby.weight;
        string height_msg, weight_msg;

        if (baby.sex == 1) {
            if (baby.height > 130)
                height_msg = "ni li hai!";
            else if (baby.height < 130)
                height_msg = "duo chi yu!";
            else
                height_msg = "wan mei!";
        } else {
            if (baby.height > 129)
                height_msg = "ni li hai!";
            else if (baby.height < 129)
                height_msg = "duo chi yu!";
            else
                height_msg = "wan mei!";
        }

        if (baby.sex == 1) {
            if (baby.weight > 27)
                weight_msg = "shao chi rou!";
            else if (baby.weight < 27)
                weight_msg = "duo chi rou!";
            else
                weight_msg = "wan mei!";
        } else {
            if (baby.weight > 25)
                weight_msg = "shao chi rou!";
            else if (baby.weight < 25)
                weight_msg = "duo chi rou!";
            else
                weight_msg = "wan mei!";
        }

        cout << height_msg << " " << weight_msg << endl;
    }

    return 0;
}