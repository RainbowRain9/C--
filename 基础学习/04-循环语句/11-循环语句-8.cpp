#include<iostream>
using namespace std;

int main() {
    int a = 0,i;

    for (i = 0; i <= 10000; i++){
        a += i;
    }
    cout << a;
    
    return 0;
}