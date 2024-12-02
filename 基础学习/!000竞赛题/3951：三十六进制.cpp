// Source : 
// Date   : 2024-12-02

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int baseToDecimal(string number, int base) {
    int result = 0;
    bool isNegative = number[0] == '-';
    int start = isNegative ? 1 : 0;
    
    for(int i = start; i < number.length(); i++) {
        result *= base;
        if(number[i] >= '0' && number[i] <= '9') {
            result += number[i] - '0';
        } else {
            result += number[i] - 'A' + 10;  // A->10, B->11, ...
        }
    }
    
    return isNegative ? -result : result;
}

int main()
{
    string n;
    cin >> n;
    cout << baseToDecimal(n, 36) << ednl;
    
    return 0;
}