#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

void rain()
{
    int n, V, W;
    cin >> n >> V >> W;

    vector<int> v;
    vector<double> c;

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        v.push_back(V);
        c.push_back(p);
    }

    while (true)
    {
        int x = -1, y = -1;
        double best = W + 1;

        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                double temp = (v[i] * c[i] + v[j] * c[j]) / (v[i] + v[j]);

                if (temp <= W && temp < best)
                {
                    x = i;
                    y = j;
                    best = temp;
                }
            }
        }

        if (x == -1)
            break;

        v[x] = v[x] + v[y];
        c[x] = best;

        v.erase(v.begin() + y);
        c.erase(c.begin() + y);
    }

    int maxV = 0;
    double maxC = 0.0;

    for (int i = 0; i < v.size(); i++)
    {
        if (c[i] <= W && v[i] > maxV)
        {
            maxV = v[i];
            maxC = c[i];
        }
    }

    if (maxV == 0)
    {
        cout << "0 0.00" << endl;
    }
    else
    {
        cout << maxV << " " << fixed << setprecision(2) << maxC / 100.0 << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    while (_--)
    {
        rain();
    }
    return 0;
}