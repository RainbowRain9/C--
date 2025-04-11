# iomanip 输入输出控制库详解

## 一、前置知识
- C++ 基础语法
- iostream 基本用法
- 流操作概念
- 格式化输出基础

## 二、库分析

### 1. 库介绍
- 头文件：`<iomanip>`
- 用途：提供格式化 I/O 操作
- 特点：使用流操纵算子(manipulator)

### 2. 主要功能
- 宽度控制
- 精度控制
- 对齐方式
- 填充字符
- 进制转换
- 数值格式化

### 3. 关键概念
- 流操纵算子
- 格式状态
- 格式标志
- 作用域规则

## 三、主要操作符

### 1. 数值格式控制
```cpp
setprecision(n)   // 设置精度
fixed             // 固定小数点
scientific        // 科学计数法
hexfloat          // 十六进制浮点
defaultfloat      // 默认浮点格式
```

### 2. 字段宽度和对齐
```cpp
setw(n)           // 设置字段宽度
setfill(c)        // 设置填充字符
left              // 左对齐
right             // 右对齐
internal          // 内部对齐
```

### 3. 基数和进制
```cpp
dec               // 十进制
hex               // 十六进制
oct               // 八进制
showbase          // 显示基数前缀
noshowbase        // 不显示基数前缀
```

## 四、代码实现

### 1. 基本用法
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pi = 3.14159265359;
    
    // 精度控制
    cout << setprecision(4) << pi << endl;        // 3.142
    cout << fixed << setprecision(2) << pi << endl; // 3.14
    
    // 宽度和对齐
    cout << setw(10) << pi << endl;              //      3.14
    cout << left << setw(10) << pi << endl;      // 3.14      
    
    // 填充字符
    cout << setfill('*') << setw(10) << pi << endl; // 3.14******
    
    return 0;
}
```

### 2. 高级格式化
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // 数值格式化
    double num = 123.456;
    cout << scientific << num << endl;    // 1.234560e+02
    cout << fixed << num << endl;         // 123.456000
    cout << hexfloat << num << endl;      // 0x1.edd2f2p+6
    
    // 进制转换
    int value = 255;
    cout << hex << showbase << value << endl;  // 0xff
    cout << oct << value << endl;              // 0377
    
    return 0;
}
```

## 五、常用组合

### 1. 表格输出
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // 表格头
    cout << left << setw(15) << "Name" 
         << right << setw(10) << "Score" << endl;
    
    // 分隔线
    cout << setfill('-') << setw(25) << "" << endl;
    
    // 数据行
    cout << setfill(' ')  // 恢复空格填充
         << left << setw(15) << "Alice"
         << right << setw(10) << fixed << setprecision(2) << 92.15 << endl;
    
    return 0;
}
```

### 2. 货币格式
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double price = 1234.56;
    
    // 货币格式
    cout << "$" << fixed << setprecision(2) 
         << setw(10) << right << price << endl;
    
    // 带千位分隔符
    cout.imbue(locale(""));
    cout << showbase << put_money(price*100) << endl;
    
    return 0;
}
```

## 六、特殊用法

### 1. 布尔值格式化
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    bool flag = true;
    
    cout << boolalpha << flag << endl;     // true
    cout << noboolalpha << flag << endl;   // 1
    
    return 0;
}
```

### 2. 指针格式化
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int* ptr = new int(42);
    
    cout << showbase << hex;              // 显示十六进制
    cout << setw(12) << ptr << endl;      // 显示指针地址
    
    delete ptr;
    return 0;
}
```

## 七、注意事项

### 1. 作用域
- setw 仅影响下一个输出
- setprecision 持续有效直到改变
- 格式标志持续有效直到改变

### 2. 常见错误
```cpp
// 错误：setw作用范围
cout << setw(5);      // 无效，因为没有立即输出
cout << "A" << "B";   // setw已失效

// 正确用法
cout << setw(5) << "A" << setw(5) << "B";
```

### 3. 性能考虑
- 频繁改变格式可能影响性能
- 合理使用格式缓存
- 避免不必要的格式转换

## 八、实战技巧

### 1. 格式状态保存
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios::fmtflags old_flags = cout.flags(); // 保存当前格式
    
    // 临时改变格式
    cout << hex << showbase << 42 << endl;
    
    cout.flags(old_flags);  // 恢复原格式
    return 0;
}
```

### 2. 自定义操纵算子
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

ostream& currency(ostream& os) {
    os << "$" << fixed << setprecision(2);
    return os;
}

int main() {
    cout << currency << 42.42 << endl;  // $42.42
    return 0;
}
```

## 九、扩展应用

### 1. 日期时间格式化
```cpp
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main() {
    time_t t = time(nullptr);
    cout << put_time(localtime(&t), "%Y-%m-%d %H:%M:%S") << endl;
    return 0;
}
```

### 2. 复数格式化
```cpp
#include <iostream>
#include <iomanip>
#include <complex>
using namespace std;

int main() {
    complex<double> z(3.0, 4.0);
    cout << fixed << setprecision(2) << z << endl;
    return 0;
}
```

## 十、最佳实践

### 1. 格式化建议
- 使用适当的精度
- 合理设置字段宽度
- 保持格式一致性
- 注意数据对齐

### 2. 代码风格
- 清晰的格式设置
- 适当的注释说明
- 格式状态管理
- 错误处理

### 3. 调试技巧
- 检查格式设置
- 验证输出效果
- 注意格式恢复
- 处理异常情况
