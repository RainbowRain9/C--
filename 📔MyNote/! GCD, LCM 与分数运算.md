# ! GCD, LCM 与分数运算

## 一、最大公约数 (GCD - Greatest Common Divisor)

### 1. 定义

最大公约数，也称为最大公因数，是指两个或多个整数共有约数中最大的一个正整数。例如，12 和 18 的公约数有 1, 2, 3, 6，其中最大的就是 6，所以 `gcd(12, 18) = 6`。

### 2. 重要性

*   **分数约分**: GCD 是将分数化为最简形式的关键。一个分数 `a/b` 的最简形式是通过将分子 `a` 和分母 `b` 同时除以它们的 `gcd(abs(a), abs(b))` 得到的。

### 3. 计算方法：欧几里得算法 (Euclidean Algorithm)

这是计算 GCD 最常用且高效的方法，也称为“辗转相除法”。其原理基于以下定理：
对于两个非负整数 `a` 和 `b`（假设 `a >= b`），`gcd(a, b) = gcd(b, a % b)`。其中 `a % b` 是 `a` 除以 `b` 的余数。算法持续这个过程，直到余数为 0，此时另一个数就是 GCD。

**递归实现:**

```cpp
long long gcd_recursive(long long a, long long b) {
    // 处理负数情况，通常我们对非负数求 GCD
    a = std::abs(a);
    b = std::abs(b);
    // 基本情况：如果 b 是 0，则 GCD 是 a
    if (b == 0) {
        return a;
    }
    // 递归步骤
    return gcd_recursive(b, a % b);
}
```

**迭代实现:**

```cpp
long long gcd_iterative(long long a, long long b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```

**C++ 标准库函数:**
在 C++17 及以后的版本中，可以使用 `<numeric>` 头文件中的 `std::gcd`。在之前的版本或使用 GNU 扩展时，可以使用 `<algorithm>` 头文件中的 `__gcd`。

```cpp
#include <numeric> // C++17 for std::gcd
#include <cmath>   // For std::abs

long long a = 12, b = 18;
long long common_divisor = std::gcd(a, b); // common_divisor 将会是 6
```

### 4. 复杂度

欧几里得算法的时间复杂度大约是 O(log(min(a, b)))，效率非常高。

## 二、最小公倍数 (LCM - Least Common Multiple)

### 1. 定义

最小公倍数是指两个或多个整数的公倍数中最小的一个正整数。例如，4 和 6 的公倍数有 12, 24, 36, ...，其中最小的是 12，所以 `lcm(4, 6) = 12`。

### 2. 重要性

*   **分数通分**: 在进行分数加减法时，需要找到所有分母的最小公倍数作为公共分母。

### 3. 计算方法：利用 GCD

计算 LCM 最常用的方法是利用 GCD，基于以下公式：
`lcm(a, b) = (|a * b|) / gcd(a, b)`

**注意溢出问题**: 当 `a` 和 `b` 都很大时，直接计算 `a * b` 可能会超出整数类型的表示范围（即使是 `long long`）。为了避免这种情况，可以先做除法：
`lcm(a, b) = (|a| / gcd(a, b)) * |b|`
或者
`lcm(a, b) = |a| * (|b| / gcd(a, b))`

**C++ 实现:**

```cpp
#include <numeric> // For std::gcd
#include <cmath>   // For std::abs

long long gcd(long long a, long long b) { // 使用上面定义的 gcd 函数或 std::gcd
    return std::gcd(std::abs(a), std::abs(b));
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0; // 处理 0 的情况
    long long abs_a = std::abs(a);
    long long abs_b = std::abs(b);
    long long common_divisor = gcd(abs_a, abs_b);
    // 优先做除法避免溢出
    return (abs_a / common_divisor) * abs_b;
}

int main() {
    long long a = 4, b = 6;
    long long common_multiple = lcm(a, b); // common_multiple 将会是 12
    return 0;
}
```

## 三、分数运算

### 1. 分数表示

通常，一个分数可以用两个整数表示：分子 (Numerator) 和分母 (Denominator)。为了方便处理，可以定义一个结构体或类：

```cpp
struct Fraction {
    long long x; // 分子
    long long y; // 分母

    // 构造函数，可以加入初始化和自动约分逻辑
    Fraction(long long num = 0, long long den = 1) {
        if (den == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        if (num == 0) {
            x = 0;
            y = 1; // 规范化 0 的表示
        } else {
            long long common = std::gcd(std::abs(num), std::abs(den));
            x = num / common;
            y = den / common;
            // 保证分母为正，符号放在分子上
            if (y < 0) {
                x = -x;
                y = -y;
            }
        }
    }
    // 可以添加其他成员函数，如打印、运算符重载等
};
```
**规范形式 (Canonical Form)** 很重要：
*   分母始终为正数。
*   分数总是保持最简形式 (分子分母互质)。
*   0 通常表示为 0/1。

### 2. 约分 (Simplification)

如上所述，约分通过分子分母同时除以它们的 GCD 来实现。

```cpp
void simplify(Fraction& f) {
    if (f.x == 0) {
        f.y = 1;
        return;
    }
    long long common = std::gcd(std::abs(f.x), std::abs(f.y));
    f.x /= common;
    f.y /= common;
    // 保证分母为正
    if (f.y < 0) {
        f.x = -f.x;
        f.y = -f.y;
    }
}
```
通常在构造函数和每次运算后调用 `simplify`。

### 3. 加法 / 减法 (Addition / Subtraction)

**步骤**:
1.  找到两个分数分母 `b` 和 `d` 的最小公倍数 `lcm_val = lcm(b, d)`。
2.  将两个分数通分，使其分母都变为 `lcm_val`:
    *   `a/b` 变为 `(a * (lcm_val / b)) / lcm_val`
    *   `c/d` 变为 `(c * (lcm_val / d)) / lcm_val`
3.  将通分后的分子相加或相减。
4.  得到结果分数 `((a * (lcm_val / b)) ± (c * (lcm_val / d))) / lcm_val`。
5.  对结果进行约分。

**示例 (加法):**

```cpp
Fraction add(const Fraction& f1, const Fraction& f2) {
    long long common_multiple = lcm(f1.y, f2.y);
    long long new_x = f1.x * (common_multiple / f1.y) + f2.x * (common_multiple / f2.y);
    long long new_y = common_multiple;
    // 返回新的 Fraction 对象，构造函数会自动约分和规范化
    return Fraction(new_x, new_y); 
}

// 类似地可以实现减法 subtract
```

### 4. 乘法 (Multiplication)

**步骤**:
1.  分子相乘，分母相乘：`(a/b) * (c/d) = (a * c) / (b * d)`。
2.  对结果进行约分。

**示例:**

```cpp
Fraction multiply(const Fraction& f1, const Fraction& f2) {
    long long new_x = f1.x * f2.x;
    long long new_y = f1.y * f2.y;
    // 返回新的 Fraction 对象，构造函数会自动约分和规范化
    return Fraction(new_x, new_y);
}
```
*   **优化**: 为了避免中间结果过大，可以在相乘 *之前* 进行交叉约分，例如约分 `gcd(f1.x, f2.y)` 和 `gcd(f2.x, f1.y)`，但这会使逻辑复杂化。通常直接相乘后约分更简单。

### 5. 除法 (Division)

**步骤**:
1.  除以一个分数等于乘以它的倒数：`(a/b) / (c/d) = (a/b) * (d/c)`。
2.  检查除数 `c/d` 的分子 `c` 是否为 0，如果是则为除零错误。
3.  执行乘法：`(a * d) / (b * c)`。
4.  对结果进行约分。

**示例:**

```cpp
Fraction divide(const Fraction& f1, const Fraction& f2) {
    if (f2.x == 0) { // 检查除数是否为 0
        throw std::runtime_error("Division by zero fraction.");
    }
    long long new_x = f1.x * f2.y; // 乘以倒数的分子
    long long new_y = f1.y * f2.x; // 乘以倒数的分母
    // 返回新的 Fraction 对象，构造函数会自动约分和规范化
    return Fraction(new_x, new_y);
}
```

## 四、与 "N个数求和" 问题的联系

在 L1-009 "N个数求和" 问题中：
*   我们维护一个累加和分数 `sum_x / sum_y`。
*   每次读入一个新的分数 `a / b`。
*   使用 **LCM** 找到 `sum_y` 和 `b` 的公共分母进行 **分数加法**。
*   每次加法运算后，使用 **GCD** 对结果 `sum_x / sum_y` 进行 **约分**，以保持其最简形式并防止数值溢出。
*   最后，根据结果分数 `sum_x / sum_y` 的特点（是否为0，分子是否小于分母）进行格式化输出，可能需要提取整数部分。

掌握了 GCD、LCM 和基本的分数四则运算，就能有效地解决这类有理数计算问题。
