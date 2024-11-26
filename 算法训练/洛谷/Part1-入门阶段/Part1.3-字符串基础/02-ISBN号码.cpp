/*https://www.luogu.com.cn/problem/P1055*/

/**************************************************
 * 题目描述：
 * 每一本正式出版的图书都有一个ISBN号码与之对应，ISBN码包括9位数字、1位识别码和3位分隔符，其规定格式如下：
 * X-XXX-XXXXX-X
 * 其中符号-就是分隔符，最后一位是识别码，例如0-670-82162-4就是一个标准的ISBN码。
 * 判断输入的ISBN号码是否正确，用以下公式检验：
 * (第1位数字×1+第2位数字×2+第3位数字×3+第4位数字×4+第5位数字×5+第6位数字×6+第7位数字×7+第8位数字×8+第9位数字×9)除以11的余数等于识别码
 *
 * 示例 1：
 *   输入：0-670-82162-4
 *   输出：Right
 *   解释：(0×1+6×2+7×3+0×4+8×5+2×6+1×7+6×8+2×9)÷11=4
 *
 * 示例 2：
 *   输入：0-670-82162-0
 *   输出：4
 *   解释：识别码应该是4
 *
 * 提示：
 *   - 如果识别码正确，输出"Right"
 *   - 如果识别码错误，输出正确的识别码
 **************************************************/

/*
    解题思路：
    1. 读取ISBN号码字符串
    2. 提取数字部分并按公式计算
    3. 比较计算结果与识别码是否一致
    4. 根据比较结果输出

    时间复杂度分析：O(1) - ISBN号码长度固定
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string isbn;
    cin >> isbn;

    // 提取数字并计算
    int sum = 0;
    int pos = 1;
    for (int i = 0; i < isbn.length() - 1; i++)
    {
        if (isbn[i] >= '0' && isbn[i] <= '9')
        {
            sum += (isbn[i] - '0') * pos;
            pos++;
        }
    }

    // 获取识别码
    char lastChar = isbn[isbn.length() - 1];
    int checkDigit = (lastChar == 'X') ? 10 : (lastChar - '0');

    // 计算正确的识别码
    int correctDigit = sum % 11;

    // 判断并输出结果
    if (checkDigit == correctDigit)
    {
        cout << "Right" << endl;
    }
    else
    {
        isbn[isbn.length() - 1] = (correctDigit == 10) ? 'X' : (correctDigit + '0');
        cout << isbn[isbn.length() - 1] << endl;
    }

    return 0;
}