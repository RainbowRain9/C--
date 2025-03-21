# Lambda表达式详解

## 一、前置知识
- 函数指针基础
- 函数对象(functor)概念
- C++11及以上版本特性
- 闭包(closure)概念

## 二、基本概念

### 1. 定义
Lambda表达式是C++11引入的特性，允许定义一个匿名函数对象，可以捕获当前作用域中的变量。

### 2. 语法格式
```cpp
[capture](parameters) -> return_type { body }
```
各部分解释：
- `[capture]`: 捕获列表
- `(parameters)`: 参数列表(可选)
- `-> return_type`: 返回类型(可选)
- `{ body }`: 函数体

### 3. 基本示例
```cpp
auto lambda = []() { cout << "Hello Lambda!" << endl; };
lambda(); // 调用lambda函数
```

## 三、捕获列表详解

### 1. 捕获方式
```cpp
// 1. 空捕获列表
[]() { /* ... */ }

// 2. 值捕获
[x]() { return x + 1; }

// 3. 引用捕获
[&x]() { x += 1; }

// 4. 隐式值捕获所有变量
[=]() { /* ... */ }

// 5. 隐式引用捕获所有变量
[&]() { /* ... */ }

// 6. 混合捕获
[x, &y]() { /* ... */ }

// 7. 默认值捕获+引用捕获
[=, &x]() { /* ... */ }
```

### 2. 示例分析
```cpp
int main() {
    int x = 1, y = 2;
    
    // 值捕获示例
    auto val_capture = [x]() {
        // x不能被修改
        return x + 1;
    };
    
    // 引用捕获示例
    auto ref_capture = [&x]() {
        x += 1; // 可以修改x
        return x;
    };
    
    // 混合捕获示例
    auto mixed_capture = [x, &y]() {
        y += x; // 只能修改y
        return y;
    };
}
```

## 四、参数列表

### 1. 基本用法
```cpp
// 无参数
auto f1 = []() { return 42; };

// 单个参数
auto f2 = [](int x) { return x * 2; };

// 多个参数
auto f3 = [](int x, int y) { return x + y; };

// 使用auto参数(C++14)
auto f4 = [](auto x, auto y) { return x + y; };
```

### 2. 参数特性
```cpp
// 默认参数
auto f = [](int x = 10) { return x * 2; };

// 可变参数模板
auto f = [](auto... args) {
    return (... + args); // 折叠表达式(C++17)
};
```

## 五、返回类型

### 1. 自动推导
```cpp
// 编译器自动推导返回类型
auto f = [](int x) { return x * 2; };  // 返回int
```

### 2. 显式指定
```cpp
// 明确指定返回类型
auto f = [](int x) -> double { return x * 2.0; };
```

### 3. 特殊情况
```cpp
// 条件返回时需要显式指定
auto f = [](int x) -> double {
    if (x > 0)
        return x * 2.0;
    else
        return x / 2.0;
};
```

## 六、常见用法

### 1. 算法库中使用
```cpp
vector<int> nums = {1, 2, 3, 4, 5};

// 作为排序谓词
sort(nums.begin(), nums.end(), 
    [](int a, int b) { return a > b; });

// 作为查找条件
auto it = find_if(nums.begin(), nums.end(),
    [](int x) { return x > 3; });

// 作为转换规则
transform(nums.begin(), nums.end(), nums.begin(),
    [](int x) { return x * x; });
```

### 2. 回调函数
```cpp
class Button {
public:
    void setClickHandler(function<void()> handler) {
        onClick = handler;
    }
private:
    function<void()> onClick;
};

Button btn;
btn.setClickHandler([]() {
    cout << "Button clicked!" << endl;
});
```

### 3. 即时函数
```cpp
// 定义并立即调用
int result = [](int x) {
    int sum = 0;
    for(int i = 0; i <= x; ++i)
        sum += i;
    return sum;
}(10);
```

## 七、高级特性

### 1. mutable关键字
```cpp
int x = 10;
// 值捕获的变量默认是const的
auto f = [x]() mutable {
    x += 1; // 现在可以修改x了
    return x;
};
```

### 2. 泛型Lambda(C++14)
```cpp
// 使用auto参数实现泛型
auto generic = [](auto x, auto y) {
    return x + y;
};

// 可以用于不同类型
int n = generic(1, 2);      // int
double d = generic(1.5, 2.0); // double
string s = generic("Hello"s, " World"s); // string
```

### 3. constexpr Lambda(C++17)
```cpp
// 编译期计算
constexpr auto square = [](int x) constexpr {
    return x * x;
};

constexpr int result = square(12); // 编译期计算
```

## 八、性能考虑

### 1. 捕获优化
```cpp
// 避免不必要的捕获
vector<int> vec(1000);

// 不好的做法
[=]() { /* 捕获整个vector */ };

// 好的做法
[vec_size = vec.size()]() { /* 只捕获需要的值 */ };
```

### 2. 内联优化
```cpp
// 小的lambda通常会被内联
auto small = [](int x) { return x * 2; };

// 大的lambda可能不会被内联
auto big = [](int x) {
    // 大量代码...
};
```

## 九、常见错误

### 1. 捕获错误
```cpp
// 错误：没有捕获外部变量
int x = 10;
auto f = []() { return x; }; // 编译错误

// 正确：捕获外部变量
auto f = [x]() { return x; };
```

### 2. 生命周期问题
```cpp
function<int()> createLambda() {
    int x = 10;
    // 危险：返回捕获局部变量的lambda
    return [&x]() { return x; }; // x已经销毁
}
```

### 3. 类型转换问题
```cpp
// 错误：lambda无法直接转换为函数指针
int (*fp)(int) = [](int x) { return x * 2; }; // 可能编译错误

// 正确：使用+转换为函数指针
auto lambda = [](int x) { return x * 2; };
int (*fp)(int) = +lambda; // 正确
```

## 十、最佳实践

### 1. 代码风格
```cpp
// 保持lambda简短清晰
auto process = [](int x) {
    return x * 2;  // 简单的单一功能
};

// 复杂逻辑使用命名函数
int complexProcess(int x) {
    // 复杂的处理逻辑...
}
```

### 2. 使用建议
1. 优先使用命名函数表达复杂逻辑
2. Lambda适合简短的局部函数
3. 注意捕获列表的性能影响
4. 合理使用auto和类型推导
5. 考虑代码可维护性

### 3. 调试技巧
```cpp
// 添加调试信息
auto debugLambda = [](int x) {
    cout << "Processing: " << x << endl;
    auto result = x * 2;
    cout << "Result: " << result << endl;
    return result;
};
```

Lambda表达式是C++现代特性中非常重要的一部分，合理使用可以提高代码的简洁性和可读性。但也要注意避免过度使用，保持代码的可维护性。
