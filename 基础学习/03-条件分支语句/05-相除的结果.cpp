/*

描述
输入两个整数x和y，如果y等于0，那么输出0；否则如果x除以y的余数为0，那么输出1；如果余数不为0，那么输出2。

输入
两个整数x和y

输出
如果y等于0，那么输出0；否则如果x%y为0，那么输出1；如果x%y不为0，那么输出2。不要换行。

样例输入
5 2

样例输出
2

*/

#include <iostream>
using namespace std;
int main(){
    int x, y;
    cin >> x >> y;
    if (y == 0){
        cout << "0";
    }
    else if (x % y == 0){
        cout << "1";
    }
    else{
        cout << "2";
    }
    return 0;
} 