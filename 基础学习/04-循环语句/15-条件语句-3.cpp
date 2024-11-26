/*
描述
    判断一张纸能否夹在一本书里而不露出来

输入
    4个正整数a、b、c、d，其中a和b代表书的两边长度，c和d代表纸的两边长度

输出
    如果这张纸够小，以至于可以夹在书里而不露出来，则输出1，否则输出0。

样例输入
    6 4 5 4

样例输出
    1

提示说明
    只需要考虑纸横放和竖放的情况，不用考虑斜着放的情况。只要某一个方向可以不露出来就算可以。
*/

#include<iostream>
using namespace std;

int main() {
    int a, b, c, d, m, n;
    
    cin >> a >> b >> c >> d;

    // 交换a和b，确保a是书的长边
    if (a < b) {
        m = a;
        a = b;
        b = m;
    }

    // 交换c和d，确保c是纸的长边
    if (c < d) {
        n = c;
        c = d;
        d = n;
    }

    // 如果书的长边和短边都大于纸，则输出1
    if (a >= c && b >= d) {
        cout << "1";
    } else {
        cout << "0";
    }
    return 0;
}