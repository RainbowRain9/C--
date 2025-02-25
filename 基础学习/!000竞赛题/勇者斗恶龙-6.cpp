#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1005;
int graph[MAXN * 2][MAXN * 2];
int n, m, q;

void floyd(int total)
{
    for (int k = 0; k < total; k++)
    {
        for (int i = 0; i < total; i++)
        {
            for (int j = 0; j < total; j++)
            {
                if (graph[i][k] == 1 && graph[k][j] == 1)
                {
                    graph[i][j] = 1;
                    graph[j][i] = -1;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m >> q;
    int total = n + m;

    for (int i = 0; i < total; i++)
    {
        for (int j = 0; j < total; j++)
        {
            graph[i][j] = 0;
        }
    }

    while (q--)
    {
        int type, x, y;
        cin >> type >> x >> y;
        x--;
        y--;

        if (type == 1)
        {
            graph[x][y] = 1;
            graph[y][x] = -1;
        }
        else if (type == 2)
        {
            graph[x][n + y] = 1;
            graph[n + y][x] = -1;
        }
        else if (type == 3)
        {
            graph[n + x][n + y] = 1;
            graph[n + y][n + x] = -1;
        }
        else
        {
            graph[n + x][y] = 1;
            graph[y][n + x] = -1;
        }
    }

    floyd(total);

    vector<int> lazy_heroes;
    for (int i = 0; i < n; i++)
    {
        bool is_lazy = true;
        for (int j = 0; j < m; j++)
        {
            if (graph[i][n + j] != -1)
            {
                is_lazy = false;
                break;
            }
        }
        if (is_lazy)
        {
            lazy_heroes.push_back(i + 1);
        }
    }

    cout << lazy_heroes.size() << endl;
    if (lazy_heroes.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        for (int hero : lazy_heroes)
        {
            cout << hero << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        int max_wins = 0;
        for (int j = 0; j < m; j++)
        {
            if (graph[i][n + j] != -1)
            {
                max_wins++;
            }
        }
        cout << max_wins << " ";
    }
    cout << endl;

    return 0;
}