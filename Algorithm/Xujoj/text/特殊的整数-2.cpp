#include <iostream>
#include <map>
#include <numeric>
#include <vector>


// 使用 long long 来存储可能较大的组合数
using namespace std;
using ll = long long;

// Memoization 表：将状态键映射到结果
// 键是一个 long long，编码了当前的数字(digit)和每个数字(0-9)的已使用次数(counts)
map<ll, ll> memo;

/**
 * @brief 将状态 (digit, counts) 转换为一个唯一的 long long 键
 *
 * @param digit 当前考虑的数字 (从 9 递减到 -1)
 * @param counts 一个 vector，存储数字 0 到 9 当前已被选择的次数
 * @return ll 代表该状态的唯一键
 */
ll get_state_key(int digit, const vector<int>& counts)
{
    // 使用 digit+1 (范围 0 到 10) 作为键的一部分，确保非负
    ll key = (digit + 1);
    // 使用 4 作为基数，因为每个数字最多使用 3 次 (0, 1, 2, 3 四种状态)
    // power_of_4 将依次为 4^0, 4^1, ..., 4^9
    ll power_of_4 = 1;
    for (int i = 0; i <= 9; ++i) {
        // 为了避免哈希冲突，将 counts[i] 乘以 4 的幂次，
        // 再乘以一个大于 digit+1 最大值 (10) 的数 (这里用 11)。
        // 确保状态的每个部分在最终键中有唯一的表示。
        // key = (digit+1) + c0*4^0*11 + c1*4^1*11 + ... + c9*4^9*11
        key += (ll)counts[i] * power_of_4 * 11;
        power_of_4 *= 4;
    }
    // 最终键唯一地代表了 (digit, c0, c1, ..., c9) 的状态
    return key;
}

/**
 * @brief 递归函数，计算满足条件的数字组合数
 *
 * 使用深度优先搜索 (DFS) 和记忆化来计算。
 * 该函数计算的是，在已经确定了 > digit 的数字的使用次数后，
 * 使用数字 0 到 digit 可以形成的有效后缀组合的数量。
 *
 * @param digit 当前正在考虑分配次数的数字 (从 9 向下递归到 -1)
 * @param counts 引用传递的 vector，存储数字 0 到 9 到目前为止被选择的次数。
 *               这个数组在递归过程中被修改，并在返回前恢复。
 * @return ll 从当前状态出发，可以形成的有效正整数组合的数量。
 */
ll count_combinations(int digit, vector<int>& counts)
{
    // 基本情况：所有数字 (9 到 0) 都已考虑完毕
    if (digit < 0) {
        // 检查是否至少选择了一个非零数字 (1-9)
        // 这是为了满足“正整数”和“0不能作为最高位”的条件
        // 如果只选择了0，或者什么都没选，都不是有效的正整数
        bool has_positive_digit = false;
        for (int i = 1; i <= 9; ++i) {
            if (counts[i] > 0) {
                has_positive_digit = true;
                break;
            }
        }
        // 如果 counts 数组代表了一个有效的正整数（即至少包含一个 1-9 的数字），
        // 则返回 1，表示找到了一个有效的组合。否则返回 0。
        return has_positive_digit ? 1 : 0;
    }

    // 记忆化：检查当前状态 (digit, counts) 是否已计算过
    ll state_key = get_state_key(digit, counts);
    if (memo.count(state_key)) {
        return memo[state_key];
    }

    ll total_count = 0;

    // 状态转移：尝试为当前数字 `digit` 选择 0 到 3 次
    // 这个循环决定了当前考虑的数字 `digit` 在最终的数中出现多少次
    for (int count_digit = 0; count_digit <= 3; ++count_digit) {
        // 更新当前数字 `digit` 的使用次数
        counts[digit] = count_digit;

        // 递归到下一个更小的数字 (digit - 1)，累加结果
        total_count += count_combinations(digit - 1, counts);

        // 回溯：恢复 `digit` 的使用次数为 0，以便探索其他分支
        // 这一步至关重要，确保 counts 数组在返回上一层调用时状态正确
        counts[digit] = 0;
    }

    // 存储结果到 memoization 表，避免重复计算
    memo[state_key] = total_count;
    return total_count;
}

int main()
{
    // 设置 C++ 标准输入输出流不与 C 标准库同步，提高效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 初始化 counts 数组，所有数字的使用次数初始为 0
    // counts[i] 表示数字 i 被使用的次数
    vector<int> counts(10, 0);

    // 从最高位数字 9 开始递归计算
    // count_combinations(9, counts) 将计算所有可能的有效组合数
    ll result = count_combinations(9, counts);

    // 输出结果，注意题目要求不要换行
    cout << result;

    return 0;
}