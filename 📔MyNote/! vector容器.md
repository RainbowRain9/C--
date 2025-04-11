# ! vector容器

## 一、基础概念与创建 (Day 1-2)

### 1. 什么是 `vector`？
- `vector` 是 C++ 标准模板库 (STL) 中的一个**序列容器**。
- 它封装了一个**动态数组**，能够根据需要自动调整大小。
- 元素在内存中是**连续存储**的，这使得它支持快速的随机访问。
- 需要包含头文件 `<vector>`。

### 2. 创建 `vector`
```cpp
#include <vector>
#include <iostream>
#include <string>

// 假设在作用域顶部使用了 using namespace std;
using namespace std; 

int main() {
    // 1. 创建空 vector
    vector<int> v1; 

    // 2. 创建指定大小的 vector，元素初始化为默认值 (int 为 0)
    vector<int> v2(5); // 大小为 5，包含 {0, 0, 0, 0, 0}

    // 3. 创建指定大小的 vector，并指定初始值
    vector<string> v3(3, "hello"); // 大小为 3，包含 {"hello", "hello", "hello"}

    // 4. 使用初始化列表创建 (C++11 及以后)
    vector<double> v4 = {1.1, 2.2, 3.3}; 
    vector<double> v4_alt {1.1, 2.2, 3.3}; // 另一种写法

    // 5. 从另一个 vector 或迭代器范围创建 (拷贝构造)
    vector<double> v5(v4);             // 拷贝 v4
    vector<int> v6(v2.begin(), v2.begin() + 3); // 从 v2 的前 3 个元素创建 {0, 0, 0}

    return 0;
}
```

### 3. 基本信息查询
```cpp
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3};
    
    // 获取元素数量
    cout << "Size: " << v.size() << endl; // 输出 3

    // 检查是否为空
    cout << "Is empty? " << (v.empty() ? "Yes" : "No") << endl; // 输出 No

    // 获取当前分配的容量 (可能大于 size)
    cout << "Capacity: " << v.capacity() << endl; // 输出 >= 3 (具体值依赖实现)

    // 获取最大可能容纳的元素数
    cout << "Max size: " << v.max_size() << endl; // 输出一个很大的数

    return 0;
}
```

### 4. 理解内存模型：`size` vs `capacity`
- `size()`: `vector` 中实际存储的元素数量。
- `capacity()`: `vector` 在不重新分配内存的情况下可以容纳的元素数量。`capacity() >= size()` 总是成立。
- 当 `push_back` 或 `insert` 导致 `size` 将要超过 `capacity` 时，`vector` 会**重新分配**一块更大的内存（通常是当前容量的 1.5 或 2 倍，具体因子依赖 STL 实现），将旧元素**移动或拷贝**到新内存，然后释放旧内存。这是一个**耗时**操作。

```cpp
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> v;
    cout << "Initial -> Size: " << v.size() << ", Capacity: " << v.capacity() << endl;
    
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
        cout << "After push_back(" << i << ") -> Size: " << v.size() 
             << ", Capacity: " << v.capacity() << endl; 
    }
    // 观察 capacity 如何在 size 增长时跳跃式增加
    return 0;
}
```

## 二、核心操作 (Day 3-5)

### 1. 元素访问
```cpp
#include <vector>
#include <iostream>
#include <stdexcept> // for out_of_range

using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40};

    // 1. 使用下标 `[]` (不进行边界检查，速度快但可能不安全)
    int first = v[0];       // first = 10
    cout << "v[1]: " << v[1] << endl; // 输出 20
    // int dangerous = v[10]; // 越界！行为未定义，可能崩溃或读到垃圾数据

    // 2. 使用 `at()` (进行边界检查，越界时抛出 out_of_range 异常，更安全)
    int second = v.at(1);   // second = 20
    cout << "v.at(2): " << v.at(2) << endl; // 输出 30
    try {
        int error = v.at(10); // 会抛出异常
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl; // 输出错误信息
    }

    // 3. 访问第一个元素 `front()`
    int first_alt = v.front(); // first_alt = 10
    cout << "Front: " << v.front() << endl; 

    // 4. 访问最后一个元素 `back()`
    int last = v.back();       // last = 40
    cout << "Back: " << v.back() << endl; 

    // 5. 获取底层数组指针 `data()` (C++11)
    int* raw_array = v.data();
    cout << "Data[0]: " << raw_array[0] << endl; // 输出 10
    cout << "Data[1]: " << *(v.data() + 1) << endl; // 输出 20

    return 0;
}
```
**注意:** 对空 `vector` 调用 `front()` 或 `back()` 会导致未定义行为。

### 2. 添加元素
```cpp
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct MyData {
    int id;
    string name;
    MyData(int i, string s) : id(i), name(move(s)) { cout << "Constructed MyData(" << id << ")" << endl; }
    // 必须有拷贝或移动构造函数才能用于 vector
    MyData(const MyData& other) : id(other.id), name(other.name) { cout << "Copied MyData(" << id << ")" << endl; }
    MyData(MyData&& other) noexcept : id(other.id), name(move(other.name)) { cout << "Moved MyData(" << id << ")" << endl; }
};

int main() {
    vector<int> v_int = {1, 2};

    // 1. 在末尾添加元素 `push_back()`
    v_int.push_back(3); // v_int: {1, 2, 3}
    v_int.push_back(4); // v_int: {1, 2, 3, 4}
    cout << "v_int after push_back: ";
    for(int x : v_int) cout << x << " ";
    cout << endl;

    // 2. 在指定位置插入元素 `insert()`
    // insert(iterator pos, const value_type& val);
    auto it_insert = v_int.insert(v_int.begin() + 1, 99); // 在索引 1 处插入 99
    // v_int: {1, 99, 2, 3, 4}
    // it_insert 指向新插入的元素 99
    cout << "Inserted element: " << *it_insert << endl; 

    // insert(iterator pos, size_type count, const value_type& val);
    v_int.insert(v_int.end(), 2, 55); // 在末尾插入 2 个 55
    // v_int: {1, 99, 2, 3, 4, 55, 55}

    // insert(iterator pos, InputIt first, InputIt last);
    vector<int> src = {100, 200};
    v_int.insert(v_int.begin(), src.begin(), src.end()); // 在开头插入 src 的所有元素
    // v_int: {100, 200, 1, 99, 2, 3, 4, 55, 55}
    
    cout << "v_int after insert: ";
    for(int x : v_int) cout << x << " ";
    cout << endl;


    // 3. 在末尾就地构造元素 `emplace_back()` (C++11, 更高效，避免额外拷贝/移动)
    vector<MyData> v_data;
    cout << "\n--- emplace_back ---" << endl;
    v_data.emplace_back(1, "Alice"); // 直接在 vector 内部构造 MyData 对象
    
    cout << "--- push_back ---" << endl;
    MyData bob(2, "Bob");
    v_data.push_back(bob); // 会调用拷贝构造函数 (如果 MyData 有移动构造，则优先移动)
    
    cout << "--- push_back (temporary) ---" << endl;
    v_data.push_back(MyData(3, "Charlie")); // 创建临时对象，然后移动（或拷贝）进 vector


    // 4. 在指定位置就地构造元素 `emplace()` (C++11)
    cout << "\n--- emplace ---" << endl;
    auto it_emplace = v_data.emplace(v_data.begin(), 0, "Zero"); // 在开头构造 id=0 的对象
    // it_emplace 指向新构造的元素
    cout << "Emplaced element name: " << it_emplace->name << endl;

    return 0;
}
```
**关键点**: `emplace_back` 和 `emplace` 通常比 `push_back` 和 `insert` 更高效，因为它们直接在容器管理的内存中构造对象，减少了不必要的临时对象创建和拷贝/移动操作。

### 3. 删除元素
```cpp
#include <vector>
#include <iostream>
#include <algorithm> // for remove, remove_if

using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50, 60};

    // 1. 删除末尾元素 `pop_back()` (效率高)
    v.pop_back(); // v: {10, 20, 30, 40, 50}
    v.pop_back(); // v: {10, 20, 30, 40}
    cout << "After pop_back: ";
    for(int x : v) cout << x << " ";
    cout << endl;

    // 2. 删除指定位置的元素 `erase(iterator pos)` (效率较低，需移动后续元素)
    auto it_erase = v.erase(v.begin() + 1); // 删除索引 1 的元素 (20)
    // v: {10, 30, 40}
    // it_erase 指向被删除元素之后的元素 (30)
    cout << "Element after erased: " << *it_erase << endl;
    cout << "After erase(pos): ";
    for(int x : v) cout << x << " ";
    cout << endl;


    // 3. 删除指定范围的元素 `erase(iterator first, iterator last)`
    v = {10, 20, 30, 40, 50, 60};
    auto it_erase_range = v.erase(v.begin() + 1, v.begin() + 4); // 删除索引 [1, 4) 的元素 (20, 30, 40)
    // v: {10, 50, 60}
    // it_erase_range 指向被删除范围之后的元素 (50)
    cout << "Element after erased range: " << *it_erase_range << endl;
    cout << "After erase(range): ";
    for(int x : v) cout << x << " ";
    cout << endl;

    // 4. 清空所有元素 `clear()`
    v.clear(); // v: {}
    cout << "After clear, size: " << v.size() << ", capacity: " << v.capacity() << endl; 
    // 注意：clear 只改变 size，不改变 capacity

    // 5. 删除特定值的元素 (remove-erase idiom)
    v = {1, 2, 3, 2, 4, 2, 5};
    // remove 把所有不等于 2 的元素移到前面，并返回新的逻辑终点
    auto new_end = remove(v.begin(), v.end(), 2); 
    // v 此时可能是 {1, 3, 4, 5, ?, ?, ?} (问号部分是未定义但有效的元素)
    // new_end 指向第一个问号的位置
    cout << "Vector after remove(2): ";
    for(auto it = v.begin(); it != v.end(); ++it) cout << *it << " ";
    cout << endl;
    cout << "New logical end index: " << distance(v.begin(), new_end) << endl;

    v.erase(new_end, v.end()); // 删除从 new_end 到末尾的所有元素
    // v: {1, 3, 4, 5}
    cout << "Vector after erase(new_end, end): ";
    for(int x : v) cout << x << " ";
    cout << endl;

    // 6. 删除满足条件的元素 (remove_if-erase idiom)
    v = {1, 2, 3, 4, 5, 6, 7, 8};
    // 删除所有偶数
    auto new_end_if = remove_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
    v.erase(new_end_if, v.end());
    // v: {1, 3, 5, 7}
    cout << "Vector after removing even numbers: ";
    for(int x : v) cout << x << " ";
    cout << endl;


    return 0;
}
```
**重要**: `insert` 和 `erase` 操作（除了在末尾进行）可能会导致**迭代器失效**，需要谨慎处理返回值或重新获取迭代器。`push_back`, `emplace_back`, `pop_back` 如果不引起内存重新分配，通常不会使指向其他元素的迭代器失效，但可能使 `end()` 迭代器失效。如果发生内存重新分配，所有迭代器、指针和引用都会失效。

### 4. 修改元素和容器
```cpp
#include <vector>
#include <iostream>
#include <algorithm> // for swap

using namespace std;

int main() {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {10, 20};

    // 1. 修改单个元素 (通过下标或迭代器)
    v1[0] = 11;       // v1: {11, 2, 3}
    *(v1.begin() + 1) = 22; // v1: {11, 22, 3}
    v1.at(2) = 33;    // v1: {11, 22, 33}

    cout << "v1 after modification: ";
    for(int x : v1) cout << x << " ";
    cout << endl;

    // 2. 重新赋值整个 vector `assign()`
    // assign(size_type count, const value_type& value);
    v1.assign(5, 99); // v1 变为包含 5 个 99: {99, 99, 99, 99, 99}
    cout << "v1 after assign(count, val): ";
    for(int x : v1) cout << x << " ";
    cout << endl;
    
    // assign(InputIt first, InputIt last);
    v1.assign(v2.begin(), v2.end()); // v1 变为 v2 的拷贝: {10, 20}
    cout << "v1 after assign(iterators): ";
    for(int x : v1) cout << x << " ";
    cout << endl;

    // assign(initializer_list<value_type> ilist); (C++11)
    v1.assign({100, 200, 300}); // v1: {100, 200, 300}
    cout << "v1 after assign(initializer_list): ";
    for(int x : v1) cout << x << " ";
    cout << endl;

    // 3. 交换两个 vector 的内容 `swap()` (效率非常高，只交换内部指针)
    v1 = {1, 1, 1};
    v2 = {2, 2};
    cout << "Before swap: v1.size=" << v1.size() << ", v2.size=" << v2.size() << endl;
    v1.swap(v2); // 或者 swap(v1, v2);
    cout << "After swap: v1.size=" << v1.size() << ", v2.size=" << v2.size() << endl; // size 会交换
    cout << "v1 after swap: "; for(int x : v1) cout << x << " "; cout << endl; // 输出 2 2
    cout << "v2 after swap: "; for(int x : v2) cout << x << " "; cout << endl; // 输出 1 1 1
    // swap 不会导致迭代器失效（迭代器仍指向原容器，但内容变了），并且保证不抛出异常。

    return 0;
}
```

## 三、迭代器与遍历 (Day 3-5)

### 1. `begin()` 和 `end()`
- `begin()`: 返回指向第一个元素的**正向迭代器**。
- `end()`: 返回指向**末尾元素之后**位置的正向迭代器（不是最后一个元素！）。
- 用于构成左闭右开的区间 `[begin, end)`。

### 2. `rbegin()` 和 `rend()` (反向迭代)
- `rbegin()`: 返回指向最后一个元素的**反向迭代器**。
- `rend()`: 返回指向**第一个元素之前**位置的反向迭代器。
- 用于构成反向的左闭右开区间 `[rbegin, rend)`。

### 3. `cbegin()`, `cend()`, `crbegin()`, `crend()` (常量迭代器, C++11)
- 功能同上，但返回的是**常量迭代器 (`const_iterator` 或 `const_reverse_iterator`)**。
- 通过常量迭代器只能读取元素，不能修改。
- 用于在 `const` 成员函数中或不希望修改 `vector` 内容时进行遍历。

### 4. 遍历方式
```cpp
#include <vector>
#include <iostream>
#include <iterator> // for ostream_iterator

using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    // 1. 使用索引的 for 循环 (简单，但可能不如迭代器通用)
    cout << "Index loop: ";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " "; // 或 v.at(i)
    }
    cout << endl;

    // 2. 使用正向迭代器的 for 循环 (最通用)
    cout << "Iterator loop: ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " "; // 使用 * 解引用获取元素值
        // *it = 99; // 可以修改元素
    }
    cout << endl;
    // 使用 auto 简化 (C++11)
    cout << "Auto Iterator loop: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 3. 使用基于范围的 for 循环 (C++11, 最简洁推荐)
    cout << "Range-based for loop (read-only copy): ";
    for (int x : v) { // x 是 v 中元素的拷贝
        cout << x << " ";
        // x = 99; // 修改 x 不会影响 v
    }
    cout << endl;

    cout << "Range-based for loop (reference, modifiable): ";
    for (int& x : v) { // x 是 v 中元素的引用
        cout << x << " ";
        x += 1; // 可以修改 v 中的元素
    }
    cout << endl;
    cout << "Vector after modification: ";
    for (int x : v) cout << x << " "; cout << endl; // 输出 11 21 31 41 51

    cout << "Range-based for loop (const reference, read-only): ";
    for (const int& x : v) { // x 是 v 中元素的常量引用 (高效只读)
        cout << x << " ";
        // x = 99; // 编译错误
    }
    cout << endl;


    // 4. 使用反向迭代器
    cout << "Reverse iterator loop: ";
    for (auto rit = v.rbegin(); rit != v.rend(); ++rit) {
        cout << *rit << " "; // 输出 51 41 31 21 11
    }
    cout << endl;

    // 5. 使用常量迭代器 (例如在 const 函数中)
    cout << "Const iterator loop: ";
    for (auto cit = v.cbegin(); cit != v.cend(); ++cit) {
        cout << *cit << " ";
        // *cit = 99; // 编译错误
    }
    cout << endl;

    // 6. 使用 STL 算法 (如 copy)
    cout << "Using copy algorithm: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
```

## 四、性能与内存管理 (Day 5-7)

### 1. 预分配空间 `reserve()`
- 当你能预估 `vector` 大致需要存储多少元素时，使用 `reserve()` 提前分配足够的容量。
- 这可以显著**避免**在 `push_back` 或 `insert` 过程中发生**多次内存重新分配**，提高性能。
- `reserve(n)` 确保 `capacity()` 至少为 `n`。如果 `n` 小于等于当前 `capacity()`，则什么也不做。

```cpp
#include <vector>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    const int N = 10000000; // 一千万

    // 不预分配
    auto start1 = high_resolution_clock::now();
    vector<int> v1;
    for(int i = 0; i < N; ++i) v1.push_back(i);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end1 - start1);
    cout << "Without reserve: " << duration1.count() << "ms, Capacity: " << v1.capacity() << endl;

    // 预分配
    auto start2 = high_resolution_clock::now();
    vector<int> v2;
    v2.reserve(N); // 关键步骤
    for(int i = 0; i < N; ++i) v2.push_back(i);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end2 - start2);
    cout << "With reserve:    " << duration2.count() << "ms, Capacity: " << v2.capacity() << endl;

    // 可以看到预分配后性能提升明显，capacity 正好是 N (或稍大)
    return 0;
}
```

### 2. 调整大小 `resize()`
- `resize(new_size)`: 改变 `vector` 的 `size()` 到 `new_size`。
    - 如果 `new_size` > `size()`: 在末尾添加 `new_size - size()` 个默认构造的元素。如果需要，会增加 `capacity`。
    - 如果 `new_size` < `size()`: 删除末尾 `size() - new_size` 个元素。`capacity` **不变**。
- `resize(new_size, value)`: 同上，但新添加的元素是 `value` 的拷贝。

```cpp
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3};
    cout << "Initial: size=" << v.size() << ", capacity=" << v.capacity() << endl;

    v.resize(5); // 扩展大小，用 0 填充
    cout << "After resize(5): size=" << v.size() << ", capacity=" << v.capacity() << ", elements: ";
    for(int x: v) cout << x << " "; cout << endl; // 输出 1 2 3 0 0

    v.resize(7, 99); // 扩展大小，用 99 填充
    cout << "After resize(7, 99): size=" << v.size() << ", capacity=" << v.capacity() << ", elements: ";
    for(int x: v) cout << x << " "; cout << endl; // 输出 1 2 3 0 0 99 99

    v.resize(2); // 缩小大小，删除末尾元素
    cout << "After resize(2): size=" << v.size() << ", capacity=" << v.capacity() << ", elements: ";
    for(int x: v) cout << x << " "; cout << endl; // 输出 1 2 (capacity 不变)

    return 0;
}
```

### 3. 收缩容量 `shrink_to_fit()` (C++11)
- 请求 `vector` 释放未使用的内存，使 `capacity()` 尽可能接近 `size()`。
- 这**不是强制性**的，具体实现可以忽略此请求。
- 如果 `vector` 包含大量元素后又删除了很多，导致 `capacity` 远大于 `size`，可以使用此函数尝试回收内存。

```cpp
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> v;
    v.reserve(100); // 分配大容量
    v.push_back(1);
    v.push_back(2);
    cout << "Before shrink: size=" << v.size() << ", capacity=" << v.capacity() << endl; // size=2, capacity=100

    v.shrink_to_fit(); // 请求收缩容量

    cout << "After shrink: size=" << v.size() << ", capacity=" << v.capacity() << endl; // capacity 可能会减小到接近 2

    // 传统的 Swap Trick (C++11 前常用，现在仍有效)
    vector<int>(v).swap(v); // 创建一个临时 vector (拷贝 v)，其 capacity 正好是 v.size()，然后交换
    cout << "After swap trick: size=" << v.size() << ", capacity=" << v.capacity() << endl; 

    return 0;
}
```

## 五、与 STL 算法结合 (Day 7-10)

`vector` 的连续内存和迭代器使其能高效地与 `<algorithm>` 头中的各种算法配合使用。

```cpp
#include <vector>
#include <iostream>
#include <algorithm> // for sort, find, count, copy, reverse, etc.
#include <numeric>   // for accumulate, iota
#include <iterator>  // for ostream_iterator

using namespace std;

int main() {
    vector<int> v = {5, 2, 8, 1, 9, 2, 7};

    // 1. 排序 `sort()`
    sort(v.begin(), v.end()); // 默认升序
    // v: {1, 2, 2, 5, 7, 8, 9}
    cout << "Sorted: "; copy(v.begin(), v.end(), ostream_iterator<int>(cout, " ")); cout << endl;

    // 排序降序
    sort(v.begin(), v.end(), greater<int>()); // 使用比较器
    // v: {9, 8, 7, 5, 2, 2, 1}
    cout << "Sorted descending: "; copy(v.begin(), v.end(), ostream_iterator<int>(cout, " ")); cout << endl;

    // 2. 查找 `find()`, `find_if()`
    auto it_find = find(v.begin(), v.end(), 5); // 查找第一个 5
    if (it_find != v.end()) {
        cout << "Found 5 at index: " << distance(v.begin(), it_find) << endl;
    } else {
        cout << "5 not found" << endl;
    }

    auto it_find_if = find_if(v.begin(), v.end(), [](int x){ return x % 2 == 0 && x > 6; }); // 查找第一个大于6的偶数 (8)
    if (it_find_if != v.end()) {
        cout << "Found first even > 6: " << *it_find_if << endl;
    }

    // 3. 计数 `count()`, `count_if()`
    int count_2 = count(v.begin(), v.end(), 2); // 统计 2 出现的次数
    cout << "Count of 2: " << count_2 << endl;

    int count_odd = count_if(v.begin(), v.end(), [](int x){ return x % 2 != 0; }); // 统计奇数个数
    cout << "Count of odd numbers: " << count_odd << endl;

    // 4. 数值计算 `accumulate()`
    long long sum = accumulate(v.begin(), v.end(), 0LL); // 计算总和 (用 long long 避免溢出)
    cout << "Sum: " << sum << endl;
    
    // 计算乘积 (初始值为 1)
    long long product = accumulate(v.begin(), v.end(), 1LL, multiplies<long long>());
    cout << "Product: " << product << endl;

    // 5. 填充与生成 `fill()`, `iota()`
    vector<int> v_fill(5);
    fill(v_fill.begin(), v_fill.end(), -1); // 填充 -1
    cout << "Filled vector: "; copy(v_fill.begin(), v_fill.end(), ostream_iterator<int>(cout, " ")); cout << endl;

    vector<int> v_iota(10);
    iota(v_iota.begin(), v_iota.end(), 100); // 生成 100, 101, 102, ...
    cout << "Iota vector: "; copy(v_iota.begin(), v_iota.end(), ostream_iterator<int>(cout, " ")); cout << endl;

    // 6. 拷贝与变换 `copy()`, `transform()`
    vector<int> v_copy;
    v_copy.resize(v.size()); // 需要先分配足够空间
    copy(v.begin(), v.end(), v_copy.begin()); // 拷贝 v 到 v_copy

    vector<int> v_squared;
    v_squared.resize(v.size());
    transform(v.begin(), v.end(), v_squared.begin(), [](int x){ return x * x; }); // 计算平方
    cout << "Squared vector: "; copy(v_squared.begin(), v_squared.end(), ostream_iterator<int>(cout, " ")); cout << endl;

    // 7. 反转 `reverse()`
    reverse(v.begin(), v.end()); // 反转容器元素顺序
    cout << "Reversed vector: "; copy(v.begin(), v.end(), ostream_iterator<int>(cout, " ")); cout << endl;

    // 8. 查找最大最小值
    auto max_it = max_element(v.begin(), v.end());
    auto min_it = min_element(v.begin(), v.end());
    cout << "Max: " << *max_it << ", Min: " << *min_it << endl;

    int max_idx = distance(v.begin(), max_element(v.begin(), v.end()));
    int min_idx = distance(v.begin(), min_element(v.begin(), v.end()));
    cout << "Max index: " << max_idx << ", Min index: " << min_idx << endl;

    return 0;
}
```

## 六、高级特性与注意事项 (Day 10-15)

### 1. 迭代器失效 (Iterator Invalidation)
- **关键**: 任何可能导致内存**重新分配**的操作 (`push_back`, `insert`, `emplace`, `reserve`, `resize` 扩展大小) 都会使**所有**指向该 `vector` 的迭代器、指针和引用失效。
- `erase` 操作会使指向**被删除元素及之后**所有元素的迭代器、指针和引用失效。
- `insert` 操作（如果未发生重分配）会使指向**插入点及之后**所有元素的迭代器、指针和引用失效。
- `pop_back` （如果未发生重分配）仅使 `end()` 迭代器和指向最后一个元素的迭代器失效。
- `swap`, `clear`, `assign` 等操作也可能导致迭代器失效。
- **最佳实践**: 在执行可能使迭代器失效的操作后，**不要**再使用旧的迭代器，应重新获取或使用操作的返回值（如 `erase` 返回指向下一个有效元素的迭代器）。

```cpp
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    auto it = v.begin() + 2; // 指向 3

    // 错误示例: erase 后继续使用旧迭代器
    // v.erase(v.begin()); // 删除 1，it 现在可能失效 (取决于实现，但逻辑上已失效)
    // cout << *it << endl; // 危险！

    // 正确示例: 使用 erase 的返回值
    v = {1, 2, 3, 4, 5};
    it = v.begin() + 1; // 指向 2
    it = v.erase(it);   // 删除 2，it 现在指向 3
    cout << "After erasing 2, iterator points to: " << *it << endl; // 输出 3

    // 错误示例: push_back 可能导致重分配
    v = {1, 2, 3};
    it = v.begin(); // 指向 1
    v.reserve(3);  // capacity 恰好为 3
    v.push_back(4); // 可能发生重分配！
    // cout << *it << endl; // 危险！it 可能已失效

    return 0;
}
```

### 2. `vector<bool>` 的特殊化
- `vector<bool>` 是一个**特化版本**，为了节省空间，它通常将每个 `bool` 存储为**一个比特位**。
- 这导致它**不完全符合**标准容器的要求：
    - `operator[]` 返回的不是 `bool&`，而是一个代理类 (proxy class)，可以隐式转换为 `bool`。
    - 不能直接获取 `bool` 元素的地址 (`&v[i]` 非法)。
    - 迭代器不是标准的 `bool*` 类型。
- 如果你需要一个行为完全标准的 `bool` 容器，可以使用 `vector<char>` 或 `vector<int>` (存储 0/1)，或者 `deque<bool>`。

```cpp
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<bool> vb = {true, false, true};
    
    bool b = vb[0]; // OK, 通过代理类转换
    cout << "vb[0]: " << b << endl;

    // vb[1] = true; // OK, 通过代理类赋值

    // auto ref = vb[1]; // ref 是代理类类型，不是 bool&
    // bool* ptr = &vb[0]; // 编译错误！不能取地址

    // 如果需要标准行为
    vector<char> vc_bool = {1, 0, 1}; // 用 char 存储 0/1
    bool* ptr_c = reinterpret_cast<bool*>(&vc_bool[0]); // 不推荐，但技术上可行

    return 0;
}
```

### 3. 异常安全
- `vector` 的许多操作提供**强异常安全保证** (strong exception guarantee)，意味着如果操作因异常（如内存分配失败或元素构造/拷贝/移动抛出异常）而失败，`vector` 的状态会回滚到操作开始之前的状态，不会泄露资源，保持有效。例如 `push_back`。
- 有些操作提供**基本异常安全保证** (basic exception guarantee)，意味着如果发生异常，`vector` 自身状态可能改变（例如 `resize`），但仍处于有效状态，不会泄露资源。
- `noexcept` 标记的操作（如 `swap`, `clear`, `pop_back` (若元素析构不抛异常), 移动构造/赋值 (若元素移动不抛异常)）保证不抛出异常。

### 4. C++11 及以后的改进
- **移动语义**: 大幅提升了包含需要管理资源（如指针、文件句柄）的对象的 `vector` 操作性能（如重分配、`push_back`, `insert`）。
- **`emplace_back`, `emplace`**: 原地构造元素，减少拷贝/移动。
- **`shrink_to_fit`**: 标准化的内存回收请求。
- **初始化列表构造和赋值**: 更方便地创建和修改 `vector`。
- **常量迭代器 `cbegin`/`cend`**: 提高代码的 const 正确性。
- **`data()`**: 提供直接访问底层连续内存的指针。

## 七、总结与最佳实践

1.  **优先选择 `vector`**: 当你需要一个动态数组，且主要操作是末尾添加/删除和随机访问时，`vector` 通常是最佳选择。
2.  **预估大小并 `reserve`**: 如果能预知大致元素数量，使用 `reserve` 避免不必要的内存重分配，提升性能。
3.  **使用 `emplace_back` / `emplace`**: 对于非平凡类型，优先使用 `emplace` 系列函数以获得更好的性能。
4.  **警惕迭代器失效**: 在循环中修改 `vector` 或在操作后继续使用迭代器时要特别小心。
5.  **使用基于范围的 for 循环**: 使遍历代码更简洁、安全。
6.  **理解 `size` 和 `capacity`**: 有助于分析性能和内存使用。
7.  **善用 STL 算法**: 结合 `<algorithm>` 和 `<numeric>` 可以简洁高效地完成许多常见任务。
8.  **了解 `vector<bool>` 的特殊性**: 避免因此产生的陷阱。
9.  **考虑异常安全**: 了解不同操作的保证级别。
10. **利用 C++11 及后续版本的特性**: 移动语义、`emplace` 等能带来显著改进。
