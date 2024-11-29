#include <iostream>

using namespace std;

const int MaxSize = 100;

class MGraph
{
private:
    char vertex[MaxSize];
    int edge[MaxSize][MaxSize];
    int visited[MaxSize];
    int vertexNum, edgeNum;

public:
    MGraph(char a[], int n, int e)
    {
        vertexNum = n;
        edgeNum = e;
        for (int i = 0; i < vertexNum; i++)
        {
            vertex[i] = a[i];
        }
        for (int i = 0; i < vertexNum; i++)
        {
            for (int j = 0; j < vertexNum; j++)
            {
                edge[i][j] = 0;
            }
        }
        for (int i = 0; i < vertexNum; i++)
        {
            visited[i] = 0;
        }
        for (int k = 0; k < edgeNum; k++)
        {
            int i, j;
            cin >> i >> j;
            edge[i][j] = 1;
            edge[j][i] = 1;
        }
    }

    void DFTraverse(int v)
    {
        cout << vertex[v];
        visited[v] = 1;
        for (int j = 0; j < vertexNum; j++)
        {
            if (edge[v][j] == 1 && !visited[j])
            {
                DFTraverse(j);
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    char *a = new char[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int e;
    cin >> e;
    MGraph graph(a, n, e);
    graph.DFTraverse(0);
    cout << endl;
    delete[] a;
    return 0;
}
