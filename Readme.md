# Remember

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

## 运算符

### 位运算符

#### `&` 按位与

- 两个位都为1时，结果为1，否则为0

```cpp
1 & 1 = 1
1 & 0 = 0
0 & 1 = 0
0 & 0 = 0
1100 & 1011 = 1000
```

- 与运算通常用于掩码操作，例如屏蔽某些位

#### `|` 按位或

- 两个位都为0时，结果为0，否则为1

```cpp
1 | 1 = 1
1 | 0 = 1
0 | 1 = 1
0 | 0 = 0
1100 | 1011 = 1111
```

- 或运算通常用于设置某些位

#### `^` 按位异或

- 两个位相同为0，不同为1

```cpp
1 ^ 1 = 0
1 ^ 0 = 1
0 ^ 1 = 1
0 ^ 0 = 0
1100 ^ 1011 = 0111
```

- 异或运算通常用于交换两个变量的值

#### `~` 按位取反

- 0变1，1变0

```cpp
~1 = 0
~0 = 1
~1100 = 0011
```

- 取反运算通常用于反转二进制位

#### `<<` 左移

- 各二进位全部左移若干位，高位丢弃，低位补0

```cpp
1 << 1 = 2
1 << 2 = 4
1100 << 1 = 1000
```

- 左移运算通常用于乘法操作，例如 `2 << 1` 等价于 `2 * 2`

#### `>>` 右移

- 各二进位全部右移若干位，低位丢弃，高位补0

```cpp
1 >> 1 = 0
1 >> 2 = 0
1100 >> 1 = 0110
```

- 右移运算通常用于除法操作，例如 `4 >> 1` 等价于 `4 / 2`

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

#### 反转

- `reverse(nums.begin(), nums.end());`

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

### 链表

#### 链表的虚拟头节点

- `ListNode dummy(0, head);`
- 使用 `dummy` 节点来简化链表操作，避免对头节点进行特殊处理

#### 链表的遍历

- `while (p & p->next)`
  - 使用 `p` 指针遍历链表，`p` 初始化为 `dummy` 节点，`p->next` 为链表的实际头节点

#### 链表的交换

```cpp
// 保存节点
p1 = p->next; // p1是p的next
p2 = p1->next; // p2是p1的next
p3 = p2->next; // p3是p2的next

// dummy -> 1 -> 2 -> 3 -> 4
//   ↑      ↑    ↑    ↑
// dummy    p1   p2   p3

// 改变指向
p->next = p2; // p的next指向p2
p1->next = p3; // p1的next指向p3
p2->next = p1; // p2的next指向p1

// dummy -> 2 -> 1 -> 3 -> 4
//   ↑      ↑    ↑    ↑
// dummy    p2   p1   p3
```

#### 链表的删除

- `p->next = p->next->next;`

#### 链表的插入

- `p->next = new ListNode(val);`

#### 链表的遍历

- `while (p != NULL)`

### 栈

#### 模板

- STL 栈

```cpp
stack<int> stk;
stk.push(1); // 压入栈顶元素
stk.pop(); // 弹出栈顶元素
stk.top(); // 返回栈顶元素
stk.empty(); // 判断栈是否为空
stk.size(); // 返回栈的大小
```

- vector or string 栈

```cpp
vector<int> stk;
// string stk;
stk.push_back(1); // 压入栈顶元素   
stk.pop_back(); // 弹出栈顶元素
stk.back(); // 返回栈顶元素
stk.empty(); // 判断栈是否为空
stk.size(); // 返回栈的大小
```

#### 注意事项

1. 操作前必须判断栈是否为空

```cpp
if (!stk.empty()) {
    stk.pop();
}
```

2. 清空栈的两种方法

```cpp
while (!stk.empty()) {
    stk.pop();
}

// 或者
stk.clear();
```

3. 访问栈顶元素前检查

```cpp
if (!stk.empty()) {
    int top = stk.top();  // 安全的访问栈顶
}
```

4. 遍历

```cpp
while (!stk.empty()) {
    int top = stk.top();
    stk.pop();
}
```

### 二叉树

#### 二叉树节点的结构

```cpp  
struct TreeNode
{
    auto data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(auto x) : data(x), left(NULL), right(NULL) {}
};
```

#### 二叉树的创建

- 递归创建二叉树

```cpp
TreeNode* createTree() {
    auto val;
    cin >> val;
    
    // 基本情况:遇到'#'返回空节点 
    if (val == '#') {
        return NULL;
    }
    
    // 创建当前节点
    TreeNode* root = new TreeNode(val);
    
    // 递归创建左子树
    root->left = createTree();
    
    // 递归创建右子树
    root->right = createTree();
    
    return root;
}
```

- 非递归创建二叉树

```cpp
TreeNode* createTree() {
    int n;
    cin >> n;  // 输入节点个数
    if (n <= 0) return NULL;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];  // 输入n个数据
    }
    
    TreeNode* root = new TreeNode(nums[0]);  // 创建根节点
    for (int i = 1; i < n; i++) {
        insert(root, nums[i]);  // 依次插入其他节点
    }
    return root;
}

```

#### 二叉树的插入

- 按数字大小插入二叉树

```cpp
TreeNode *insert(TreeNode *root, int val) {
    if (!root)  // 如果当前位置为空,创建新节点
        return new TreeNode(val);
        
    if (val < root->data)  // 小于当前节点值,往左子树插入
        root->left = insert(root->left, val);
    else                   // 大于等于当前节点值,往右子树插入
        root->right = insert(root->right, val);
        
    return root;
}
```

#### 二叉树的查找

- 递归查找二叉树

```cpp
TreeNode* search(TreeNode* root, int val) {
    if (!root || root->data == val) return root;
    if (val < root->data) return search(root->left, val);
    return search(root->right, val);
}
```

- 非递归查找二叉树

```cpp
TreeNode* search(TreeNode* root, int val) {
    while (root && root->data != val) {
        root = val < root->data ? root->left : root->right;
    }
    return root;
}
```

#### 二叉树的删除

- 递归删除二叉树

```cpp
TreeNode* deleteNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    
    // 查找要删除的节点
    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data) 
        root->right = deleteNode(root->right, val);
    else {  // 找到要删除的节点
        // 情况1: 叶子节点
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        // 情况2: 只有一个子节点
        else if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // 情况3: 有两个子节点
        else {
            // 找到右子树的最小值节点
            TreeNode* temp = root->right;
            while (temp->left)
                temp = temp->left;
            // 用右子树最小值替换当前节点
            root->data = temp->data;
            // 删除右子树最小值节点
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

```

#### 二叉树的遍历

- 前序遍历

```cpp
void preOrder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
```

- 中序遍历

```cpp  
void inOrder(TreeNode* root)
{
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
```

- 后序遍历

```cpp
void postOrder(TreeNode* root)
{
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
```

## 算法

### 排序

#### 插入排序

- 模板

```cpp
void insertSort(vector<int>& data) {
    int n = data.size();
    for (int i = 1; i < n; i++) { // 从第二个元素开始插入
        int temp = data[i]; // 当前待插入元素
        int j = i - 1; // 从后往前遍历，找到插入位置
        while (j >= 0 && temp < data[j]) {
            data[j + 1] = data[j]; // 移动元素，腾出插入位置
            j--; // 继续向前遍历
        }
        data[j + 1] = temp; // 插入元素
    }
}
```

- 例题
  - [39-插入排序](./基础学习/39-广度优先遍历/01-插入排序.cpp)

#### 冒泡排序

- 模板

```cpp
void bubbleSort(vector<int>& data) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (data[j] > data[j + 1]) swap(data[j], data[j + 1]);
        }
    }
}
```

- 例题
  - [39-冒泡排序](./基础学习/39-广度优先遍历/03-冒泡排序.cpp)

#### 希尔排序

- 模板

```cpp
void shellSort(vector<int>& data) {
    int n = data.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = data[i];
            int j = i;
            while (j >= gap && temp < data[j - gap]) {
                data[j] = data[j - gap];
                j -= gap;
            }
            data[j] = temp;
        }
    }
}
```

- 例题
  - [39-希尔排序](./基础学习/39-广度优先遍历/04-希尔排序.cpp)

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
bool isPrime(int n) 
{
    if (n == 2) return true;
    if (n <= 1 || n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0) return false;
    }
    return true;
}
```

### 判断回文数

```cpp
// 判断一个数是否为回文数
bool isPalindrome(int n)
{
    string s = to_string(n);
    int len = s.length();
    for (int k = 0; k < len / 2; k++)
    {
        if (s[k] != s[len - 1 - k])
            return false;
    }
    return true;
}
```

### 各位数之和

```cpp
// 计算一个数的各位数之和
int sumOfDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
```

### 斐波那契数列

- 斐波那契数列的递推公式

```cpp
// 递归实现斐波那契数列
int fib(int n)
{
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2); 
}

// 迭代实现斐波那契数列
int fibIterative(int n) 
{
    if (n <= 1) return n;
    int prev = 0, curr = 1;
    for (int i = 2; i <= n; i++)
    {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

```

### 关键的数学公式

- 平方和公式

```cpp
1 * 1 + 2 * 2 + 3 * 3 + ... + n * n = n * (n + 1) * (2 * n + 1) / 6;
```

- 等差数列求和公式

```cpp
1 + 2 + 3 + ... + n = n * (n + 1) / 2;
```

- 等比数列求和公式

```cpp
sum = a * (1 - q ^ n) / (1 - q);
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

```cpp
// 将十进制数转换为其他进制的代码实现
string decimalToBase(int decimal, int base) {
    if (decimal == 0) return "0";
    
    string result = "";
    bool isNegative = decimal < 0;
    decimal = abs(decimal);
    
    while (decimal > 0) {
        int remainder = decimal % base;
        char digit;
        if (remainder < 10) {
            digit = remainder + '0';
        } else {
            digit = remainder - 10 + 'A';  // 10->A, 11->B, ...
        }
        result = digit + result;
        decimal /= base;
    }
    
    return isNegative ? "-" + result : result;
}

// 其他进制转换为十进制
int baseToDecimal(string number, int base) {
    int result = 0;
    bool isNegative = number[0] == '-';
    int start = isNegative ? 1 : 0;
    
    for(int i = start; i < number.length(); i++) {
        result *= base;
        if(number[i] >= '0' && number[i] <= '9') {
            result += number[i] - '0';
        } else {
            result += number[i] - 'A' + 10;  // A->10, B->11, ...
        }
    }
    
    return isNegative ? -result : result;
}

```

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

### 快速幂

- 用法
  - 快速幂可以用来计算一个数的幂，时间复杂度为O(log n)，比直接计算O(n)要快得多
  
- 要点
  - 快速幂的递归和迭代实现
  - 快速幂的取模实现

- 模板

```cpp
// 递归快速幂
long long qpow(long long a, long long n) {
    if (n == 0) return 1;
    long long ans = qpow(a, n / 2); // 递归计算a的n/2次幂
    ans *= ans;
    if (n & 1) ans *= a; // 如果n是奇数，ans乘以a
    return ans;
}

// 迭代快速幂
long long qpow(long long a, long long n) {
    long long ans = 1;
    while (n) {
        if (n & 1) ans *= a; // 如果n是奇数，ans乘以a
        a *= a;              // 平方
        n >>= 1;             // 右移一位，相当于除以2
    }
    return ans;
}

// 取模快速幂
long long qpow(long long a, long long n, long long mod) {
    long long ans = 1;
    while (n) {
        if (n & 1) ans = ans * a % mod; // 如果n是奇数，ans乘以a
        a = a * a % mod;                // 平方
        n >>= 1;                       // 右移一位，相当于除以2
    }
    return ans;
}

```

### 字母异位词

#### 字母异位词的判断

- 要点  
  - 使用 `vector<int> cnt(26)` 来存储每个字母出现的次数
  - 遍历字符串 `s` 和 `t`，将每个字母出现的次数存储在 `cnt` 中
  - 最后遍历 `cnt`，如果每个字母出现的次数都为0，则 `s` 和 `t` 是字母异位词

- 模板

```cpp
bool isAnagram(string s, string t) {
    if (t.size() != s.size()) return false;
    vector<int> cnt(26);
    for (auto c : s) cnt[c - 'a']++;
    for (auto c : t) cnt[c - 'a']--;
    for (int i = 0; i < 26; i++) if (cnt[i] != 0) return false;
    return true;
}
```

- 例题
  - [242-有效的字母异位词](./算法训练/LeetCode/All/242-有效的字母异位词.cpp)

#### 字母异位词的分组

- 要点
  - 使用 `unordered_map<string, vector<string>> mp` 来存储每个字母异位词
  - 遍历字符串数组 `strs`，将每个字符串排序后作为键值存储在 `mp` 中
  - 最后遍历 `mp`，将每个键值对的值存储在结果数组中

- 模板

```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string& str : strs) {
        string key = str;
        sort(key.begin(), key.end());
        mp[key].push_back(str);
    }
    vector<vector<string>> ans;
    for (auto& [_, group] : mp) ans.push_back(group);
    return ans;
}
```

- 例题
  - [49-字母异位词分组](./算法训练/LeetCode/All/49-字母异位词分组.cpp)

### 差分数组

- 要点
  - 差分数组是一种用于高效处理区间修改和查询的数据结构
  - 差分数组 `diff[i]` 表示原数组 `a[i]` 与 `a[i-1]` 的差值
  - 差分数组可以用于优化区间修改和查询，时间复杂度为O(1)

  - 差分数组与前缀和数组的关系
    - 对差分数组求前缀和可以得到原数组
    - 对原数组求差分可以得到差分数组

- 差分数组的模板

```cpp
// 差分数组的构造
vector<int> diff(n + 1);  // n为原数组长度
for (int i = 1; i <= n; i++) {
    diff[i] = a[i] - a[i-1];  // 构造差分数组
}

// 区间修改
void add(int l, int r, int val) {  // 将区间[l,r]整体加上val
    diff[l] += val;
    diff[r + 1] -= val;
}

// 还原原数组
vector<int> a(n + 1);
for (int i = 1; i <= n; i++) {
    a[i] = a[i-1] + diff[i];  // 前缀和运算还原原数组
}

```

- 应用场景
  - 区间修改
  - 区间查询
  

### 栈

#### 字符串处理

- 模板

```cpp
string removeDuplicates(string s) {
    string stk;
    for (char c : s) {
        if (!stk.empty() && stk.back() == c) {
            stk.pop_back();
        } else {
            stk.push_back(c);
        }
    }
    return stk;
}
```

- 例题
  - [1047-删除字符串中的所有相邻重复项](./算法训练/LeetCode/All/1047-删除字符串中的所有相邻重复项.cpp)

### 滑动窗口

#### 1. 定长滑动窗口

- 定长滑动窗口的模板

```cpp
for (int i = 0; i < n; i++) // n是数组长度, k是窗口长度
{
  // 将新元素加入窗口
  sum += nums[i];

  // 窗口未形成时继续
  if (i < k - 1)
    continue;

  // 更新结果
  ans = max(ans, sum / k);

  // 移出窗口最左边的元素
  sum -= nums[i - k + 1];
}
```

- 定长滑动窗口的题目
  - [643-子数组最大平均数I](./算法训练/LeetCode/灵茶山艾府/01-滑动窗口与双指针/01-定长滑动窗口/643-子数组最大平均数I.cpp)
  - [1052-爱生气的书店老板](./算法训练/LeetCode/灵茶山艾府/01-滑动窗口与双指针/01-定长滑动窗口/1052-爱生气的书店老板.cpp)

#### 2. 不定长滑动窗口

##### 2.1 求最长或最大

- 要点
  - 求最长或最大，一般使用 `unordered_map` 或 `unordered_set` 来存储窗口内元素
  - 使用 `left` 指针表示当前无重复子串的起始位置
  - 使用 `right` 指针遍历整个字符串
  - 如果当前字符已经在map中存在，且其索引大于等于left指针，说明在当前窗口中存在重复字符，将left指针移动到重复字符的下一个位置

- 模板

```cpp
int left = 0, right = 0;
int maxLen = 0;
unordered_map<char, int> window;

while (right < s.size()) {
    // 扩大窗口
    char c = s[right];
    right++;
    window[c]++;
    
    // 缩小窗口
    while (window[c] > 1) { // 根据题目要求调整条件
        char d = s[left];
        left++;
        window[d]--;
    }
    
    // 更新答案
    maxLen = max(maxLen, right - left);
}

```

- 题目
  - [3-无重复字符的最长子串](./算法训练/LeetCode/灵茶山艾府/01-滑动窗口与双指针/02-不定长滑动窗口/2.1-求最长或最大/03-无重复字符的最长子串.cpp)


### 单序列双指针

#### 1. 双向指针

- 要点
  - 双向指针一般用于处理数组或字符串中的问题
  - 通常使用两个指针 `left` 和 `right` 从序列的不同位置开始移动
  - 根据题目要求，可以从同一侧开始（快慢指针），也可以从两端开始（对撞指针）
  - 通过移动这两个指针来寻找满足条件的解

- 模板

```cpp
// 对撞指针基本模板
int twoPointers(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        // 根据条件移动指针
        if (condition1) {
            left++;
        } else if (condition2) {
            right--;
        } else {
            // 找到答案,更新结果
            updateResult();
            left++;
            right--;
        }
    }
    return result;
}
```

- 题目
  - [11-盛最多水的容器](./算法训练/LeetCode/灵茶山艾府/01-滑动窗口与双指针/03-单序列双指针/11-盛最多水的容器.cpp)

#### 2. 同向指针

- 要点
  - 同向指针一般用于处理数组或字符串中的问题
  - 通常使用一个指针 `left` 从序列的起点开始移动
  - 根据题目要求，通过移动指针来寻找满足条件的解

- 模板

```cpp
// 快慢指针基本模板 
int fastSlowPointers(vector<int>& nums) {
    int slow = 0, fast = 0;
    while (fast < nums.size()) {
        // 根据条件移动快指针
        if (condition) {
            // 移动慢指针并更新结果
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }
    return slow; // 通常返回慢指针位置
}
```

- 题目
  - [27-移除元素](./算法训练/LeetCode/灵茶山艾府/01-滑动窗口与双指针/03-单序列双指针/27-移除元素.cpp)


### 二分查找

- 二分查找的模板

```cpp
while (left < right) 
{
    int mid = (left + right + 1) / 2;
    if (check(mid)) left = mid; // 找最大的满足check的值
    else right = mid - 1;
}
```

