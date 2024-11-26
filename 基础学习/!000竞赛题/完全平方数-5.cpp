#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        long long a;
        cin >> a;
        
        long long sqrtA = sqrt(a);
        long long count = (sqrtA + 1) / 2;
        
        cout << count << endl;
    }
    
    return 0;
}