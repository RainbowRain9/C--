#include <iostream>
using namespace std;

int ActiveManage(int* s, int* f, int* B, int n) {
    int count = 0;
    int lastFinishTime = 0;

    B[0] = 1;
    count++;
    lastFinishTime = f[0];

    for (int i = 1; i < n; i++) {
        if (s[i] >= lastFinishTime) {
            B[i] = 1;
            count++;
            lastFinishTime = f[i];
        } else {
            B[i] = 0;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    int *s = new int[11] { 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12 };
    int *f = new int[11]{ 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    int i, k = 0;
    int *B = new int[n]{ 0 };
    k = ActiveManage(s, f, B, n);
    cout << k << endl;
    return 0;
}