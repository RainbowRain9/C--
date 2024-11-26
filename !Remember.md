## 字符

```cpp
int a;    // 整数      4字节
char b;   // 字符  255 1字节
float c;  // 浮点数
double d; // 双
bool e;   // 布尔 2 1字节 true fasle
static_cast<int>(a) // 转换字符
numbers[5]; // 存储五个整数的数组
```

## 头文件

### `climits` 库

- `INT_MAX` 、 `INT_MIN` 、 `LLONG_MAX` 在 `#include <climits>` 头文件里，
- `int`最⼤大值为2147483647，共10位数字；
- `LLONG_MAX` 最⼤大值有19位数字，以9开头。
- 所以说储存13位的学号可以⽤用 `long long int` ，输出的时候使⽤用 `%013lld`。

### `string.h` 库

- 对字符数组排序时，比较函数 `cmp(char a[], char b[])` 需要使用 `strcmp(a, b) < 0`
- `strcmp` 函数在 `#include <string.h>` 头文件中，返回值规则:
  - 若 a < b，返回小于 0 的值
  - 若 a = b，返回 0
  - 若 a > b，返回大于 0 的值

### `cmath` 库

```cpp
#include <cmath> // 包含以使用abs函数
abs(number)      // 输出该数字的绝对值
bool isPrime(int j)
{
    // ... 函数实现 ...
}
```

### `cctype` 库

1. `isalnum` 是字母数字；
2. `isalpha` 是字母；
3. `isdigit` 是数字；
4. `isupper` 是大写字母；
5. `islower` 是小写字母；
6. `isblank` 是空格/tab键；
7. `isspace` 是空格/tab键/回车

### `cstdlib` 库

- `char c[10]` 类型转 `int` 、 `long` 、 `long long`
- 头文件 `#include <cstdlib>` ： `atoi` 、 `atol` 、 `atoll`

### `unordered_map` 和 `multimap 库`

- 头文件分别为 `#include <unordered_map>` 和 `#include <map>`
- `unordered_map` 是不排序的map，主要以key，下标法来访问
- 在内部 `unordered_map` 的元素不以键值或映射的元素作任何特定的顺序排序，其存储位置取决于哈希值
- 允许直接通过其键值为快速访问单个元素（所以也不不是你输入的顺序，别想太多…）
- `multimap` 是可重复的map，因为元素可重复，所以一般用迭代器遍历

### `algorithm` 库

- 在 `#include <algorithm>` 头文件里，有 `reverse` 函数， `reverse(s.begin(), s.end());` ， `reverse` 是直接改变字符串本身的，并没有返回值，不能 `reverse` 之后赋值给一个字符串，所以 `string t = reverse(s.begin(), s.end());` 这样是不对的～

## 语句

### 条件语句

```cpp
if (a > b)
{

} // 条件语句
```

### 循环语句

```cpp
for (i = 0; i < 10; i++)
{

} // 循环语句

while (i < n)
{ // 循环语句
    i++;
}

do
{

} while (i < n); // 循环语句
```

### 选择语句

```cpp
switch (expression)
{
case /* constant-expression */:
/* code */
break;

default:
break;
}
```

- `switch` 后面只能 `int` 或者 `char` 类型，其它类型不可以。用错了 `switch` 也会导致答案错误。

### 布尔语句

- `bool` 变量在 `main` 函数里记得要初始化， `bool flag[256] = {false};`
- 在 `main` 函数外（全局变量）会被自动初始化为 `false` 就可以不写～

### 三元运算符

```cpp
condition ? expression1 : expression2 // 三元运算符
// 如果 condition 为真（即非零），则表达式的值是 expression1 的值；
// 如果 condition 为假（即零），则表达式的值是 expression2 的值。
```

### 数组

#### 建立数组

- `vector<int> v[n]` - 建立一个存储 int 类型数组的数组，即n行的二维数组；也可以用 `vector<vector<int>> v` 建立二维数组

#### 排序

- 如果对数组进行 `sort` 排序： `sort(a, a + n, cmp1);`
- 如果对 `vector v` 或者字符串 `v` 进行 `sort` 排序： `sort(v.begin(), v.end(), cmp1);`
- 判断是否是不降序列： `is_sorted(begin(a), end(a));`
- 容器 `vector`、`set`、`map` 这些遍历的时候都是使用迭代器访问的，`c.begin()` 是一个指针，指向容器的第一个元素，`c.end()` **指向容器的最后一个元素的后一个位置**，所以迭代器指针 `it`的for循环判断条件是 `it != c.end()`，我再重复一遍～`c.end()` 指向容器的最后一个元素的后一个位置，这是一个重点和难点，我画个图加深一下大家的记忆。

### 字符串

#### 添加字符

- 在 `string s` 后⾯面加字符 `s += b;`
- 在 `string s` 前⾯面加字符 `s = a + s;` // a可以是 char 型也可以是 string 类型
- 如果是 `string s` ，则用 `getline(cin, s);` 在头文件 `#include <string>` 里面；
  - `getline(cin, s);` 前面如果有换行的输入，一定要在前面加上 `getchar();` (用来读取空格)，否则会直接只读入要读的字符串前面的 \n ～
- 如果是 `char str[100]` , 则用 `cin.getline(str, 100);` 在头文件 `#include <iostream>` 里面，也可以用 `gets(str);`

#### 移除字符串

- 移除字符串 `s`的第一个字符：`s.erase(s.begin())`
- 在字符串 `s`前面增加 `n`个 `0`：`s.insert(0, n, '0')`
- `string` 可以使用 `push_back('a');` 和 `pop_back();` 移除字符
  - `vector` 、 `string` 、 `deque` 是⽤用 `push_back` 添加元素

#### 计算字符串长度

- `char a[]` 的长度要用 `strlen(a)` 计算；得到的长度是里面真实存储了字母的长度，不包括 `\0`

#### `substr` 的用法

- `string s2 = s.substr(4);` // 表示从下标4开始一直到结束
- `string s3 = s.substr(5, 3);` // 表示从下标5开始，3个字符

#### 转换字符

- `string` 转其他类型

  - `string` 类型转 `int` 、 `long` 、 `long long` 、 `float` 、 `double` 、 `long double`
  - `stoi` 、 `stol` 、 `stoll` 、 `stof` 、 `stod` 、 `stold`
- 字符转 `string`

  - `to_string`

#### `string.find`

- `string.find` 返回的是下标的值，如果没有，⽤ == `string::npos` ，如果找到了了某个字符，就将这个字符的位置赋值给index，可以这样写代码：

  ```cpp
  if(s.find('a', 5) != string::npos)
      int index = s.find('a', 5);
  ```

  > 解释：
  >
  > - `int index = s.find('a');` //返回字符'a'第一次出现的下标（从0开始）
  > - `int index = s.find('a', 5);` //从下标5开始，寻找字符'a'第一次出现的下标
  >

## 算法

### 辗转相除法

- 计算最大公约数

```cpp
int GCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b; // 临时存储b的值
        b = a % b;    // 计算a除以b的余数，并赋值给b
        a = temp;     // 将b的原始值赋给a
    }
    return a; // 当b为0时，a即为最大公约数
}
```

- 计算最小公倍数

```cpp
int LCM(int a, int b)
{
    return (a * b) / GCD(a, b); // 使用最大公约数计算最小公倍数
}
```

### 判断素数

```cpp
// 判断n是否为素数
bool isprime(int n) 
{
    if (n <= 1) return false;
    int sqr = int(sqrt(n * 1.0));
    for (int i = 2; i <= sqr; i++)
    if (n % i == 0)
        return false;
return true;
}
```

### 进制转换

将十进制数转换为其他进制的方法:

1. 将十进制数 `a` 转换为 `b` 进制数的步骤:
   - 当 `a` 不等于 0 时:
     1. 计算 `a % b` 并从后往前保存
     2. 将 `a` 除以 `b`
   - 最后倒序排列所有余数,即为结果

> 示例:
> 将十进制数 13 转换为二进制:
>
> - 13 ÷ 2 = 6 余 1
> - 6 ÷ 2 = 3 余 0
> - 3 ÷ 2 = 1 余 1
> - 1 ÷ 2 = 0 余 1
> - 从下往上读余数: 1101

### 交换变量

在C++ 中，交换两个变量的值有多种方法。以下是一些常见的方法：

1. 使用临时变量：

```cpp
b = 10;
int temp = a; // 将a的值存储在temp中
a = b;        // 将b的值赋给a
b = temp;     // 将temp的值（原a的值）赋给b
```

2. 不使用临时变量（使用算术运算符）:

```cpp
int a = 5, b = 10;
a = a + b; // 将a和b的和赋给a
b = a - b; // 从a中减去b，得到原a的值，赋给b
a = a - b; // 从a中减去新的b（原a的值），得到原b的值，赋给a
```

- 这种方法需要确保 `a + b` 不会导致整数溢出。

3. 使用位运算符 XOR(异或运算):

```cpp
int a = 5,
b = 10;
a = a ^ b; // a和b进行异或运算，结果赋给a
b = a ^ b; // a和b的异或结果与b进行异或，得到原a的值，赋给b
a = a ^ b; // a和b的异或结果与新的b（原a的值）进行异或，得到原b的值，赋给a
```

- 这种方法不需要担心溢出问题，且效率较高。

4. 使用C++ 标准库中的swap函数 :

```cpp
#include <utility> // 引入头文件
int a = 5,
b = 10;
swap(a, b); // 交换a和b的值
f <= 1e-6 // f == 0;
```
