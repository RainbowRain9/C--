/*
描述
输入两个整数，如果这两个数字的乘积大于100，那么输出0，否则输出1

输入
两个整数m和n

输出
如果m*n大于100，那么输出0，否则输出1

样例输入
5 6

样例输出
1
*/

#include <iostream>
using namespace std;
int main(){
    int m,n;
    cin >> m >> n;
    if(m * n > 100){
        cout << "0";
    }
    else{
        cout << "1";
    }
    return 0;
}