#include <iostream>
#include <vector>
using namespace std;

int N, r;
vector<int> result;

void dfs(int start, int depth)
{
    if (depth == r)
    {
        for (int i = 0; i < r; i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i >= 1; i--)
    {
        result[depth] = i;
        dfs(i - 1, depth + 1);
    }
}

int main()
{
    cin >> N >> r;
    result.resize(r);
    dfs(N, 0);
    return 0;
}