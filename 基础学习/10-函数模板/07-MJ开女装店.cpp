/*
描述
MJ开了一间女装店，规定每件衣服的价格是m元。MJ同时又推出了两项优惠活动：

1、多买优惠活动：第2件衣服的售价比原价低1元，第3件衣服的售价比原价低2元，以此类推，第t件衣服的售价比原价低t-1元。
但如果某件衣服优惠后的价格低于p元，那么就按p元销售。

2、学弟优惠活动：如果是学弟前来购买，则在第1项优惠算好总价格后，
再次进行九折优惠，并且只收九折计算后的整数部分。

现在已知某人来MJ的女装店买了t件衣服，问优惠后的总价格是多少？

输入
一个正整数n，表示有n组案例。

每组案例由3个正整数m、t和p，以及一个字符c组成，
其中m代表一件衣服的原价，t代表买衣服的件数，p表示多买打折优惠中的最低售价，c等于Y时表示是学弟，
等于N时表示不是学弟。（1<=p<=m<=1000, 1<=t<=1000）

输出
针对每组案例，输入一个正整数，表示优惠后的总价格。

每组案例输出完都要换行。

样例输入
2

10 1 5 Y

10 3 9 N

样例输出
9

28
*/

#include <iostream>
using namespace std;

// 计算优惠后的总价格
// 参数：m - 单件衣服的原价，t - 购买的衣服件数，p - 优惠价格的下限，isStudent - 是否是学弟
int calculatePrice(int m, int t, int p, bool isStudent) {
    int totalPrice = 0;  // 初始化总价格为0
    for (int i = 0; i < t; ++i) {
        int discountedPrice = m - i;  // 计算每件衣服的折扣价
        if (discountedPrice < p) {  // 如果折扣价低于最低售价p
            discountedPrice = p;  // 则将价格设为p
        }
        totalPrice += discountedPrice;  // 累加到总价格
    }

    if (isStudent) {  // 如果是学弟
        totalPrice = (totalPrice * 9) / 10;  // 应用10%的折扣
    }

    return totalPrice;  // 返回计算后的总价格
}

int main() {
    int n;  // 案例数量
    cin >> n;
    while (n--) {  // 循环处理每个案例
        int m, t, p;  // m - 单价，t - 数量，p - 优惠下限
        char c;  // Y或N，表示是否是学弟
        cin >> m >> t >> p >> c;
        bool isStudent = (c == 'Y');  // 判断是否是学弟
        cout << calculatePrice(m, t, p, isStudent) << endl;  // 输出计算结果
    }
    return 0;
}

