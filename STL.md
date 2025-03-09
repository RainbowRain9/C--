<!--
 * @Author: RainbowRain9
 * @Date: 2024-12-01 17:38:19
 * @LastEditTime: 2025-03-09 20:54:28
 * @FilePath: \C++\STL.md
 * @Description: 
-->
# STL

🌟STL 知识点总结
=============

✨0. 使用说明书
---------

首先先收藏这篇文章，`STL`确实有点多，第一次可以看代码自己敲一遍，然后今后用到忘记了查就行，主要还是要多用，用多了自然就会了，STL 中六大组件：容器、迭代器、算法、仿函数 、迭代适配器、空间配制器。本文章主要涉及前三个，另外会有一些使用小技巧，和实战习题。

> 小技巧：内容太多可以使用 Ctrl + F 直接搜索 加快查询速度`(4.6更新)`

✨1、vector 【不定长数组】
-----------------

> 你说它是数组吧，是，但又不完全是，还比数组好用

### ①头文件：

```cpp
#include<vector>
```

### ②初始化：

> 这个初始化比较详细，后面一些容器用法类似

```cpp
#include<iostream>
#include<vector>
using namespace std;
int main () 
{
	//几种初始化的方法
    vector<int> a;//定义一个vector  未初始化 输出》 0
    
    vector<int> a(3);//定义一个长度为3的vector  未初始化 输出》0 0 0
    
    vector<int> a(10, 3); //定义一个长度为10，且每个数赋值为3
    
	//将向量b中从下标0 1 2（共三个）的元素赋值给a，a的类型为int型
	//它的初始化不和数组一样 
	vector<int>a(b.begin(),b.begin+3);

	//从数组中获得初值
	int b[7]={1,2,3,4,5,6,7};
	vector<int> a(b,b+7）;
	
    for(auto x : a) {//遍历输出 
        cout << x << " ";
    }
    return 0;
}

```

![](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/a9bda9f925b74a65b3cc9236f94fdb6a~tplv-k3u1fbpfcp-zoom-in-crop-mark:1512:0:0:0.awebp)

### ③size()

```cpp
a.size( )//返回元素个数
```

### ④a.resize( )

```cpp
a.resize( )//改变大小
```

### ⑤empty()

```cpp
a.empty();
//判断a是否为空，空则返回true，非空则返回false
```

### ⑥front() 和 back()

```cpp
a.front();
//返回a的第1个元素,当且仅当a存在
a.back(); 
//返回vector的最后一个数
```

### ⑦倍增的思想

[C++] 系统为某一程序分配空间的所需时间，与空间大小无关，与申请次数有关如申请一个空间为 1000 和 空间为 1 申请 1000 次的所需时间差别是很大的，申请次数越多，越耗时间

### ⑧clear()

```cpp
a.clear();
//清空a中的元素
```

### ⑨支持比较运算

`比较操作==，！=，<，<，<=，>，>=`

```cpp
int main () {
    //支持比较运算
    vector<int> a(4, 3), b(3, 4);
    //a: 3 3 3 3   b:4 4 4 
    //比较原理字典序 (根据最前面那个判断，如果一样就往后比较)
    if (a < b) {
        puts("a < b"); 
    } 
    return 0;
}
```

### ⑩push_back() 和 pop_back();

```cpp
a.pop_back();
//删除a向量的最后一个元素
a.push_back(5);
//在a的最后一个向量后插入一个元素，其值为5
```

### ⑪begin() 和 end()

```cpp
a.begin();// vector的第0个数
a.end();// vector的最后一个的数的后面一个数
//通常与for循环结合使用
```

### ⑫遍历 vector 的三种方法

```cpp
int main () {
    vector<int> a;
    for (int i = 0; i < 10; i ++) {
        a.push_back(i);
    }
    //三种遍历vector的方法
    for (int i = 0; i < a.size(); i ++) {
        cout << a[i] << ' ';
    }
    cout << endl;

    for (auto i = a.begin(); i != a.end(); i ++) {
        cout << *i << ' ';
    }
    cout << endl;

    //C++11的新语法
    for (auto x : a) {
        cout << x << ' ';
    }
    cout << endl;  
    return 0;
}
```

![](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/29ed0c036d4148659a099993fdbf3801~tplv-k3u1fbpfcp-zoom-in-crop-mark:1512:0:0:0.awebp)

### ⑬结合算法 erase() reverse()

`#include<algorithm>`

```cpp
a.erase(p)//从a中删除迭代器p指定的元素，p必须指向c中的一个真实元素，不能是最后一个元素end()
a.erase(b,e)//从a中删除迭代器对b和e所表示的范围中的元素，返回e

vector<int> a={1,2,3,4,5};
reverse(a.begin(),a.end());//a的值为5，4，3，2，1  倒置
```

✨2、pair 【套娃模拟器】
---------------

> 可以理解为`（x,y）`数学中的坐标表示 小技巧：使用 typedef 定义 `typedef pair<int, int> PII`

### ①头文件

```cpp
#include<utility>
```

### ②初始化

使用：pair<first 数据类型, second 的数据类型> 元素名； pair 中只有两个元素，first 和 second。

```cpp
//俩种方法初始化
pair<string,int> p("hello",1);
p = make_pair("hello",1);
```

### ③first() 和 second()

```cpp
p("hello",1);
p.first; //第一个元素 =hello
p.second; //第二个元素 = 1
```

### ④嵌套（套娃）

```cpp
vector<vector<pair<int, int>>>//与vector结合【再写个vector结合即可】
```

```cpp
//套娃操作 用pair存储3个数据
 pair<int, pair<int, int>> p(1,{2,3});
```

### ⑤实战题

> 可以做下这道题[离散化 AcWing 802](https://link.juejin.cn?target=https%3A%2F%2Fblog.csdn.net%2Fweixin_49486457%2Farticle%2Fdetails%2F122770861%3Fspm%3D1001.2014.3001.5502 "https://blog.csdn.net/weixin_49486457/article/details/122770861?spm=1001.2014.3001.5502")

✨3、string
---------

> 支持比较操作符`>,>=,<,<=,==,!=`

### ①头文件

```cpp
#include <string>
```

### ②初始化

```cpp
string a = "ac";
```

### ③ substr()

```cpp
#include<iostream> 
#include<string>
using namespace std;

int main () {
    string a = "ac";
    a += "w";//支持比较操作符>,>=,<,<=,==,!=
    cout << a << endl; //输出子串a :acw

    a += "ing";  
    cout << a << endl;
    //以字符串数组理解
    cout << a.substr(0, 3) << endl; //当第一个数是0 则后一位数:输出从头开始的长度为3的子串
    cout << a.substr(0, 3) << endl; //当第一个数是1 则输出下标为1 到下标为3的子串  
    cout << a.substr(0, 9) << endl;//如果超出长度范围 则输出原子串
    cout << a.substr(1) << endl; //从下标为1开始输出
    cout << a.substr(0) << endl; //原子串
    printf("%s\n", a.c_str());//如果用printf输出  

    return 0;
}  
```

![](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/5fe8f65361704975aa0101a90e1fba17~tplv-k3u1fbpfcp-zoom-in-crop-mark:1512:0:0:0.awebp)

### ④ c_str()

```cpp
// 返回这个string对应的字符数组的头指针
string s = "Hello World!";
printf("%s", s.c_str()); //输出 "Hello World!"
```

### ⑤push_back() 和 insert()

```cpp
// 尾插一个字符
    a.push_back('a');
// insert(pos,char):在制定的位置pos前插入字符char
    a.insert(a.begin(),'1'); //输出 1a
  //插入字符串
  string str2="hello";
    string s2="weakhaha";
    str2.insert(0,s2,1,3);
//将字符串s2从下标为1的e开始数3个字符，分别是eak，插入原串的下标为0的字符h前    
```

![](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/45a03b8232c040b888955a5e184e026e~tplv-k3u1fbpfcp-zoom-in-crop-mark:1512:0:0:0.awebp)

### ⑥empty()

判断 a 是否为空，空则返回 true，非空则返回 false

### ⑦size() length()

都是 返回字母个数

```cpp
string s = "cpt";
cout << a.size()<< endl; //输出3
printf("%s", a.length()); //输出 3
```

### ⑧clear()

把字符串清空

> 可以发现 string 和 vector 这些还是有很多共同的函数的

✨4、queue【队列】 和 priority_queue 【优先队列、堆】
--------------------------------------

> **队列**是一种数据结构 **原理**：先进先出，元素从一端入队，从另一端出队，就像是排队。 **优先队列和队列特性不同**：按优先级排序 和 获取

### ①头文件

```cpp
#include <queue>//都在这个头文件
```

### ②初始化

```cpp
//queue <类型> 变量名  
//priority_queue <类型> 变量名;
queue <int> q; //定义一个名为q队列
priority_queue <int> q; //默认是大根堆
//定义小根堆
小根堆：priority_queue <类型,vecotr <类型>,greater <类型>> 变量名
```

![](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/5847a1cba7544281be4e5435f87beaa1~tplv-k3u1fbpfcp-zoom-in-crop-mark:1512:0:0:0.awebp) ![](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/28a6c8cec7d14125968f6558fa60956a~tplv-k3u1fbpfcp-zoom-in-crop-mark:1512:0:0:0.awebp)

### ③共同函数

```cpp
q.size();// 这个队列的长度
q.empty();//用于判断这个队列是否为空，空则返回true，非空则返回false
q.push(); //往队尾插入一个元素
q.pop(); //队列：把队头弹出  优先队列 ：弹出堆顶元素
```

### ④区别

队列：

```cpp
q.front();// 返回队头元素
q.back(); //返回队尾元素
```

优先队列：

```cpp
 q.top();// 返回堆顶元素
```

### ⑤清空

注意：队列和堆没有`clear`函数 所以清空的方法就是重新初始化

```cpp
q = queue <int> ();
```

✨5、stack 【栈】
------------

### ①头文件

```cpp
include<stack>
```

### ②初始化

```cpp
//stack<类型> 名字;
stack<int> s;
```

### ③size()

返回这个栈的长度

### ④push()

向栈顶插入一个元素

### ⑤top()

返回栈顶元素

### ⑥pop()

弹出栈顶元素

✨6、deque【双向队列】
--------------

> 好用，几乎其他容器的都有，就是慢一点

### ①头文件

```cpp
#include <deque>
```

### ②初始化

```cpp
deque<int> dq;//定义一个int类型的双向队列
```

### ③常用函数

```cpp
dq.size(); //返回这个双端队列的长度
dq.empty(); //返回这个队列是否为空，空则返回true，非空则返回false
dq.clear(); //清空这个双端队列
dq.front(); //返回第一个元素
dq.back(); //返回最后一个元素
dq.push_back(); //向最后插入一个元素
dq.pop_back(); //弹出最后一个元素
dq.push_front(); //向队首插入一个元素
dq.pop_front();//弹出第一个元素
dq.begin(); //双端队列的第0个数
dq.end(); //双端队列的最后一个的数的后面一个数
```

✨7、set 【集合】和 multiset
---------------------

> 集合与映射也是两个常用的容器,`set`类似于数学上的集合

### ①头文件

`include<set>`

### ②初始化

```cpp
set<string> s;//string 集合
```

### ③区别

`set`不允许元素重复，如果有重复就会被忽略，但`multiset`允许.

### ④常用函数

```cpp
size();// 返回元素个数
empty(); //返回set是否是空的
clear(); //清空
begin(); //第0个数，支持++或--，返回前驱和后继
end(); //最后一个的数的后面一个数，支持++或--，返回前驱和后继
insert(); //插入一个数
find(); //查找一个数
count(); //返回某一个数的个数
erase(x); //删除所以x  时间复杂度 O(k + logn)
erase(s.begin(),s.end());//删除一个迭代器
```

### ⑤核心函数

```cpp
lower_bound(x); //返回大于等于x的最小的数的迭代器  核心操作
upper_bound(x); //返回大于x的最小的数的迭代器  不存在返回end()
```

✨8、map 【映射】 /multimap
---------------------

> `map`就是从键（key）到值（value）的映射。因为重载了 [] 运算符，map 像是数组的“高 级版”。例如可以用一个`map<string，int>month_name`来表示 “月份名字到月份编号” 的映射， 然后用`month_name["July"]=7`这样的方式来赋值

### ①头文件

```cpp
include <map>
```

### ②初始化

> 这个初始化有点不同 还是小技巧搭配`typedef`简化

```cpp
map<string,int> m = { "A", 10 };
```

### ③常用函数

```cpp
insert(); //插入一个数，插入的数是一个pair
erase(); 
    //（1）输入是pair
    //（2）输入一个迭代器，删除这个迭代器
find(); //查找一个数
lower_bound(x); //返回大于等于x的最小的数的迭代器
upper_bound(x); //返回大于x的最小的数的迭代器
```

### ④ 映射 [ ]

`时间复杂度 O(logn)`

```cpp
#include <iostream>
#include <string>
#include<map>
using namespace std;
int main()
{
  	map<string,int>a;
  	a["abc"] = 1;   //把字符串"abc" 映射为1
  	cout << a["abc"] << endl; //查找abc  程序输出 1
    return 0;
}
```

### ⑤应用

```cpp
#include <iostream>
#include <string>
#include<map>
using namespace std;
typedef pair<string,int> PSI;
int main()
{
    map<string,int> mp;
    mp.insert(make_pair("heihei",5));
    mp.insert(PSI("haha",10));//简化
    map<string,int>::iterator it=mp.begin();//迭代器：map<int, char>::iterator it
    for(;it!=mp.end();it++)
       cout<<it->first<<"  "<<it->second<<endl;
    return 0;
}


```

[参考文章](https://link.juejin.cn?target=https%3A%2F%2Fblog.csdn.net%2Fm0_57026473%2Farticle%2Fdetails%2F119331711%3Fops_request_misc%3D%26request_id%3D%26biz_id%3D102%26utm_term%3Dmap%2520C%2B%2B%2520pair%26utm_medium%3Ddistribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-4-119331711.142%255Ev2%255Epc_search_result_control_group%2C143%255Ev4%255Econtrol%26spm%3D1018.2226.3001.4187 "https://blog.csdn.net/m0_57026473/article/details/119331711?ops_request_misc=&request_id=&biz_id=102&utm_term=map%20C++%20pair&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-4-119331711.142%5Ev2%5Epc_search_result_control_group,143%5Ev4%5Econtrol&spm=1018.2226.3001.4187")

✨9、哈希表
------

> 原谅我才刚学，可以先看看 [y 总的教程](https://link.juejin.cn?target=https%3A%2F%2Fwww.acwing.com%2Fblog%2Fcontent%2F9%2F "https://www.acwing.com/blog/content/9/"), 等我会了更新！！

### ①头文件

```cpp
unordered_set，unordered_map，unordered_muliset,unordered_multimap 
//头文件就是加上对应名称
```

### ②优势

和上面 map 和 set 类似，增删改查的时间复杂度是 O(1)

### ③缺点

> 不支持`lower_bound()`和`upper_bound()`

✨10、bitset 【压位】
---------------

> 它是一种类似数组的结构，它的每一个元素只能是`０`或`１`，每个元素仅用`１bit`空间, 用于节省空间， 并且可以直接用 01 串赋值，可以理解为一个二进制的数组

### ①头文件

`include<bitset>`

### ②初始化

```cpp
bitset<4> bs;　　//无参构造，长度为４，默认每一位为０

bitset<8> b(12);　　//长度为８，二进制保存，前面用０补充

string s = "100101"; //01串赋值
bitset<10> bs(s);　　//长度为10，前面用０补充
```

### ③支持操作

```cpp
~取反，&与，|与或，^异或
>>，<<  移动
==，!=
[]   取0/1
```

### ④常用函数

```cpp
count(); //返回1的个数
any(); //判断是否至少有一个1
none(); //判断是否全为0
set(); //把所有位置赋值为1
set(k,v); //将第k位变成v
reset(); //把所有位变成0
flip(); //把所有位取反，等价于~
flip(k); //把第k位取反
```

✨10、Algorithm
-------------

### 头文件

`#include<algorithm>`

> 以下为常用函数

### ①、sort();【具有和快排一样的速度】

`时间复杂度O (n*logn)`

```cpp
int a[5] = {4,2,1,3,5};
vector<int> b(a,a+5);
sort(a,a+5);//搭配数组  从小到大排序
sort(b.begin(),b.end());
```

**写一个 cmp 函数 实现从大到小排序**

```cpp
#include <bits/stdc++.h>
using namespace std;

int cmp(int a, int b)
{
    return a > b; 
    //蚂蚁感冒的正负数绝对值 return abs(a) < abs(b); 
}
int main () {
    int a[5] = {4,2,1,3,5};
    vector<int> b(a,a+5);
    sort(a,a+5);//搭配数组  从小到大排序
    sort(b.begin(),b.end());//搭配容器     //从小到大
    for (int i = 0; i < 5; i ++) {
        cout << a[i] << " ";
    }
    cout << endl;

    for (auto x:b) {
        cout << x << " " ;
    }

    cout << endl;
    sort(b.begin(),b.end(),cmp); //从大到小
    for (auto x:b) {
        cout << x << " ";
    }
    return 0;
}
```

### ②__gcd 最大公约数

[最大公约数小题](https://link.juejin.cn?target=https%3A%2F%2Fwww.acwing.com%2Fproblem%2Fcontent%2F3645%2F "https://www.acwing.com/problem/content/3645/")

```cpp
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int main()
{
    scanf("%d %d",&n,&m);
    int k=__gcd(n,m);//最大公约数
    printf("%d ",k);
    printf("%d", n * m / k); //最小公倍数
    return 0;
}
```

### ③max min

```cpp
max(a,b);//返回最大值
min(a,b);//返回最小值
```

### ④swap

```cpp
swap(a,b);//交换a和b
```

### ⑤lower_bound() 与 upper_bound() [二分查找]

时间复杂度 O(log n) `使用之前一定要先排序` ![](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/f09f2841dcdf45b595c0645db75a69fd~tplv-k3u1fbpfcp-zoom-in-crop-mark:1512:0:0:0.awebp)

### ⑥reverse 【倒置】

```cpp
ector<int> v={1,2,3,4,5};
reverse(v.begin(),v.end());//v的值为5，4，3，2，1  倒置
```

### ⑦find

```cpp
//在a中的从a.begin()（包括它）到a.end()（不包括它）的元素中查找10，
//若存在返回其在向量中的位置
find(a.begin(),a.end(),10);
```

### ⑧、erase【删除】

```cpp
//从c中删除迭代器p指定的元素，p必须指向c中的一个真实元素，不能等于c.end()
c.erase(p)
//从c中删除迭代器对b和e所表示的范围中的元素，返回e
c.erase(b,e)
```

✨11、语法小技巧
---------

### ①、连续读取

```cpp
while (cin >> a >> b) { ...}
```

### ①、加快 cin 和 cout 的速度

![](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/d2b5865e643d4966b6aeded5c0c38df1~tplv-k3u1fbpfcp-zoom-in-crop-mark:1512:0:0:0.awebp)

```cpp
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
```

### ③、万能头

> 缺点 耗时 `#include <bits/stdc++.h>`

### ④、#define

```cpp
#define INF  0x3f3f3f3f; //无穷大 10^9
#define x first ;//结合pair
#define y second;
```

### ⑤exit(0) [debug]

> 头文件`<cstring>` 相当于注释掉 Debug 技巧 ： 使用`exit(0)` 中断程序，如果没出现问题，则继续往下`exit(0)`, 直到发现问题，则 Debug 在附近

### ⑥无穷大

> `0x3f3f3f3f`的十进制为`1061109567`，和`INT_MAX`一个数量级，即 10^9^ 数量级，而一般场合下的数据都是小于 10^9^ 的。 `0x3f3f3f3f * 2 = 2122219134`，无穷大相加依然不会溢出。 可以使用`memset(array, 0x3f, sizeof(array))`来为数组设初值为`0x3f3f3f3f`，因为这个数的每个字节都是`0x3f`。

✨12、题目分析
--------

![](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/b033438d233a48e994efb1ffc2caa66e~tplv-k3u1fbpfcp-zoom-in-crop-mark:1512:0:0:0.awebp) **记住一些常见的数**

> **==2^0^~2^10^:0 1 2 4 8 16 32 64 128 256 522 1024==** **==2^20^ 约 10^6^ (1048576)==** **==2^16^ =65536==** **==2^15^ =32768==** **==2^63^ =10^8^==**
