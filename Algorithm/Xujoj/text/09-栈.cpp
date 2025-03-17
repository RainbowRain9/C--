#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    stack<int> stackA, stackB;
    int n;
    cin >> n;

    while (n--)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            char c;
            int x;
            cin >> c >> x;
            if (c == 'A')
            {
                stackA.push(x);
            }
            else
            {
                stackB.push(x);
            }
        }
        else if (op == "pop")
        {
            char c;
            cin >> c;
            if (c == 'A')
            {
                if (stackA.empty())
                {
                    cout << "EMPTY" << endl;
                }
                else
                {
                    cout << stackA.top() << endl;
                    stackA.pop();
                }
            }
            else
            {
                if (stackB.empty())
                {
                    cout << "EMPTY" << endl;
                }
                else
                {
                    cout << stackB.top() << endl;
                    stackA.pop();
                }
            }
        }
        else
        {
            char a, b;
            cin >> a >> b;
            vector<int> temp;
            if (a == 'A')
            {
                while (!stackB.empty())
                {
                    temp.push_back(stackB.top());
                    stackA.pop();
                }
                for (int i = temp.size() - 1; i >= 0; i--)
                {
                    stackA.push(temp[i]);
                }
            }
            else
            {
                while (!stackA.empty())
                {
                    temp.push_back(stackA.top());
                    stackA.pop();
                }
                for (int i = temp.size() - 1; i >= 0; i--)
                {
                    stackB.push(temp[i]);
                }
            }
        }
    }

    return 0;
}