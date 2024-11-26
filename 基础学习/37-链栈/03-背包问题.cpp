// Source : https://xujcoj.com/home/contest/1957/problem/3
// Date   : 2024-11-14

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// 定义物品结构体
struct Item
{
    int weight;   // 物品重量
    int value;    // 物品价值
    double ratio; // 价值重量比
};

// 比较函数，用于排序
bool compareItems(Item a, Item b)
{
    return a.ratio > b.ratio; // 按照价值重量比从大到小排序
}

// 背包问题求解函数
// w: 重量数组
// v: 价值数组
// n: 物品数量
// C: 背包容量
double KnapSack(int *w, int *v, int n, int C)
{
    vector<Item> items(n); // 创建物品数组

    // 初始化物品数组，计算每个物品的价值重量比
    for (int i = 0; i < n; i++)
    {
        items[i].weight = w[i];
        items[i].value = v[i];
        items[i].ratio = (double)v[i] / w[i];
    }

    // 按照价值重量比排序
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0; // 总价值
    int currentWeight = 0; // 当前重量

    // 遍历排序后的物品
    for (int i = 0; i < n; i++)
    {
        // 如果当前物品可以完全装入背包
        if (currentWeight + items[i].weight <= C)
        {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        }
        // 如果当前物品只能部分装入背包
        else
        {
            int remainWeight = C - currentWeight;        // 计算剩余容量
            totalValue += items[i].ratio * remainWeight; // 按比例添加价值
            break;                                       // 背包已满，退出循环
        }
    }

    return totalValue;
}

int main()
{
    int n = 3;
    int w[] = {10, 30, 20};
    int v[] = {50, 120, 60};
    int C;

    // cout << "请输入背包的容量: ";
    cin >> C; // C的范围是[30,60]

    // cout << "背包获得的最大价值是: ";
    cout << KnapSack(w, v, n, C) << endl;

    return 0;
}