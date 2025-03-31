# ! next_permutation全排列

## 一、前置知识
- 排列组合基础
- 字典序概念
- 数组/字符串操作
- STL算法基础

## 二、算法介绍

### 1. 基本概念
- next_permutation是C++ STL中的一个算法
- 用于生成下一个字典序更大的排列
- 位于`<algorithm>`头文件中

### 2. 函数原型
```cpp
// 使用默认的<运算符比较
template <class BidirectionalIterator>
bool next_permutation (BidirectionalIterator first, BidirectionalIterator last);

// 使用自定义比较函数
template <class BidirectionalIterator, class Compare>
bool next_permutation (BidirectionalIterator first, BidirectionalIterator last, Compare comp);
```

### 3. 返回值
- true: 成功生成下一个排列
- false: 已经是最后一个排列

## 三、算法原理

### 1. 核心思路
1. 从后向前查找第一个相邻的升序对(i,i+1),记录位置i
2. 从后向前查找第一个大于position[i]的元素,记录位置j
3. 交换i,j位置的元素
4. 将i+1到末尾的元素反转

### 2. 图解过程
```
例如序列: 1 2 3
第一次调用:
1. 找到2,3是升序对
2. 3大于2
3. 交换2,3
4. 反转后面的序列
得到: 1 3 2

第二次调用:
1. 找到1,3是升序对
2. 2大于1
3. 交换1,2
4. 反转后面的序列
得到: 2 1 3

以此类推...
```

## 四、代码实现

### 1. STL源码分析
```cpp
template <class BidirectionalIterator>
bool next_permutation(BidirectionalIterator first, BidirectionalIterator last) {
    if (first == last) return false;
    BidirectionalIterator i = last;
    if (first == --i) return false;

    while (true) {
        BidirectionalIterator i1, i2;
        
        i1 = i;
        if (*--i < *i1) {                  // 找到第一个升序对
            i2 = last;
            while (!(*i < *--i2));         // 找到第一个大于*i的元素
            iter_swap(i, i2);              // 交换元素
            reverse(i1, last);             // 反转后续序列
            return true;
        }
        if (i == first) {                  // 已经是最后一个排列
            reverse(first, last);
            return false;
        }
    }
}
```

### 2. 使用示例
```cpp
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3};
    
    do {
        // 处理当前排列
        for(int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    } while(next_permutation(nums.begin(), nums.end()));
    
    return 0;
}
```

## 五、应用场景

### 1. 排列问题
```cpp
// 生成1-n的所有排列
vector<int> nums(n);
for(int i = 0; i < n; i++) nums[i] = i + 1;
do {
    // 处理当前排列
} while(next_permutation(nums.begin(), nums.end()));
```

### 2. 字符串排列
```cpp
// 生成字符串的所有排列
string str = "abc";
do {
    cout << str << endl;
} while(next_permutation(str.begin(), str.end()));
```

### 3. 在本题中的应用
```cpp
// 使用next_permutation解决三位数问题
vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
do {
    int num1 = nums[0]*100 + nums[1]*10 + nums[2];
    int num2 = nums[3]*100 + nums[4]*10 + nums[5];
    int num3 = nums[6]*100 + nums[7]*10 + nums[8];
    if(num2 == 2*num1 && num3 == 3*num1) {
        cout << num1 << " " << num2 << " " << num3 << endl;
    }
} while(next_permutation(nums.begin(), nums.end()));
```

## 六、复杂度分析

### 1. 时间复杂度
- 单次调用: O(n)
- 生成所有排列: O(n!)

### 2. 空间复杂度
- O(1) 原地修改

### 3. 性能优化
- 提前剪枝
- 避免不必要的排列
- 利用问题特性减少搜索空间

## 七、使用注意事项

### 1. 前提条件
- 序列必须有序(升序)
- 迭代器必须是双向迭代器
- 元素必须支持比较操作

### 2. 常见错误
```cpp
// 错误:序列未排序
vector<int> nums = {3, 1, 2};
next_permutation(nums.begin(), nums.end()); // 可能错过部分排列

// 正确:先排序
sort(nums.begin(), nums.end());
next_permutation(nums.begin(), nums.end());
```

### 3. 处理重复元素
```cpp
// 重复元素会生成重复排列
vector<int> nums = {1, 1, 2};
// 需要去重或使用set等数据结构
```

## 八、相关算法

### 1. prev_permutation
- 生成上一个字典序的排列
- 使用方法类似

### 2. 其他生成排列的方法
- 递归回溯
- 康托展开
- 字典序法

## 九、实战技巧

### 1. 代码模板
```cpp
// 生成排列的通用模板
vector<int> nums = {...};
sort(nums.begin(), nums.end()); // 保证升序
do {
    // 处理当前排列
} while(next_permutation(nums.begin(), nums.end()));
```

### 2. 优化建议
- 根据具体问题特点剪枝
- 合理使用break和continue
- 注意边界条件处理

### 3. 调试技巧
- 使用小规模数据测试
- 打印中间结果
- 验证排列的正确性

## 十、练习题目

### 1. 相关题目
1. [全排列](https://leetcode.cn/problems/permutations/) - 使用next_permutation生成排列
2. [字符串的排列](https://leetcode.cn/problems/permutation-in-string/) - 排列在字符串中的应用

### 2. 提高练习
- 带重复元素的排列
- 带约束条件的排列
- 特定模式的排列生成
