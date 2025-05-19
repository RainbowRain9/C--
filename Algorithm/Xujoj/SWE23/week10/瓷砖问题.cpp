#include <bits/stdc++.h>
#include <vector>
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

void rain()
{
    int w, h;
    cin >> w >> h;
    vector<string> grid(h);
    int x = -1, y = -1;
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == '!') {
                x = j;
                y = i;
            }
        }
    }
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    int count = 0;
    q.push({ x, y });
    visited[y][x] = true;

    int dy[] = { -1, 1, 0, 0 };
    int dx[] = { 0, 0, -1, 1 };

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;

        count++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (ny >= 0 && ny < h && nx >= 0 && nx < w && grid[ny][nx] == '*' && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ nx, ny });
            }
        }
    }
    cout << count << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        rain();
    }
    return 0;
}