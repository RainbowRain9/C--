# ! sort排序

## 一、前置知识
- 数组和向量的基本操作
- 递归算法
- 堆数据结构
- 分治思想
- 时间复杂度分析

## 二、排序算法总览

### 1. 排序算法分类
- 比较类排序
  - 交换排序(冒泡、快速)
  - 插入排序(直接插入、希尔)
  - 选择排序(直接选择、堆排序)
  - 归并排序
- 非比较类排序
  - 计数排序
  - 桶排序
  - 基数排序

### 2. 算法对比
|算法|平均时间复杂度|最坏时间复杂度|最好时间复杂度|空间复杂度|稳定性|
|---|---|---|---|---|---|
|插入排序|O(n²)|O(n²)|O(n)|O(1)|稳定|
|冒泡排序|O(n²)|O(n²)|O(n)|O(1)|稳定|
|选择排序|O(n²)|O(n²)|O(n²)|O(1)|不稳定|
|希尔排序|O(n^1.3)|O(n²)|O(n)|O(1)|不稳定|
|堆排序|O(nlogn)|O(nlogn)|O(nlogn)|O(1)|不稳定|
|快速排序|O(nlogn)|O(n²)|O(nlogn)|O(logn)|不稳定|

## 三、算法详解

### 1. 插入排序
```cpp
void InsertSort(vector<int> &a) {
    for (int i = 1; i < a.size(); i++) {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}
```

#### 工作原理
- 将数组分为已排序和未排序两部分
- 从未排序部分取出一个元素
- 在已排序部分找到合适位置插入
- 重复直到所有元素都排序完成

#### 适用场景
- 小规模数据
- 基本有序的数据
- 数据量较小的嵌入式系统

### 2. 冒泡排序
```cpp
void BubbleSort(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}
```

#### 工作原理
- 比较相邻元素
- 如果前者大于后者则交换
- 每轮将最大元素"冒泡"到末尾
- 重复n-1轮完成排序

#### 优化方案
- 增加标志位记录是否发生交换
- 记录最后一次交换的位置

### 3. 选择排序
```cpp
void SelectSort(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        if (i != minIndex) {
            swap(a[i], a[minIndex]);
        }
    }
}
```

#### 工作原理
- 在未排序序列中找最小元素
- 将其与未排序序列的首位交换
- 重复直到所有元素排序完成

#### 特点
- 交换次数最少
- 不稳定排序
- 时间复杂度固定为O(n²)

### 4. 希尔排序
```cpp
void ShellSort(vector<int> &a) {
    int n = a.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {   
            int temp = a[i];
            int j = i - gap;
            while (j >= 0 && a[j] > temp) {
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j + gap] = temp;
        }
    }
}
```

#### 工作原理
- 将序列分成多个子序列
- 对每个子序列进行插入排序
- 逐步减小间隔直到为1
- 最后一次间隔为1时相当于直接插入排序

#### 间隔序列选择
- 原始希尔序列: n/2, n/4, ..., 1
- Hibbard序列: 2^k-1
- Sedgewick序列: 4^k+3*2^(k-1)+1

### 5. 堆排序
```cpp
void heapify(vector<int> &a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;

    if (i != largest) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void HeapSort(vector<int> &a) {
    int n = a.size();
    // 建堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    // 排序
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
```

#### 工作原理
- 将数组构建成最大堆
- 交换堆顶和末尾元素
- 重新调整堆结构
- 重复直到完成排序

#### 性能特点
- 时间复杂度稳定O(nlogn)
- 空间复杂度O(1)
- 不稳定排序

### 6. 快速排序
```cpp
int partition(vector<int> &a, int left, int right) {
    int pivot = a[left];
    while (left < right) {
        while (left < right && a[right] >= pivot)
            right--;
        a[left] = a[right];
        while (left < right && a[left] <= pivot)
            left++;
        a[right] = a[left];
    }
    a[left] = pivot;
    return left;
}

void QuickSort(vector<int> &a, int left, int right) {
    if (left < right) {
        int pos = partition(a, left, right);
        QuickSort(a, left, pos - 1);
        QuickSort(a, pos + 1, right);
    }
}
```

#### 工作原理
- 选择基准元素(pivot)
- 将小于pivot的元素放左边
- 将大于pivot的元素放右边
- 递归对左右两部分进行排序

#### 优化策略
- 三数取中选择pivot
- 小规模数据使用插入排序
- 处理重复元素的三路快排

## 四、实现要点

### 1. 代码规范
- 使用引用参数避免拷贝
- 合理使用swap函数
- 注意边界条件处理

### 2. 性能优化
- 选择合适的排序算法
- 针对数据特点优化
- 考虑空间和时间平衡

### 3. 实际应用
- 标准库sort实现
- 数据库索引排序
- 文件系统排序

## 五、常见问题

### 1. 稳定性问题
- 什么是排序稳定性
- 为什么需要稳定排序
- 如何保证排序稳定性

### 2. 性能问题
- 如何选择合适的排序算法
- 大数据量排序解决方案
- 外部排序的实现

### 3. 特殊情况
- 重复元素的处理
- 极端数据的处理
- 内存限制的处理

## 六、扩展阅读

### 1. 高级排序算法
- 归并排序
- 计数排序
- 基数排序

### 2. 并行排序
- 并行快速排序
- GPU排序算法
- 分布式排序

### 3. 应用场景
- 大规模数据排序
- 实时排序系统
- 多维数据排序

## 七、练习题目

### 1. 基础练习
- 实现各种排序算法
- 分析算法复杂度
- 处理边界情况

### 2. 进阶练习
- 优化排序算法
- 处理特殊数据
- 解决实际问题

### 3. 面试题
- 手写快速排序
- 分析算法优劣
- 设计特定场景的排序方案
