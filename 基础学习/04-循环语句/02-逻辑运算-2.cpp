#include<iostream>
using namespace std;

int main() {
    int m, n, temp;
    cin >> m >> n;
    if (m>n){
        temp = m;
        m = n;
        n = temp;//m最小
    }
    if (n - m <= 100){
        cout << "0";
    }
    else{
        cout << "1";
    }

    return 0;
}