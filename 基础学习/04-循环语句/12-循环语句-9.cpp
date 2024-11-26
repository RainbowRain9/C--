#include<iostream>
using namespace std;

int main() {
    int m, n, sum = 0;
    cin >> m >> n;
    for (m; m <= n; m++){
        sum = sum + m;
    }
    cout << sum;
    
    return 0;
}