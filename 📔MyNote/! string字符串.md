# C++ `string` 详解

## 一、`string` 简介

*   **定义**：`string` 是 C++ 标准模板库（STL）中的一个类，它是类模板 `basic_string` 针对 `char` 类型（即最常用的字符类型）的一个特化版本。它被设计用来表示和操作字符序列。
*   **目的**：`string` 的出现主要是为了解决 C 语言风格字符串（以空字符 `\0` 结尾的 `char` 数组或 `char*` 指针）在实际使用中的诸多不便和风险，例如手动内存管理复杂、容易发生缓冲区溢出、缺乏便捷的操作函数等。
*   **头文件**：要使用 `string` 类，需要包含头文件 `<string>`。

```cpp
#include <string> // 引入 string 头文件
#include <iostream>

int main() {
    string greeting = "Hello, C++ String!";
    cout << greeting << endl;
    return 0;
}
```

## 二、`string` 的优势

相比于 C 风格字符串，`string` 提供了显著的优势：

1.  **动态内存管理**：`string` 对象会自动管理其所需的内存。当字符串长度改变时（例如，通过拼接、插入、删除等操作），它能自动分配或释放内存，开发者无需手动调用 `malloc`/`free` 或 `new`/`delete`。
2.  **安全性**：提供了带边界检查的访问方式（如 `at()` 方法），可以有效防止越界访问，减少程序崩溃和安全漏洞（如缓冲区溢出）的风险。
3.  **功能丰富**：内置了大量方便易用的成员函数，用于字符串的查找、替换、比较、拼接、截取子串等操作，大大简化了字符串处理的代码。
4.  **易用性**：可以直接使用 `+` 或 `+=` 进行字符串拼接，使用 `==`, `<`, `>` 等关系运算符进行比较，操作更直观、更符合面向对象的编程习惯。
5.  **与 STL 容器兼容**：`string` 的设计遵循了 STL 容器的接口规范，可以方便地与 STL 中的算法（如 `sort`, `find`）和其他容器（如 `vector`）协同工作。

## 三、创建与初始化 `string` 对象

创建 `string` 对象有多种方式：

1.  **默认构造**：创建一个空字符串。
    ```cpp
    string s1; // s1 是一个空字符串 ""
    ```
2.  **使用字符串字面量**：用 C 风格字符串初始化。
    ```cpp
    string s2 = "hello";   // 常用方式
    string s3("world");    // 构造函数方式
    ```
3.  **拷贝构造**：使用另一个 `string` 对象初始化。
    ```cpp
    string s4 = s2;     // s4 的内容是 "hello"
    string s5(s3);      // s5 的内容是 "world"
    ```
4.  **使用部分 C 风格字符串**：从 C 风格字符串的指定位置开始，拷贝指定数量的字符。
    ```cpp
    const char* c_str = "programming";
    string s6(c_str, 7); // s6 的内容是 "program" (从索引0开始的7个字符)
    ```
5.  **使用字符和数量**：创建包含指定数量相同字符的字符串。
    ```cpp
    string s7(5, '*'); // s7 的内容是 "*****"
    ```
6.  **使用迭代器范围**：使用来自其他容器（如 `vector<char>` 或另一个 `string`）的迭代器指定的范围来初始化。
    ```cpp
    vector<char> vec = {'a', 'b', 'c'};
    string s8(vec.begin(), vec.end()); // s8 的内容是 "abc"

    string s9(s2.begin() + 1, s2.end() - 1); // s9 的内容是 "ell" (s2是"hello")
    ```

## 四、常用成员函数与操作

`string` 提供了丰富的成员函数来操作字符串。

### 1. 访问与修改

*   `operator[]`：通过索引访问字符，**不进行边界检查**。越界访问是未定义行为。
    ```cpp
    string s = "test";
    char c = s[1]; // c 是 'e'
    s[0] = 'T';    // s 变成 "Test"
    // char invalid = s[10]; // 错误：越界，未定义行为
    ```
*   `at()`：通过索引访问字符，**进行边界检查**。如果索引越界，会抛出 `out_of_range` 异常。
    ```cpp
    string s = "safe";
    char c = s.at(1); // c 是 'a'
    s.at(0) = 'S';   // s 变成 "Safe"
    try {
        char invalid = s.at(10);
    } catch (const out_of_range& oor) {
        cerr << "Out of Range error: " << oor.what() << '\n';
    }
    ```
*   `front()`：返回对第一个字符的引用。对空字符串调用是未定义行为。
*   `back()`：返回对最后一个字符的引用。对空字符串调用是未定义行为。
    ```cpp
    string s = "abc";
    char first = s.front(); // first 是 'a'
    char last = s.back();   // last 是 'c'
    s.back() = 'd';         // s 变成 "abd"
    ```
*   `clear()`：清空字符串，使其变为空字符串 `""`。
    ```cpp
    string s = "clear me";
    s.clear(); // s 变成 ""
    ```
*   `empty()`：检查字符串是否为空，返回 `bool` 值。
    ```cpp
    string s1 = "";
    string s2 = "not empty";
    if (s1.empty()) { // true
        cout << "s1 is empty\n";
    }
    if (!s2.empty()) { // true
        cout << "s2 is not empty\n";
    }
    ```
*   `size()` / `length()`：返回字符串中的字符数（两者功能相同）。
    ```cpp
    string s = "hello";
    size_t len = s.size(); // len 是 5
    size_t len2 = s.length(); // len2 也是 5
    ```
*   `capacity()`：返回当前分配给字符串的存储空间大小（以字符数为单位），通常大于或等于 `size()`。
    ```cpp
    string s = "abc";
    cout << "Size: " << s.size() << ", Capacity: " << s.capacity() << endl;
    s += "defghijklmnop"; // 可能触发内存重分配
    cout << "Size: " << s.size() << ", Capacity: " << s.capacity() << endl;
    ```
*   `reserve(n)`：请求至少能容纳 `n` 个字符的存储空间。如果 `n` 大于当前 `capacity()`，可能会导致内存重分配。这用于优化，避免在后续添加字符时发生多次内存重分配。
    ```cpp
    string s;
    s.reserve(100); // 预分配至少100个字符的空间
    cout << "Capacity after reserve: " << s.capacity() << endl; // >= 100
    ```
*   `shrink_to_fit()` (C++11)：请求减少 `capacity()` 使其匹配 `size()`，释放未使用的内存。是否真正释放由具体实现决定。
    ```cpp
    string s = "short";
    s.reserve(100);
    cout << "Capacity before shrink: " << s.capacity() << endl; // >= 100
    s.shrink_to_fit();
    cout << "Capacity after shrink: " << s.capacity() << endl; // 接近或等于 s.size() (5)
    ```
*   `assign()`：多种重载形式，用于给字符串赋新值。
    ```cpp
    string s;
    s.assign("new value");
    s.assign(10, 'x'); // s 变成 "xxxxxxxxxx"
    string s2 = "another";
    s.assign(s2, 2, 3); // s 变成 "oth" (从s2索引2开始的3个字符)
    ```
*   `insert()`：在指定位置插入字符或字符串。
    ```cpp
    string s = "world";
    s.insert(0, "hello "); // s 变成 "hello world"
    s.insert(5, 1, ',');   // s 变成 "hello, world"
    ```
*   `erase()`：删除指定位置和数量的字符，或删除迭代器指定的范围。
    ```cpp
    string s = "hello, beautiful world";
    s.erase(5, 11); // s 变成 "hello world" (删除 ", beautiful")
    s.erase(s.begin() + 5); // s 变成 "helloworld" (删除空格)
    ```
*   `replace()`：用新内容替换字符串的一部分。
    ```cpp
    string s = "this is a test string";
    s.replace(10, 4, "sample"); // s 变成 "this is a sample string" (替换 "test")
    ```
*   `swap()`：交换两个 `string` 对象的内容。效率很高，通常是 O(1)。
    ```cpp
    string s1 = "first";
    string s2 = "second";
    s1.swap(s2); // s1 是 "second", s2 是 "first"
    swap(s1, s2); // 也可以使用全局 swap 函数
    ```

### 2. 拼接与连接

*   `operator+`：连接两个字符串或字符串与字符/C风格字符串，返回一个新的 `string` 对象。
    ```cpp
    string s1 = "hello";
    string s2 = " world";
    string s3 = s1 + s2; // s3 是 "hello world"
    string s4 = s1 + '!'; // s4 是 "hello!"
    string s5 = "prefix_" + s1; // s5 是 "prefix_hello"
    ```
*   `operator+=`：将另一个字符串、字符或 C 风格字符串追加到当前字符串末尾（原地修改）。通常比 `+` 更高效，因为它可能避免创建临时对象。
    ```cpp
    string s = "start";
    s += " end";    // s 变成 "start end"
    s += '!';       // s 变成 "start end!"
    ```
*   `append()`：功能类似 `+=`，提供更多重载形式，可以将另一个字符串的一部分或重复字符追加到末尾。
    ```cpp
    string s = "base";
    string s2 = "suffix";
    s.append(s2);      // s 变成 "basesuffix"
    s.append(s2, 0, 3); // s 变成 "basesuffixsuf" (追加s2的前3个字符)
    s.append(3, '.');  // s 变成 "basesuffixsuf..."
    ```

### 3. 查找

查找函数通常返回找到的第一个匹配项的起始索引（`size_t` 类型）。如果未找到，则返回一个特殊的静态成员值 `string::npos`。

*   `find(sub, pos=0)`：从位置 `pos` 开始，查找子串 `sub` 第一次出现的位置。`sub` 可以是 `string`、C 风格字符串或单个字符。
*   `rfind(sub, pos=npos)`：从位置 `pos` 向前（反向），查找子串 `sub` 最后一次出现的位置。
*   `find_first_of(chars, pos=0)`：从位置 `pos` 开始，查找 `chars` 中任意一个字符第一次出现的位置。`chars` 可以是 `string`、C 风格字符串或单个字符。
*   `find_last_of(chars, pos=npos)`：从位置 `pos` 向前，查找 `chars` 中任意一个字符最后一次出现的位置。
*   `find_first_not_of(chars, pos=0)`：从位置 `pos` 开始，查找第一个**不**属于 `chars` 中任意字符的字符的位置。
*   `find_last_not_of(chars, pos=npos)`：从位置 `pos` 向前，查找最后一个**不**属于 `chars` 中任意字符的字符的位置。

```cpp
#include <iostream>
#include <string>

int main() {
    string s = "The quick brown fox jumps over the lazy dog.";
    string sub = "fox";
    string vowels = "aeiou";

    size_t pos = s.find(sub);
    if (pos != string::npos) {
        cout << "'" << sub << "' found at index: " << pos << endl; // 输出 16
    }

    pos = s.find("the"); // 查找 "the"
    if (pos != string::npos) {
        cout << "'the' first found at index: " << pos << endl; // 输出 31
    }

    pos = s.rfind("the"); // 反向查找 "the"
    if (pos != string::npos) {
        cout << "'the' last found at index: " << pos << endl; // 输出 31 (这里只有一个 "the")
    }

    // 查找第一个元音字母
    pos = s.find_first_of(vowels);
     if (pos != string::npos) {
        cout << "First vowel '" << s[pos] << "' found at index: " << pos << endl; // 输出 'e' at 2
    }

     // 查找第一个非空格字符
    pos = s.find_first_not_of(' ');
     if (pos != string::npos) {
        cout << "First non-space character '" << s[pos] << "' found at index: " << pos << endl; // 输出 'T' at 0
    }

    return 0;
}
```

### 4. 比较

*   关系运算符 (`==`, `!=`, `<`, `>`, `<=`, `>=`)：按字典序比较字符串。
    ```cpp
    string s1 = "apple";
    string s2 = "apply";
    string s3 = "apple";

    if (s1 < s2) { // true
        cout << "s1 comes before s2 lexicographically.\n";
    }
    if (s1 == s3) { // true
        cout << "s1 and s3 are equal.\n";
    }
    ```
*   `compare()`：提供更灵活的比较方式，可以比较整个字符串或子串，返回值表示比较结果：
    *   `0`: 相等
    *   `< 0`: 调用者小于参数
    *   `> 0`: 调用者大于参数
    ```cpp
    string s1 = "abc";
    string s2 = "abd";
    int result = s1.compare(s2); // result < 0
    if (result < 0) {
         cout << "s1 < s2" << endl;
    }

    // 比较子串
    result = s1.compare(0, 2, s2, 0, 2); // 比较 "ab" 和 "ab", result == 0
    if (result == 0) {
        cout << "First two chars are equal" << endl;
    }
    ```

### 5. 子串

*   `substr(pos = 0, count = npos)`：返回一个新的 `string` 对象，包含从 `pos` 开始的 `count` 个字符。如果 `count` 超出范围或省略，则包含从 `pos` 到末尾的所有字符。如果 `pos` 越界，抛出 `out_of_range`。
    ```cpp
    string s = "programming";
    string sub1 = s.substr(0, 7); // sub1 是 "program"
    string sub2 = s.substr(7);    // sub2 是 "ming" (从索引7到末尾)
    ```

### 6. 输入/输出

*   `operator<<` (输出运算符)：将 `string` 内容输出到输出流（如 `cout`）。
    ```cpp
    string s = "Output me";
    cout << s << endl;
    ```
*   `operator>>` (输入运算符)：从输入流（如 `cin`）读取一个单词（以空白字符——空格、制表符、换行符等——分隔）到 `string`。读取前会跳过前导空白。
    ```cpp
    string word;
    cout << "Enter a word: ";
    cin >> word; // 如果输入 "hello world", word 只会得到 "hello"
    cout << "You entered: " << word << endl;
    ```
*   `getline(is, str, delim = '\n')`：从输入流 `is` 读取字符并存入 `str`，直到遇到分隔符 `delim`（默认为换行符 `\n`）或到达文件末尾。分隔符本身不会被存入 `str`，但会从流中移除。
    ```cpp
    string line;
    cout << "Enter a line: ";
    // 需要先清除之前 cin >> word 留下的换行符
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, line); // 读取整行，直到按下 Enter
    cout << "You entered: " << line << endl;

    string segment;
    string data = "field1,field2,field3";
    stringstream ss(data);
    while (getline(ss, segment, ',')) { // 使用逗号作为分隔符
        cout << "Segment: " << segment << endl;
    }
    ```

### 7. 与 C 风格字符串转换

*   `c_str()`：返回一个指向以空字符 `\0` 结尾的 `const char*` 数组的指针。这个指针指向的数据与 `string` 对象内部的数据相同。
    *   **重要**：返回的指针是临时的。任何可能修改 `string` 对象的操作（包括析构）都可能使该指针失效。不要长期持有或在 `string` 对象生命周期结束后使用它。
    *   主要用于需要 C 风格字符串作为参数的 C 库函数或旧 API。
    ```cpp
    string s = "hello";
    const char* c_style_string = s.c_str();
    printf("C-style string: %s\n", c_style_string); // 使用 C 库函数
    ```
*   `data()`：返回一个指向字符串内部字符数据的 `const char*` 指针。
    *   C++11 之前：不保证以空字符结尾。
    *   C++11 及之后：保证以空字符结尾，行为与 `c_str()` 类似。
    *   返回的指针同样是临时的，会因字符串修改而失效。
    ```cpp
    string s = "data";
    const char* char_data = s.data();
    // 可以访问数据，例如 char_data[0] 是 'd'
    ```

## 五、代码示例 (综合)

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <sstream> // for stringstream
#include <limits>  // for numeric_limits

int main() {
    // 1. 创建和初始化
    string str1 = "Welcome";
    string str2(" to C++");
    string str3(5, '!'); // !!!!!

    // 2. 拼接
    string message = str1 + str2 + str3; // "Welcome to C++!!!!!"
    message.append(" Have fun.");           // "Welcome to C++!!!!! Have fun."
    cout << "Initial message: " << message << endl;

    // 3. 访问和长度
    cout << "Length: " << message.size() << endl; // 29
    cout << "First char: " << message.front() << endl; // W
    cout << "Last char: " << message.back() << endl;   // .
    cout << "Char at index 8: " << message.at(8) << endl; // t

    // 4. 查找
    size_t pos = message.find("C++");
    if (pos != string::npos) {
        cout << "'C++' found at index: " << pos << endl; // 10
    } else {
        cout << "'C++' not found." << endl;
    }

    // 5. 替换
    message.replace(pos, 3, "Modern C++"); // 替换 "C++"
    cout << "After replace: " << message << endl; // "Welcome to Modern C++!!!!! Have fun."

    // 6. 子串
    string sub = message.substr(10, 10); // 从索引10开始取10个字符
    cout << "Substring: " << sub << endl; // "Modern C++"

    // 7. 插入
    message.insert(message.find("Have"), "Let's "); // 在 "Have" 前插入
    cout << "After insert: " << message << endl; // "Welcome to Modern C++!!!!! Let's Have fun."

    // 8. 删除
    message.erase(message.find("!!!!!"), 5); // 删除 "!!!!!"
    cout << "After erase: " << message << endl; // "Welcome to Modern C++ Let's Have fun."

    // 9. 比较
    string compare_str = "Welcome to Modern C++ Let's Have fun.";
    if (message == compare_str) {
        cout << "Strings are equal." << endl;
    }

    // 10. 输入一行
    string user_input;
    cout << "Enter your name: ";
    // cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除可能的残留换行符
    getline(cin, user_input);
    cout << "Hello, " << user_input << "!" << endl;

    // 11. 使用 c_str()
    printf("Using printf with c_str(): %s\n", message.c_str());

    // 12. 清空
    message.clear();
    cout << "Is message empty? " << (message.empty() ? "Yes" : "No") << endl; // Yes

    return 0;
}
```

## 六、复杂度分析 (常见操作)

`string` 的许多操作复杂度都与字符串的长度有关（设长度为 N，子串长度为 M 或 k）。

*   **访问** (`operator[]`, `at`, `front`, `back`)：O(1) - 常数时间。
*   **获取长度/容量** (`size`, `length`, `capacity`, `empty`)：O(1) - 常数时间。
*   **清空** (`clear`)：通常 O(1) 或 O(N)，取决于实现（是否释放内存）。
*   **修改大小** (`resize`, `reserve`)：可能 O(N)，如果发生内存重分配和内容拷贝。
*   **拼接** (`+`, `+=`, `append`)：通常与**结果**字符串的长度相关。`+=` 和 `append` 如果容量足够则可能接近 O(M)（M 为追加长度），否则可能为 O(N+M) 因需要重分配和拷贝。`+` 操作因为创建新字符串，至少是 O(N+M)。
*   **查找** (`find`, `rfind` 等)：朴素实现是 O(N*M)，但标准库通常使用更优化的算法（如 KMP、Boyer-Moore 的变种），平均情况下可能接近 O(N+M) 或 O(N)。
*   **子串** (`substr`)：O(k)，k 为子串长度，需要拷贝子串内容。
*   **插入/删除** (`insert`, `erase`)：O(N)，因为可能需要移动插入/删除点之后的所有字符。
*   **比较** (`==`, `<`, `compare`)：O(min(N, M))，M 为另一个字符串长度。最多比较到较短字符串的末尾或第一个不匹配的字符。
*   **替换** (`replace`)：复杂度取决于被替换和替换内容的长度，可能涉及 O(N) 的移动。
*   **交换** (`swap`)：O(1) - 常数时间，只交换内部指针和状态。

## 七、注意事项与常见陷阱

1.  **迭代器失效**：任何可能改变 `string` 长度或容量的操作（如 `insert`, `erase`, `append`, `+=`, `resize`, `reserve`, `assign`, `replace`, `clear` 等）都可能导致指向该字符串元素的**所有**迭代器、指针和引用失效。在循环中修改字符串时要特别小心。
    ```cpp
    string s = "abc";
    auto it = s.begin();
    s.insert(it + 1, 'x'); // 'it' 可能已经失效
    // ++it; // 错误：不能使用失效的迭代器
    ```
    安全做法通常是利用这些函数返回的新迭代器，或者重新获取迭代器。
2.  **`operator[]` vs `at()`**：`operator[]` 不进行边界检查，速度稍快，但如果索引越界，程序行为未定义（可能崩溃或产生错误结果）。`at()` 进行边界检查，越界时抛出异常，更安全，但有轻微性能开销。推荐在不确定索引是否有效时使用 `at()`，或在性能关键区且能确保索引有效时使用 `operator[]`。
3.  **`c_str()` / `data()` 返回指针的生命周期**：这两个函数返回的 `const char*` 指针仅在下一次调用非 `const` 成员函数或字符串对象被销毁之前有效。**绝不能**保存这个指针并在之后（尤其是在字符串可能被修改后）使用它。如果需要持久的 C 风格字符串，应拷贝其内容。
    ```cpp
    string s = "temp";
    const char* ptr = s.c_str();
    s += " change"; // 此时 ptr 可能已经失效！
    // printf("%s\n", ptr); // 危险！可能访问无效内存
    ```
4.  **频繁拼接的性能**：连续使用 `+` 运算符进行拼接（如 `s = s1 + s2 + s3 + ...;`）会产生大量临时 `string` 对象，效率较低。推荐使用 `+=` 或 `append`，或者先 `reserve()` 足够空间再拼接，以减少内存重分配次数。
    ```cpp
    // 低效
    string result = "";
    for (int i = 0; i < 1000; ++i) {
        result = result + to_string(i); // 产生大量临时对象
    }

    // 高效
    string result_opt;
    result_opt.reserve(4000); // 估算总长度并预留空间
    for (int i = 0; i < 1000; ++i) {
        result_opt += to_string(i); // 使用 +=
    }

    // 或使用 stringstream
    stringstream ss;
    for (int i = 0; i < 1000; ++i) {
        ss << i;
    }
    string result_ss = ss.str();
    ```
5.  **`string::npos`**：查找函数在失败时返回 `string::npos`。它是一个 `static const` 成员，类型是 `size_t`，通常被定义为该类型的最大值 (`-1` 的无符号表示)。判断查找是否成功时，应与 `string::npos` 比较，而不是 `-1` 或 `0`。
    ```cpp
    if (s.find("substring") == string::npos) {
        // 未找到
    } else {
        // 找到了
    }
    ```
6.  **空字符 `\0`**：`string` 可以包含空字符 `\0`，其 `size()` 会正确计算包含的 `\0`。但 C 风格字符串以第一个 `\0` 作为结束符。因此，当含有 `\0` 的 `string` 通过 `c_str()` 转换为 C 风格字符串时，使用 C 库函数（如 `strlen`, `printf %s`）处理该 C 风格字符串只会处理到第一个 `\0` 之前的部分。

## 八、`string` vs C 风格字符串 (`char*`)

| 特性         | `string`             | `char*` (C 风格字符串) |
|--------------|---------------------------|------------------------|
| **内存管理** | 自动 (RAII)              | 手动 (`malloc`/`free`, `new`/`delete`) |
| **大小**     | 动态，自动调整            | 固定大小数组或手动调整指针 |
| **安全性**   | 较高 (如 `at()`, 自动管理) | 较低 (易缓冲区溢出、内存泄漏) |
| **功能**     | 丰富内置成员函数          | 依赖 `<cstring>` 或 `<string.h>` 函数 |
| **易用性**   | 高 (运算符重载，接口直观) | 低 (指针操作，手动管理) |
| **空字符结尾**| 内部保证 (C++11 `data()`/`c_str()`) | 必须由程序员手动保证 |
| **包含 `\0`**| 可以包含任意数量的 `\0`   | 第一个 `\0` 被视作结束符 |
| **与 STL 集成**| 良好                      | 需要转换或包装         |

**总结**：在 C++ 中，除非有特定的性能要求或需要与 C API 交互，**强烈推荐使用 `string`** 而不是 C 风格字符串。

## 九、进阶话题与扩展

*   **`string_view` (C++17)**：一个轻量级的**只读**字符串视图。它本身不拥有字符串数据，而是持有指向字符序列（可以是 `string`、C 风格字符串或字符数组）的指针和长度。
    *   **优点**：创建和拷贝 `string_view` 非常快（O(1)），因为它不涉及内存分配或数据拷贝。在函数参数中使用 `string_view` 可以接受多种字符串类型，并避免不必要的 `string` 临时对象的创建。
    *   **缺点**：必须确保 `string_view` 指向的原始数据在 `string_view` 的生命周期内保持有效。
    ```cpp
    void printString(string_view sv) { // 接受多种字符串类型
        cout << sv << endl;
    }

    string s = "hello";
    const char* cstr = "world";
    printString(s);       // OK
    printString(cstr);    // OK
    printString("literal"); // OK
    ```
*   **SSO (Short/Small String Optimization)**：许多标准库实现对 `string` 进行了优化。对于足够短的字符串，其内容直接存储在 `string` 对象内部（通常是栈上），而不是在堆上分配内存。这可以显著提高短字符串操作的性能。SSO 是实现细节，具体阈值和行为因库而异。
*   **字符编码**：`string` 存储的是 `char` 序列，它本身并不关心这些 `char` 代表什么编码（ASCII, UTF-8, Latin-1 等）。当处理多字节编码（如 UTF-8）时，`size()` 返回的是字节数，而不是字符数（代码点数）。对 UTF-8 字符串进行基于字符的操作（如按“字符”截取、遍历“字符”）需要专门的库或手动处理编码。
*   **宽字符和 Unicode 字符串**：
    *   `wstring`: `basic_string<wchar_t>`，用于宽字符（如 Windows 上的 UTF-16）。
    *   `u8string` (C++20): `basic_string<char8_t>`，明确表示 UTF-8 编码。
    *   `u16string` (C++11): `basic_string<char16_t>`，用于 UTF-16 编码。
    *   `u32string` (C++11): `basic_string<char32_t>`，用于 UTF-32 编码。

## 十、总结

`string` 是 C++ 中处理文本数据的基石。它提供了安全、方便、功能强大的方式来操作字符串，避免了 C 风格字符串的许多陷阱。熟练掌握 `string` 的常用操作、性能特点和注意事项，对于编写现代、高效、可靠的 C++ 代码至关重要。在需要处理只读字符串或优化性能时，可以考虑使用 C++17 引入的 `string_view`。
