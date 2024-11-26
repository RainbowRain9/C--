/*
描述
N个学生去海岛游玩，只带了一个hrr牌充电宝，可以为所有学生的手机充电。
第i个学生的手机具有百分之p[i]的电量，充电宝总共可以充百分之M的电量。
问最多可以有几台手机的电量达到百分之百。

输入
只有一组案例。

第一行是两个整数N和M(0≤N≤100,0≤M≤10000)，第二行包含N个整数p[i]
(0≤p[i]≤100)表示第i台手机剩余电量的百分比。

输出
一个整数，表示最多可以充的手机台数。不要换行。

样例输入
3 10
100 99 90

样例输出
2
*/
#include <iostream>
using namespace std;
template <typename T>
void selSort(T a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}
int main()
{
    int N, M;
    cin >> N >> M;
    int *a = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    selSort(a, N);
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] + M < 100)
		{
			break;
		}

		cnt++;
		M = a[i] + M - 100;	
	}
    cout << cnt;
    return 0;
}