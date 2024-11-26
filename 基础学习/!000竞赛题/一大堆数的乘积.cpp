#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long result = 1;
    while (n--)
    {
        int num;
        cin >> num;
        result = (result * num) % 100000000;
    }
    cout << result << endl;
    string s = to_string(result);
    while (s.length() < 8)
    {
        s = "0" + s;
    }
    cout << s;

    return 0;
}