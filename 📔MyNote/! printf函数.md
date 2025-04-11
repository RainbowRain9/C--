# printf 函数详解

## 一、前置知识
- C/C++基础语法
- 输入输出流概念
- 格式化字符串
- 数据类型

## 二、函数分析

### 1. 函数原型
```cpp
int printf(const char* format, ...);
```

### 2. 功能说明
- 根据格式化字符串输出数据
- 支持多种数据类型的格式化
- 返回输出的字符数量

### 3. 关键概念
- 格式化字符串
- 可变参数列表
- 类型说明符
- 格式控制符

## 三、格式说明符

### 1. 基本格式
```
%[flags][width][.precision][length]specifier
```

### 2. 常用说明符
```cpp
%d    // 整数
%f    // 浮点数
%c    // 字符
%s    // 字符串
%x    // 十六进制
%o    // 八进制
%p    // 指针
%%    // 输出%符号
```

### 3. 标志位(flags)
```cpp
-     // 左对齐
+     // 显示正负号
空格   // 正数前加空格
#     // 特殊格式(0x等)
0     // 零填充
```

## 四、使用示例

### 1. 整数输出
```cpp
int num = 42;
printf("%d\n", num);     // 42
printf("%5d\n", num);    //    42
printf("%-5d\n", num);   // 42   
printf("%05d\n", num);   // 00042
```

### 2. 浮点数输出
```cpp
double pi = 3.14159;
printf("%f\n", pi);      // 3.141590
printf("%.2f\n", pi);    // 3.14
printf("%8.2f\n", pi);   //    3.14
printf("%-8.2f\n", pi);  // 3.14    
```

### 3. 字符串输出
```cpp
const char* str = "Hello";
printf("%s\n", str);     // Hello
printf("%10s\n", str);   //     Hello
printf("%-10s\n", str);  // Hello     
```

## 五、代码实现

### 1. 基本用法
```cpp
#include <cstdio>

int main() {
    // 整数输出
    int num = 42;
    printf("整数: %d\n", num);
    
    // 浮点数输出
    double val = 3.14159;
    printf("浮点数: %.2f\n", val);
    
    // 字符输出
    char ch = 'A';
    printf("字符: %c\n", ch);
    
    // 字符串输出
    const char* str = "Hello";
    printf("字符串: %s\n", str);
    
    return 0;
}
```

### 2. 格式化技巧
```cpp
#include <cstdio>

int main() {
    int num = 42;
    
    // 宽度控制
    printf("[%5d]\n");   // [   42]
    printf("[%-5d]\n");  // [42   ]
    
    // 精度控制
    double pi = 3.14159;
    printf("%.2f\n");    // 3.14
    
    // 组合使用
    printf("[%8.2f]\n", pi);  // [    3.14]
    
    return 0;
}
```

## 六、常见错误

### 1. 格式不匹配
```cpp
int num = 42;
printf("%f\n", num);    // 错误：整数用%f
printf("%d\n", num);    // 正确：整数用%d
```

### 2. 精度控制错误
```cpp
double pi = 3.14159;
printf("%.2\n", pi);    // 错误：缺少类型说明符
printf("%.2f\n", pi);   // 正确：指定浮点数精度
```

### 3. 参数数量不匹配
```cpp
int a = 1, b = 2;
printf("%d\n", a, b);    // 警告：多余的参数
printf("%d %d\n", a);    // 错误：参数不足
```

## 七、性能考虑

### 1. 优点
- 执行效率高
- 格式控制灵活
- 内存占用小

### 2. 缺点
- 类型不安全
- 错误检查少
- 不支持字符串对象

### 3. 使用建议
- C语言项目首选printf
- C++项目考虑cout
- 注意类型安全

## 八、相关函数

### 1. 输入函数
- scanf：格式化输入
- gets：字符串输入
- getchar：字符输入

### 2. 输出函数
- puts：字符串输出
- putchar：字符输出
- fprintf：文件输出

### 3. 字符串函数
- sprintf：格式化到字符串
- snprintf：安全格式化

## 九、实战技巧

### 1. 对齐输出
```cpp
// 表格对齐
printf("%-10s %5s %8s\n", "Name", "Age", "Score");
printf("%-10s %5d %8.2f\n", "Tom", 18, 92.5);
printf("%-10s %5d %8.2f\n", "Jerry", 19, 87.5);
```

### 2. 进制转换
```cpp
int num = 255;
printf("十进制：%d\n", num);    // 255
printf("十六进制：%x\n", num);  // ff
printf("八进制：%o\n", num);    // 377
```

### 3. 特殊格式
```cpp
// 金额格式
double money = 1234567.89;
printf("$%,.2f\n", money);  // $1,234,567.89

// 科学计数法
double sci = 0.000123;
printf("%e\n", sci);  // 1.230000e-04
```

## 十、总结建议

### 1. 使用原则
- 确保格式正确
- 注意类型匹配
- 考虑安全性

### 2. 调试技巧
- 检查返回值
- 验证输出结果
- 使用断点调试

### 3. 最佳实践
- 合理使用格式控制
- 注意代码可读性
- 保持一致的风格
