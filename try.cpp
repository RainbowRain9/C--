#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int diff[100007]; // 差分数组  diff[i]表示a[i]-a[i-1]
int a[100007];    // 原数组
int pre[100007];  // 前缀和数组  pre[i]表示下标从1到i的所有a[i]的和

// 对差分数组做前缀和还原原数组
// 对前缀和数组做差分还原原数组

// for(int i=1;i<=n;i++)diff[i]=a[i]-a[i-1];

// 前缀和是O（1）查询区间值
// 差分是O（1）修改区间值

// pre[i]=a1+a2+...+ai
// a[i]=d1+d2+d3+....+di
// a1=d1
// a2=d1+d2
// a3=d1+d2+d3
//......

// d1++;之后再还原原数组，原数组会有什么区别
// a1-an都会++
// d[l]++;-->al-an全部++
// al=d1+...dl
// al+1=d1+...+dl+dl+1

// dl++ dl-dn++
// dl-dr++
// dr+1-dn--
// d[r+1]--

// pre[i]=pre[i-1]+a[i]

// b是diff的前缀和数组
// b[i]=b[i-1]+diff[i]
//  b       1   3  2  5   7   2

// c是pre数组的差分数组
// c[i]=pre[i]-pre[i-1]
// c   1  3  2  5  7   2

// diff    1   2  -1  3   2   -5
// a       1   3  2   5   7   2
// pre      1   4  6   11  18  20

int main()
{

    int n, c, d;
    cin >> n >> c >> d;
    while (d--) // O(q) q=1e5
    {
        int l, r;
        cin >> l >> r;
        diff[l]++, diff[r + 1]--;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        a[i] = diff[i] + a[i - 1];
        if (a[i] >= c)
            ans++;
    }
    cout << ans;
}