/*
 * @Author: RainbowRain9
 * @Date: 2025-04-09 22:16:09
 * @LastEditTime: 2025-04-09 23:09:18
 * @FilePath: \C++\Algorithm\PTA\L1-064-估值一亿的AI核心代码.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 实现一个AI英文问答程序，规则如下：
 * 1. 原样打印用户输入
 * 2. 消除多余空格：相邻单词间保留1个空格，删除首尾空格和标点前空格
 * 3. 大写字母变小写，除了I
 * 4. 独立的can you、could you替换为I can、I could
 * 5. 独立的I和me替换为you
 * 6. 问号?替换为感叹号!
 *
 * 示例 1：
 *   输入：Hello ?
 *   输出：hello!
 *   解释：大写H变小写，问号变感叹号
 *
 * 示例 2：
 *   输入：can you speak Chinese?
 *   输出：I can speak chinese!
 *   解释：can you替换为I can，大写C变小写，问号变感叹号
 *
 * 提示：
 *   - 输入N (1≤N≤10) 表示对话数量
 *   - 每行对话不超过1000个字符
 *   - 对话仅包含字母、数字、空格、可见的半角标点符号
 **************************************************/

#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
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
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);
        cout << s << endl;
        string processed_s;
        bool last_char_was_space = true;
        for (int i = 0; i < s.length(); ++i) {
            char current_char = s[i];
            if (isspace(current_char)) {
                if (!last_char_was_space) {
                    last_char_was_space = true;
                }
            } else if (ispunct(current_char) && current_char != '\'') {
                char punc_to_add = (current_char == '?') ? '!' : current_char;
                if (!processed_s.empty() && !last_char_was_space) {
                    processed_s += ' ';
                }
                processed_s += punc_to_add;
                last_char_was_space = true;
            } else {
                if (last_char_was_space && !processed_s.empty()) {
                    processed_s += ' ';
                }
                processed_s += current_char;
                last_char_was_space = false;
            }
        }
         size_t first_char = processed_s.find_first_not_of(' ');
         if (string::npos == first_char) {
             processed_s = "";
         } else {
             size_t last_char = processed_s.find_last_not_of(' ');
             processed_s = processed_s.substr(first_char, (last_char - first_char + 1));
         }
        stringstream ss(processed_s);
        vector<string> words;
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        vector<string> result_words;
        for (int i = 0; i < words.size(); ++i) {
            string current_token = words[i];
            if (current_token.length() == 1 && ispunct(current_token[0])) {
                result_words.push_back(current_token);
                continue;
            }
            string next_token = (i + 1 < words.size()) ? words[i + 1] : "";
            string lower_current_word = "";
            bool original_was_I = (current_token == "I");
            for(char c : current_token) lower_current_word += tolower(c);
            string lower_next_word = "";
            if (!next_token.empty() && !(next_token.length() == 1 && ispunct(next_token[0]))) {
                 for(char c : next_token) lower_next_word += tolower(c);
            }
            bool replaced = false;
            if ((lower_current_word == "can" || lower_current_word == "could") && lower_next_word == "you") {
                result_words.push_back("I");
                result_words.push_back(lower_current_word);
                i++;
                replaced = true;
            }
            else if (lower_current_word == "i" || lower_current_word == "me") {
                result_words.push_back("you");
                replaced = true;
            }
            if (!replaced) {
                 if(original_was_I){
                    result_words.push_back(current_token);
                 } else {
                    result_words.push_back(lower_current_word);
                 }
            }
        }
        cout << "AI: ";
        for (int i = 0; i < result_words.size(); ++i) {
             cout << result_words[i];
             if (i < result_words.size() - 1) {
                  string next_token = result_words[i+1];
                  if (!(next_token.length() == 1 && ispunct(next_token[0]) && next_token != "'"))
                  {
                       cout << " ";
                  }
             }
        }
        cout << endl;
    }
    return 0;
}